#include "Player.h"


void Player::Attack(Member& enemy)
{
    int damage = 0; // 데미지 설정

    int randValue = rand() % 100; // 0~99

    if (randValue < 60) // 60% 확률로 1 데미지
    {
        damage = 1;
    }
    else if (randValue < 90) // 30% 확률로 2 데미지
    {
        damage = 2;
    }
    else // 10% 확률로 0 데미지
    {
        damage = 0;
    }

    cout << damage << "만큼 데미지를 입혔습니다." << endl;

    enemy.TakeDamage(damage, *this);

    repeatAttack += 1; // 공격 카운트 업
    AttackTime = GetTickCount64();
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
	    cout << "(회피 중)" << endl;
    }
}

void Player::EndDodge()
{
    if (isDodging && GetTickCount64() - dodgeStartTime >= 500) // isDodging이 true이고, 0.5초가 지났는가?
    {
        cout << "(회피 종료)" << endl;
        isDodging = false;
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

    if (hp <= 0)
    {
        hp = 0;
        cout << "죽었습니다!" << endl;
        isAlive = false;
    }
}



