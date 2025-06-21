#include "Member.h"


void Member::PrepareAttack()
{
	if (!isPreparingAttack && !isDodging) // 중복 실행을 막기 위한 조건문, 회피 중이지 않을 때 실행 가능
	{
		isPreparingAttack = true;
		attackStartTime = GetTickCount64(); // 현재 시간 저장
		cout << "(공격 준비 중)" << endl;
	}
}

void Member::TryAttack(Member& target)
{
	if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack이 true이고, 0.7초가 지났는가?
	{
		cout << "(공격 실행)" << endl;
		Attack(target); // 실제 공격 실행
		isPreparingAttack = false; // 상태 초기화
	}
}

void Member::CancelAttack()
{
	isPreparingAttack = false;
}

void Member::Attack(Member& target)
{

}

void Member::TakeDamage(int dmg, const Member& Attacker)
{

}

void Member::AAttack(Member& target)
{
	isAAttack = true;
	
	target.TakeDamage(3,*this); // 3 데미지

	dodgeCount = 0; // 회피 카운트 초기화

	isAAttack = false; // 강공격 종료
}
