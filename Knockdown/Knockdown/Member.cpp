#include "Member.h"


void Member::Attack(Member& target)
{
	int damage = 0; // ������ ����

	int randValue = rand() % 100; // 0~99

	if (randValue < 60) // 60% Ȯ���� 1 ������
	{
		damage = 1;
	}
	else if (randValue < 90) // 30% Ȯ���� 2 ������
	{
		damage = 2;
	}
	else // 10% Ȯ���� 3 ������
	{
		damage = 3;
	}

	cout << damage << "��ŭ �������� �������ϴ�." << endl;

	target.TakeDamage(damage);
}

void Member::TakeDamage(int dmg)
{
	HP -= dmg;

	if (HP <= 0)
	{
		HP = 0;
		cout << "�׾����ϴ�!" << endl;
		isAlive = false;
	}
}
