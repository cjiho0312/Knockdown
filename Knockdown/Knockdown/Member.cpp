#include "Member.h"


void Member::PrepareAttack()
{
	if (!isPreparingAttack && !isDodging) // �ߺ� ������ ���� ���� ���ǹ�, ȸ�� ������ ���� �� ���� ����
	{
		isPreparingAttack = true;
		attackStartTime = GetTickCount64(); // ���� �ð� ����
		cout << "(���� �غ� ��)" << endl;
	}
}

void Member::TryAttack(Member& target)
{
	if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack�� true�̰�, 0.7�ʰ� �����°�?
	{
		cout << "(���� ����)" << endl;
		Attack(target); // ���� ���� ����
		isPreparingAttack = false; // ���� �ʱ�ȭ
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
	
	target.TakeDamage(3,*this); // 3 ������

	dodgeCount = 0; // ȸ�� ī��Ʈ �ʱ�ȭ

	isAAttack = false; // ������ ����
}
