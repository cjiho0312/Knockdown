#include "Enemy.h"

void Enemy::SetEnemyState() // ���� �� ���� �ð��� ������ IDLE ���·� ���ƿ��� ��
{
	if (ChangeState() && GetTickCount64() - StateTime >= 300) // ���� ���� ���� �����̰�, StateTime ���� 0.3�ʰ� �����°�?
	{
		ENEMY = IDLE; // �ٽ� IDLE ���·� ����
		changeState = false; // �ݺ� ���� �� �ǰԲ�
	}
}

void Enemy::FirstAttack() // ���� �ð� �� ���� ���� �����ϵ��� ����
{
	lastAttackTime = GetTickCount64(); 
	nextAttackDelay = (rand() % 2001) + 2000; 
}

void Enemy::PrepareAttack()
{
	if (!isPreparingAttack) // �ߺ� ������ ���� ���� ���ǹ�
	{
		enemyCanAttack = false;
		isPreparingAttack = true;
		attackStartTime = GetTickCount64(); // ���� �ð� ����

		ENEMY = R_ATTACK; // ���� �غ� ����
	}
}

void Enemy::TryAttack(Member& player) // ������ �޾ƿ��� ���� ����
{
	if (!isPreparingAttack) return;

	if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack�� true�̰�, 0.7�ʰ� �����°�?
	{
		if (player.IsDodgig()) // �÷��̾��� ȸ�� ����
		{
			if (player.DodgeCount() < 3) { player.IncreaseDodge(); } // dodgecount�� 3���� ���� ���� ȸ�� Ƚ�� ����


		}
		else
		{
			Attack(player); // ���� ���� ����
		}
		
		isPreparingAttack = false; // ���� �ʱ�ȭ
		lastAttackTime = GetTickCount64(); // ������ ���� �ð��� ���� �ð� ����
		nextAttackDelay = (rand() % 2001) + 1000; // 1 ~ 3�ʰ��� ���� �����̸� ��

		ENEMY = ATTACK; // ���� ����
		StateTime = GetTickCount64();
		changeState = true;
	}
}

void Enemy::Attack(Member& player)
{
	int dam = 0; // ������ ����

	int randValue = rand() % 100; // 0~99

	if (randValue < 40) // 40% Ȯ���� 1 ������
	{
		dam = 1;
	}
	else if (randValue < 80) // 40% Ȯ���� 2 ������
	{
		dam = 2;
	}
	else // 20% Ȯ���� 3 ������
	{
		dam = 3;
	}

	player.TakeDamage(dam, *this);
}

void Enemy::CheckECA()
{
	if (!isPreparingAttack && GetTickCount64() - lastAttackTime >= nextAttackDelay) // ���� �� �ƴ� ��, ���� ������ ���� ��
	{
		enemyCanAttack = true;
	}
}

void Enemy::TakeDamage(int dmg, const Member & Attacker)
{
		isPreparingAttack = false; // ���� �غ� ���� �� �������� �Ծ��� ��, ���� �غ� ���
		lastAttackTime = GetTickCount64() - 900; // �����ð� �� �ٽ� ���� �غ��ϵ��� ����
	
	repeatAttack = Attacker.RepeatAttack(); // player�� ���Ӱ���Ƚ�� �ҷ�����

	if (Attacker.IsAAttack()) // �������� �¾��� ��
	{	
		hp -= dmg;
		damage = dmg;

		ENEMY = GETDAMAGE; // �ǰ� ����
		StateTime = GetTickCount64();
		changeState = true;
		
		if (hp <= 0)
		{
			hp = 0;
			ENEMY = KO; // KO ����
			isAlive = false;
		}

	}
	else // �Ϲ� ������ ��
	{
		int dodgeChance = 30; // �⺻ ȸ�� Ȯ��

		if (repeatAttack == 2)
		{
			dodgeChance = 70; // ���� �ι�° ���� �� ȸ�� Ȯ��

		}
		else if (repeatAttack >= 3) // ���� ����° �̻� ���� �� ȸ�� Ȯ��
		{
			dodgeChance = 95;

		}

		int dodgePercent = rand() % 100;

		if (dodgePercent < dodgeChance) // ȸ�� Ȯ���� (100)���������� Ŭ ��� ȸ��
		{
			ENEMY = DODGE; // ȸ�� ����
			StateTime = GetTickCount64();
			changeState = true;
		}
		else if (dodgePercent >= dodgeChance) // ȸ�� Ȯ���� (100)���������� �۰ų� ���� ��� �ǰ�
		{
			hp -= dmg;
			damage = dmg;

			ENEMY = GETDAMAGE; // �ǰ� ����
			StateTime = GetTickCount64();
			changeState = true;
		
			if (hp <= 0)
			{
				hp = 0;

				ENEMY = KO; // ������ ����

				isAlive = false;
			}
		}
	}
}

