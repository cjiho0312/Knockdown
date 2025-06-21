#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Member
{
protected:
	
	int hp; // ü��
	bool isAlive; // ����
	
	bool isPreparingAttack = false; // ���� �غ� �������� �˷���
	DWORD attackStartTime = 0; // ���� ���� �ð� ���

	bool isDodging = false; // ȸ�� ���� �������� �˷���
	bool isAAttack = false; // ������ �������� �˷���

	int repeatAttack = 0; // ���� ���� Ƚ��
	int dodgeCount = 0; // ȸ�� Ƚ��

public:

	Member() : hp(20), isAlive(true) {} // ��� �ʱ�ȭ ����Ʈ ���, HP�� 20, isAlive true�� �ʱ�ȭ.
	virtual ~Member() {} // �Ҹ���

	int GetHP() const { return hp; }
	bool IsAlive() const { return isAlive; }
	
	bool IsPreparingAttack() const { return isPreparingAttack; }

	bool IsDodgig() const { return isDodging; }
	bool IsAAttack() const { return isAAttack; }

	int RepeatAttack() const { return repeatAttack; }

	virtual void PrepareAttack(); // ���� ����
	virtual void TryAttack(Member& enemy); // 0.7�� �� ���� �õ�

	void CancelAttack(); // ȸ�� �� ���� �ߴ�

	virtual void Attack(Member& target); // ����
	virtual void TakeDamage(int dmg, const Member& Attacker); // ������ �ޱ�

	void AAttack(Member& target); // ������

	void ResetDodge() { dodgeCount = 0; } // ȸ�� Ƚ�� �ʱ�ȭ
	void IncreaseDodge() { dodgeCount++; } // ȸ�� Ƚ�� ����
	int DodgeCount() const { return dodgeCount; }

};

