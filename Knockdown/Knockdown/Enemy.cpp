#include "Enemy.h"

void Enemy::PrepareAttack()
{
	if (!isPreparingAttack && !isDodging) // 중복 실행을 막기 위한 조건문, 회피 중이지 않을 때 실행 가능
	{
		enemyCanAttack = false;
		isPreparingAttack = true;
		attackStartTime = GetTickCount64(); // 현재 시간 저장
		cout << "                                        (공격 준비 중)" << endl;
	}
}

void Enemy::TryAttack(Member& player)
{
	if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack이 true이고, 0.7초가 지났는가?
	{
		cout << "                                        (공격 실행)" << endl;
		if (player.IsDodgig())
		{
			cout << "(회피 성공)" << endl;
			if(player.DodgeCount() < 3) { player.IncreaseDodge(); } // dodgecount가 3보다 작을 때만 회피 횟수 증가
		}
		else
		{
			Attack(player); // 실제 공격 실행
		}
		
		isPreparingAttack = false; // 상태 초기화
		lastAttackTime = GetTickCount64(); // 마지막 공격 시간에 현재 시간 저장
		nextAttackDelay = (rand() % 2001) + 2000; // 2 ~ 5초가량 공격 딜레이를 줌
	}
}

void Enemy::Attack(Member& player)
{
	int damage = 0; // 데미지 설정

	int randValue = rand() % 100; // 0~99

	if (randValue < 50) // 50% 확률로 1 데미지
	{
		damage = 1;
	}
	else if (randValue < 90) // 40% 확률로 2 데미지
	{
		damage = 2;
	}
	else // 10% 확률로 0 데미지
	{
		damage = 0;
	}

	cout << "                                        " << damage << "만큼 데미지를 입혔습니다." << endl;

	player.TakeDamage(damage, *this);
}

void Enemy::CheckECA()
{
	if (!isPreparingAttack && GetTickCount64() - lastAttackTime >= nextAttackDelay) // 공격 중 아닐 때, 공격 딜레이 끝난 후
	{
		enemyCanAttack = true;
	}
}

void Enemy::TakeDamage(int dmg, const Member & Attacker)
{
	if (isPreparingAttack) // 공격 준비 상태 중 데미지를 입었을 때
	{
		CancelAttack();
		lastAttackTime = GetTickCount64(); // lastAttackTime을 이용해 적정시간 후 다시 공격 준비하도록 설정
	}
	
	repeatAttack = Attacker.RepeatAttack();

	if (Attacker.IsAAttack()) // 강공격을 맞았을 때
	{	
		hp -= dmg;
		
		if (hp <= 0)
		{
			hp = 0;
			cout << "상대가 죽었습니다!" << endl;
			isAlive = false;
		}

	}
	else // 일반 공격일 때
	{
		int dodgeChance = 30; // 기본 회피 확률
		if (repeatAttack == 2)
		{
			dodgeChance = 70; // 연속 두번째 공격 시 회피 확률
			cout << "명중률이 낮아졌습니다!\n현재연속공격 : " << repeatAttack << endl;
		}
		else if (repeatAttack >= 3) // 연속 세번째 이상 공격 시 회피 확률
		{
			dodgeChance = 95;
			cout << "명중률이 더욱 낮아졌습니다!\n현재연속공격 : " << repeatAttack << endl;
		}

		int dodgePercent = rand() % 100;
		if (dodgePercent < dodgeChance) // 회피
		{
			cout << "\n적이 공격을 회피했습니다..." << endl;
		}
		else if (dodgePercent >= dodgeChance) // 데미지
		{
			hp -= dmg;
		
			if (hp <= 0)
			{
				hp = 0;
				cout << "상대가 죽었습니다!" << endl;
				isAlive = false;
			}
		}
	}
}

