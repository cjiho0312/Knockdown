#include "Enemy.h"

void Enemy::PrepareAttack()
{
	if (!isPreparingAttack && !isDodging) // �ߺ� ������ ���� ���� ���ǹ�, ȸ�� ������ ���� �� ���� ����
	{
		enemyCanAttack = false;
		isPreparingAttack = true;
		attackStartTime = GetTickCount64(); // ���� �ð� ����
		cout << "                                        (���� �غ� ��)" << endl;
	}
}

void Enemy::TryAttack(Member& player)
{
	if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack�� true�̰�, 0.7�ʰ� �����°�?
	{
		cout << "                                        (���� ����)" << endl;
		if (player.IsDodgig())
		{
			cout << "(ȸ�� ����)" << endl;
			if(player.DodgeCount() < 3) { player.IncreaseDodge(); } // dodgecount�� 3���� ���� ���� ȸ�� Ƚ�� ����
		}
		else
		{
			Attack(player); // ���� ���� ����
		}
		
		isPreparingAttack = false; // ���� �ʱ�ȭ
		lastAttackTime = GetTickCount64(); // ������ ���� �ð��� ���� �ð� ����
		nextAttackDelay = (rand() % 2001) + 2000; // 2 ~ 5�ʰ��� ���� �����̸� ��
	}
}

void Enemy::Attack(Member& player)
{
	int damage = 0; // ������ ����

	int randValue = rand() % 100; // 0~99

	if (randValue < 50) // 50% Ȯ���� 1 ������
	{
		damage = 1;
	}
	else if (randValue < 90) // 40% Ȯ���� 2 ������
	{
		damage = 2;
	}
	else // 10% Ȯ���� 0 ������
	{
		damage = 0;
	}

	cout << "                                        " << damage << "��ŭ �������� �������ϴ�." << endl;

	player.TakeDamage(damage, *this);
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
		CancelAttack();
		lastAttackTime = GetTickCount64(); // lastAttackTime�� �̿��� �����ð� �� �ٽ� ���� �غ��ϵ��� ����
	}
	
	repeatAttack = Attacker.RepeatAttack();

	if (Attacker.IsAAttack()) // �������� �¾��� ��
	{	
		hp -= dmg;
		
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
		if (dodgePercent < dodgeChance) // ȸ��
		{
			cout << "\n���� ������ ȸ���߽��ϴ�..." << endl;
		}
		else if (dodgePercent >= dodgeChance) // ������
		{
			hp -= dmg;
		
			if (hp <= 0)
			{
				hp = 0;
				cout << "��밡 �׾����ϴ�!" << endl;
				isAlive = false;
			}
		}
	}
}

