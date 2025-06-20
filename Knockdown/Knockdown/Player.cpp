#include "Player.h"


void Player::PrepareAttack()
{
    if (!isPreparingAttack && !isDodging) // 중복 실행을 막기 위한 조건문, 회피 중이지 않을 때 실행 가능
    {
        isPreparingAttack = true;
        attackStartTime = GetTickCount64(); // 현재 시간 저장
        cout << "플레이어가 팔을 들어 올렸습니다... (공격 준비 중)" << endl;
    }
}

void Player::TryAttack(Member& enemy)
{
    if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack이 true이고, 0.7초가 지났는가?
    { 
        cout << "→ 공격이 실행됩니다!\n";
        Attack(enemy); // 실제 공격 실행
        isPreparingAttack = false; // 상태 초기화
    }
}

void Player::CancelAttack()
{
    isPreparingAttack = false;
}

void Player::Dodge()
{
    if (!isDodging) // 중복 실행을 막기 위한 조건문
    {
        isDodging = true;
        dodgeStartTime = GetTickCount64();
	    cout << "회피 중..." << endl;
    }
}

void Player::EndDodge()
{
    if (isDodging && GetTickCount64() - dodgeStartTime >= 500) // isDodging이 true이고, 0.5초가 지났는가?
    {
        if (successDodge) // 회피 성공 판단 시
           {
           IncreaseDodge(); // 회피 카운트 +1
           cout << "회피 성공" << endl;
           successDodge = false;
           }
        
           cout << "회피 종료" << endl;
           isDodging = false;
    }
}

void Player::TakeDamage(int dmg)
{
    if (isPreparingAttack)
    {
        CancelAttack();
        cout << "공격 중 피격! 중단되었습니다." << endl;
    }
}



