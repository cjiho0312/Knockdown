#pragma once
#include "Member.h"
#include <windows.h>

class Player : public Member
{
private :
	bool isPreparingAttack = false; // ���� �غ� �������� �˷���
	bool isDodging = false; // ȸ�� ���� �������� �˷���
	bool successDodge = false; // ȸ�� ���� �������� �˷���
	int dodgeCount; // ȸ�� Ƚ��
	DWORD attackStartTime = 0; // ���� ���� �ð� ���
	DWORD dodgeStartTime = 0; // ���� ���� �ð� ���
	
public:
	void PrepareAttack(); // ���� ����
	void TryAttack(Member& enemy); // 0.7�� �� ���� �õ�
	void CancelAttack(); // ȸ�� �� ���� �ߴ�

	bool IsPreparingAttack() const { return isPreparingAttack; }

	bool IsDodgoing() const { return isDodging; }
	bool SuccessDodge() const { return successDodge; }
	int GetDodgeCount() const { return dodgeCount; }

	void ResetDodge() { dodgeCount = 0; }
	void IncreaseDodge() { dodgeCount++; }

	void Dodge(); // ȸ��
	void EndDodge(); // ȸ�� ��

	void TakeDamage(int dmg) override;

};

