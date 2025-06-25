#pragma once
#include "Member.h"
#include <windows.h>

class Player : public Member
{
private :
	DWORD dodgeStartTime = 0; // ȸ�� ���� �ð� ���
	DWORD AttackTime = 0; // ���� ���� �ð� ���
	DWORD DodgeTime = 0; // ȸ�� �� �ð� ��� (�ݺ�ȸ�� ������)
	DWORD StateTime = 0; // ���� ���� �ð� ���
	DWORD TiredTime = 0; // ��ħ ���� �ð� ���
	bool changeState = true; // SetPlayerState�� �����Ѱ�?
	bool soTired = false; // �ǰ��Ѱ�?
	STATE PLAYER; // �÷��̾� ���� ����
	
public:
	STATE GetPlayerState() const { return PLAYER; } // Player�� ���� ��ȯ
	void SetPlayerState(); // ����� ���� ���� �ð� �׷��� �Լ�
	bool ChangeState() const { return changeState; }
	
	void PrepareAttack() override; // ���� �غ�
	void TryAttack(Member& enemy) override; // ���� �õ�
	void Attack(Member& enemy);
	void AAttack(Member& target) override;

	bool IsDodging() const { return isDodging; }

	void CheckRA(); // repeatAttack Ȯ�� �� �ҷ�����
	void CheckRD(); // repeatDodge Ȯ�� �� �ҷ�����
	
	void Dodge(); // ȸ��
	void EndDodge(); // ȸ�� ��

	void Tired(); // ��ħ
	void EndTired(); // Tired ���� ������ Ȯ��
	bool SoTired() { return soTired; }

	void TakeDamage(int dmg, const Member& Attacker) override;
 
};

