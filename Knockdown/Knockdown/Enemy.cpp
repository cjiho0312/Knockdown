#include "Enemy.h"

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

void Enemy::TryAttack(Member& player)
{
	if (!isPreparingAttack) return;

	if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack�� true�̰�, 0.7�ʰ� �����°�?
	{
		if (player.IsDodgig())
		{
			if(player.DodgeCount() < 3) { player.IncreaseDodge(); } // dodgecount�� 3���� ���� ���� ȸ�� Ƚ�� ����
		}
		else
		{
			Attack(player); // ���� ���� ����
		}
		
		isPreparingAttack = false; // ���� �ʱ�ȭ
		lastAttackTime = GetTickCount64(); // ������ ���� �ð��� ���� �ð� ����
		nextAttackDelay = (rand() % 2001) + 2000; // 2 ~ 5�ʰ��� ���� �����̸� ��

		ENEMY = ATTACK; // ���� ����
	}
}

void Enemy::Attack(Member& player)
{
	int dam = 0; // ������ ����

	int randValue = rand() % 100; // 0~99

	if (randValue < 50) // 50% Ȯ���� 1 ������
	{
		dam = 1;
	}
	else if (randValue < 90) // 40% Ȯ���� 2 ������
	{
		dam = 2;
	}
	else // 10% Ȯ���� 0 ������
	{
		dam = 0;
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
	if (isPreparingAttack) // ���� �غ� ���� �� �������� �Ծ��� ��
	{
		isPreparingAttack = false;
		lastAttackTime = GetTickCount64(); // lastAttackTime�� �̿��� �����ð� �� �ٽ� ���� �غ��ϵ��� ����
	}
	
	repeatAttack = Attacker.RepeatAttack();

	if (Attacker.IsAAttack()) // �������� �¾��� ��
	{	
		hp -= dmg;
		damage = dmg;

		ENEMY = GETDAMAGE; // �ǰ� ����
		
		if (hp <= 0)
		{
			hp = 0;
			cout << "��밡 �׾����ϴ�!" << endl;
			isAlive = false;
		}

	}
	else // �Ϲ� ������ ��
	{
		int dodgeChance = 30; // �⺻ ȸ�� Ȯ��
		if (repeatAttack == 2)
		{
			dodgeChance = 70; // ���� �ι�° ���� �� ȸ�� Ȯ��
			cout << "���߷��� ���������ϴ�!\n���翬�Ӱ��� : " << repeatAttack << endl;
		}
		else if (repeatAttack >= 3) // ���� ����° �̻� ���� �� ȸ�� Ȯ��
		{
			dodgeChance = 95;
			cout << "���߷��� ���� ���������ϴ�!\n���翬�Ӱ��� : " << repeatAttack << endl;
		}

		int dodgePercent = rand() % 100;

		if (dodgePercent < dodgeChance) // ȸ�� Ȯ���� (100)���������� Ŭ ��� ȸ��
		{
			ENEMY = DODGE; // ȸ�� ����
		}
		else if (dodgePercent >= dodgeChance) // ȸ�� Ȯ���� (100)���������� �۰ų� ���� ��� �ǰ�
		{
			hp -= dmg;
			damage = dmg;

			ENEMY = GETDAMAGE; // �ǰ� ����
		
			if (hp <= 0)
			{
				hp = 0;
				cout << "��밡 �׾����ϴ�!" << endl;

				ENEMY = KO; // ������ ����

				isAlive = false;
			}
		}
	}
}

