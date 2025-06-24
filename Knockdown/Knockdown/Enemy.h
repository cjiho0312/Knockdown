#pragma once
#include "Member.h"
class Enemy : public Member
{
private:
	DWORD lastAttackTime = 0; // ������ ���� �ð�
	DWORD nextAttackDelay = 0; // ���� ���� �ð�
	DWORD attackStartTime = 0; // ���� ���� �ð�
	DWORD StateTime = 0; // ���� ���� �ð� ���

	bool isPreparingAttack = false; // ������ �غ�Ǿ��°�?
	bool enemyCanAttack = false; // ���� �����Ѱ�?
	bool changeState = true; // SetEnemyState�� �����Ѱ�?

	STATE ENEMY; // �� ���� ����

public:
	STATE GetEnemyState() const { return ENEMY; } // Enemy�� ���� ��ȯ
	void SetEnemyState(); // ����� ���� ���� �ð� �׷��� �Լ�

	void FirstAttack(); // ù ���� ����
	
	void PrepareAttack() override; // �� ���� �غ�
	void TryAttack(Member& player) override; // �� ���� �õ�
	void Attack(Member& player) override; // ����

	void CheckECA(); // enemyCanAttack ���� Ȯ�� �� ����

	bool EnemyCanAttack() const { return enemyCanAttack; }
	bool ChangeState() const { return changeState; }

	void TakeDamage(int dmg, const Member & Attacker) override;
};

