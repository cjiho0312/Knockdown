#include "Enemy.h"

void Enemy::SetEnemyState() // 동작 후 일정 시간이 지나면 IDLE 상태로 돌아오게 함
{
	if (ChangeState() && GetTickCount64() - StateTime >= 300) // 상태 수정 가능 상태이고, StateTime 이후 0.3초가 지났는가?
	{
		ENEMY = IDLE; // 다시 IDLE 상태로 변경
		changeState = false; // 반복 실행 안 되게끔
	}
}

void Enemy::FirstAttack() // 일정 시간 후 적이 공격 가능하도록 설정
{
	lastAttackTime = GetTickCount64(); 
	nextAttackDelay = (rand() % 2001) + 2000; 
}

void Enemy::PrepareAttack()
{
	if (!isPreparingAttack) // 중복 실행을 막기 위한 조건문
	{
		enemyCanAttack = false;
		isPreparingAttack = true;
		attackStartTime = GetTickCount64(); // 현재 시간 저장

		ENEMY = R_ATTACK; // 공격 준비 동작
	}
}

void Enemy::TryAttack(Member& player) // 원본값 받아오기 위해 참조
{
	if (!isPreparingAttack) return;

	if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack이 true이고, 0.7초가 지났는가?
	{
		if (player.IsDodgig()) // 플레이어의 회피 성공
		{
			if (player.DodgeCount() < 3) { player.IncreaseDodge(); } // dodgecount가 3보다 작을 때만 회피 횟수 증가


		}
		else
		{
			Attack(player); // 실제 공격 실행
		}
		
		isPreparingAttack = false; // 상태 초기화
		lastAttackTime = GetTickCount64(); // 마지막 공격 시간에 현재 시간 저장
		nextAttackDelay = (rand() % 2001) + 1000; // 1 ~ 3초가량 공격 딜레이를 줌

		ENEMY = ATTACK; // 공격 동작
		StateTime = GetTickCount64();
		changeState = true;
	}
}

void Enemy::Attack(Member& player)
{
	int dam = 0; // 데미지 설정

	int randValue = rand() % 100; // 0~99

	if (randValue < 40) // 40% 확률로 1 데미지
	{
		dam = 1;
	}
	else if (randValue < 80) // 40% 확률로 2 데미지
	{
		dam = 2;
	}
	else // 20% 확률로 3 데미지
	{
		dam = 3;
	}

	player.TakeDamage(dam, *this);
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
		isPreparingAttack = false; // 공격 준비 상태 중 데미지를 입었을 때, 공격 준비 취소
		lastAttackTime = GetTickCount64() - 900; // 적정시간 후 다시 공격 준비하도록 설정
	
	repeatAttack = Attacker.RepeatAttack(); // player의 연속공격횟수 불러오기

	if (Attacker.IsAAttack()) // 강공격을 맞았을 때
	{	
		hp -= dmg;
		damage = dmg;

		ENEMY = GETDAMAGE; // 피격 동작
		StateTime = GetTickCount64();
		changeState = true;
		
		if (hp <= 0)
		{
			hp = 0;
			ENEMY = KO; // KO 동작
			isAlive = false;
		}

	}
	else // 일반 공격일 때
	{
		int dodgeChance = 30; // 기본 회피 확률

		if (repeatAttack == 2)
		{
			dodgeChance = 70; // 연속 두번째 공격 시 회피 확률

		}
		else if (repeatAttack >= 3) // 연속 세번째 이상 공격 시 회피 확률
		{
			dodgeChance = 95;

		}

		int dodgePercent = rand() % 100;

		if (dodgePercent < dodgeChance) // 회피 확률이 (100)랜덤값보다 클 경우 회피
		{
			ENEMY = DODGE; // 회피 동작
			StateTime = GetTickCount64();
			changeState = true;
		}
		else if (dodgePercent >= dodgeChance) // 회피 확률이 (100)랜덤값보다 작거나 같을 경우 피격
		{
			hp -= dmg;
			damage = dmg;

			ENEMY = GETDAMAGE; // 피격 동작
			StateTime = GetTickCount64();
			changeState = true;
		
			if (hp <= 0)
			{
				hp = 0;

				ENEMY = KO; // 쓰러짐 동작

				isAlive = false;
			}
		}
	}
}

