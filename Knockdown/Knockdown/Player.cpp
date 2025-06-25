#include "Player.h"


void Player::SetPlayerState() // 동작 후 일정 시간이 지나면 IDLE 상태로 돌아오게 함 (회피 제외)
{
    if (GetPlayerState() != 6 && ChangeState() && GetTickCount64() - StateTime >= 300) // 피곤 상태 아니고, 상태 수정 가능 상태이고, StateTime 이후 0.3초가 지났는가?
    {
        PLAYER = IDLE; // 다시 IDLE 상태로 변경
        changeState = false; // 반복 실행 안 되게끔
    }
}

void Player::PrepareAttack()
{
    if (!isPreparingAttack && !isDodging) // 중복 실행을 막기 위한 조건문, 회피 중이지 않을 때 실행 가능
    {
        isPreparingAttack = true;
        attackStartTime = GetTickCount64(); // 현재 시간 저장

        PLAYER = R_ATTACK; // 공격 준비 동작
    }
}

void Player::TryAttack(Member& enemy)
{
    if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack이 true이고, 0.7초가 지났는가?
    {
        Attack(enemy); // 실제 공격 실행
        isPreparingAttack = false; // 상태 초기화

        PLAYER = ATTACK; // 공격 동작
        StateTime = GetTickCount64(); // 동작 시전 시간 저장
        changeState = true;
    }
}

void Player::Attack(Member& enemy)
{
    int dam = 0; // 데미지 설정

    int randValue = rand() % 100; // 0~99

    if (randValue < 60) // 60% 확률로 1 데미지
    {
        dam = 1;
    }
    else if (randValue < 90) // 30% 확률로 2 데미지
    {
        dam = 2;
    }
    else // 10% 확률로 0 데미지
    {
        dam = 0;
    }

    enemy.TakeDamage(dam, *this);

    repeatAttack += 1; // 공격 카운트 업

    AttackTime = GetTickCount64();
}

void Player::AAttack(Member& target)
{
    isAAttack = true;

    target.TakeDamage(3, *this); // 3 데미지

    dodgeCount = 0; // 회피 카운트 초기화

    PLAYER = A_ATTACK; // 강공격 동작

    StateTime = GetTickCount64(); // 동작 시전 시간 저장
    changeState = true;

    isAAttack = false; // 강공격 종료
}

void Player::CheckRA()
{
    if (repeatAttack >= 1) // 연속 공격 상태일 때
    {
        if (GetTickCount64() - AttackTime >= 2000) // 공격을 안 한지 2초가 지났는가?
        {
            repeatAttack = 0; // 연속 공격 상태 해제
        }
    }

    if (repeatAttack >= 4) // 4회 이상 연속 공격 상태일 때
    {
        Tired();
    }

}

void Player::CheckRD()
{
    if (repeatDodge >= 1) // 연속 회피 상태일 때
    {
        if (GetTickCount64() - DodgeTime >= 1000) // 회피를 안 한지 1초가 지났는가?
        {
            repeatDodge = 0; // 연속 회피 상태 해제
        }
    }

}

void Player::Dodge()
{
    if (!isDodging) // 중복 실행을 막기 위한 조건문
    {
        isDodging = true;
        dodgeStartTime = GetTickCount64(); // 회피 시작 시간 기록

        PLAYER = DODGE; // 회피 동작
    }
}

void Player::EndDodge()
{
    if (isDodging && GetTickCount64() - dodgeStartTime >= 400) // isDodging이 true이고, 0.4초가 지났는가?
    {
        isDodging = false;
        repeatDodge += 1; // 회피반복 카운트 증가
        DodgeTime = GetTickCount64();


        if (repeatDodge < 3)
        {
            PLAYER = IDLE; // 회피 종료 후 아이들 동작
        }
        if (repeatDodge >= 3)
        {
            Tired();
        }
    }
}

void Player::Tired()
{
    PLAYER = TIRED; // 지침 동작
    TiredTime = GetTickCount64(); // 동작 시전 시간 저장
    dodgeCount = 0; // 회피 카운트 초기화

    isDodging = false; // 회피 중이던 거 취소
    isPreparingAttack = false; // 공격 중이던 거 취소

    repeatDodge = 0; // 연속회피 카운트 초기화
    repeatAttack = 0; // 연속공격 카운트 초기화

    soTired = true;
}

void Player::EndTired()
{
    if (soTired == true && GetTickCount64() - TiredTime >= 3000) // 3초 후 지침상태 끝
    {
        PLAYER = IDLE; // 대기 상태로 변경
        soTired = false; // 중복 방어
    }
}

void Player::TakeDamage(int dmg, const Member& Attacker)
{
    if (isPreparingAttack)
    {
        CancelAttack();
    }

    hp -= dmg;

    damage = dmg;

    PLAYER = GETDAMAGE; // 데미지 받는 동작

    StateTime = GetTickCount64(); // 동작 시전 시간 저장
    changeState = true;

    if (hp <= 0)
    {
        hp = 0;

        PLAYER = KO; // 쓰러짐 동작

        isAlive = false;
    }
}




