#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Member
{
protected:
	
	int hp; // ü��
	bool isAlive; // ����
	int damage; // ������ 
	
	bool isPreparingAttack = false; // ���� �غ� �������� �˷���
	DWORD attackStartTime = 0; // ���� ���� �ð� ���

	bool isDodging = false; // ȸ�� ���� �������� �˷���
	bool isAAttack = false; // ������ �������� �˷���

	int repeatAttack = 0; // ���� ���� Ƚ��
	int repeatDodge = 0; // ���� ȸ�� Ƚ��
	int dodgeCount = 0; // ȸ�� ���� Ƚ��


	typedef enum _STATE // ���� ��¿�
	{
		IDLE, // �⺻ ��� ����, 0
		R_ATTACK, // ���� �غ� ���� ����, 1
		ATTACK, // ���� ����, 2
		GETDAMAGE, // �ǰ� ����, 3
		DODGE, // ȸ�� ����, 4
		A_ATTACK, // ������ ����, 5
		TIRED, // ��ħ ����, 6
		KO // ������ ����, 7
	} STATE;

public:

	Member() : hp(20), isAlive(true), damage(0){} // ��� �ʱ�ȭ ����Ʈ ���, HP�� 20, isAlive true�� �ʱ�ȭ.
	virtual ~Member() {} // �Ҹ���

	int GetHP() const { return hp; }
	bool IsAlive() const { return isAlive; }
	int Damage() const { return damage; }
	
	bool IsPreparingAttack() const { return isPreparingAttack; }

	bool IsDodgig() const { return isDodging; }
	bool IsAAttack() const { return isAAttack; }

	int RepeatAttack() const { return repeatAttack; }

	virtual void PrepareAttack(); // ���� ����
	virtual void TryAttack(Member& enemy); // 0.7�� �� ���� �õ�

	void CancelAttack(); // ȸ�� �� ���� �ߴ�

	virtual void Attack(Member& target); // ����
	virtual void TakeDamage(int dmg, const Member& Attacker); // ������ �ޱ�

	virtual void AAttack(Member& target); // ������

	int RepeatDodge() const { return repeatDodge; }

	void IncreaseDodge() { dodgeCount++; } // ȸ�� Ƚ�� ����
	int DodgeCount() const { return dodgeCount; }


};

