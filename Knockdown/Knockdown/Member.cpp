#include "Member.h"


void Member::PrepareAttack()
{
	if (!isPreparingAttack && !isDodging) // �ߺ� ������ ���� ���� ���ǹ�, ȸ�� ������ ���� �� ���� ����
	{
		isPreparingAttack = true;
		attackStartTime = GetTickCount64(); // ���� �ð� ����
		cout << "(���� �غ� ��)" << endl;
	
		STATE PLAYER = R_ATTACK; // ���� �غ� ����
	}

}

void Member::TryAttack(Member& target)
{
	if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack�� true�̰�, 0.7�ʰ� �����°�?
	{
		cout << "(���� ����)" << endl;
		Attack(target); // ���� ���� ����
		isPreparingAttack = false; // ���� �ʱ�ȭ

		STATE PLAYER = ATTACK; // ���� ����
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

	STATE PLAYER = A_ATTACK; // ������ ����

	isAAttack = false; // ������ ����
}
