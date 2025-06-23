#pragma once
#include "Member.h"
#include <windows.h>

class Player : public Member
{
private :
	DWORD dodgeStartTime = 0; // ȸ�� ���� �ð� ���
	DWORD AttackTime = 0; // ȸ�� ���� �ð� ���

	STATE PLAYER = IDLE; // �÷��̾� ���� ����
	
public:
	void Attack(Member& enemy);

	bool IsDodging() const { return isDodging; }

	void CheckRA(); // repeatAttack Ȯ�� �� �ҷ�����
	
	void Dodge(); // ȸ��
	void EndDodge(); // ȸ�� ��

	void TakeDamage(int dmg, const Member& Attacker) override;
 
};

