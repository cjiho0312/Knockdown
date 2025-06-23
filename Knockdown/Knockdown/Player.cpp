#include "Player.h"


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

    isAAttack = false; // 강공격 종료
}

void Player::CheckRA()
{
    if (repeatAttack >= 2) // 연속 공격 상태일 때
    {
        if (GetTickCount64() - AttackTime >= 3000) // 공격을 안 한지 3초가 지났는가?
        {
            repeatAttack = 0; // 연속 공격 상태 해제
            cout << "연속 공격 상태 해제.." << endl;
        }
    }
}

void Player::Dodge()
{
    if (!isDodging) // 중복 실행을 막기 위한 조건문
    {
        isDodging = true;
        dodgeStartTime = GetTickCount64();

        PLAYER = DODGE; // 회피 동작
    }
}

void Player::EndDodge()
{
    if (isDodging && GetTickCount64() - dodgeStartTime >= 500) // isDodging이 true이고, 0.5초가 지났는가?
    {
        isDodging = false;

        PLAYER = IDLE; // 회피 종료 후 아이들 동작
    }
}

void Player::TakeDamage(int dmg, const Member& Attacker)
{
    if (isPreparingAttack)
    {
        CancelAttack();
        cout << "공격 중 피격! 중단되었습니다." << endl;

    }

    hp -= dmg;

    damage = dmg;

    PLAYER = GETDAMAGE; // 데미지 받는 동작

    if (hp <= 0)
    {
        hp = 0;
        cout << "죽었습니다!" << endl;

        STATE PLAYER = KO; // 쓰러짐 동작

        isAlive = false;
    }
}




