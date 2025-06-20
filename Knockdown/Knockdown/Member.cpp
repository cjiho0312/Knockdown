#include "Member.h"


void Member::Attack(Member& target)
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
	else // 10% 확률로 3 데미지
	{
		damage = 3;
	}

	cout << damage << "만큼 데미지를 입혔습니다." << endl;

	target.TakeDamage(damage);
}

void Member::TakeDamage(int dmg)
{
	HP -= dmg;

	if (HP <= 0)
	{
		HP = 0;
		cout << "죽었습니다!" << endl;
		isAlive = false;
	}
}
