#pragma once
#include "Member.h"
#include <windows.h>

class Player : public Member
{
private :
	bool isPreparingAttack = false; // 공격 준비 상태인지 알려줌
	bool isDodging = false; // 회피 중인 상태인지 알려줌
	bool successDodge = false; // 회피 성공 상태인지 알려줌
	int dodgeCount; // 회피 횟수
	DWORD attackStartTime = 0; // 공격 시작 시간 기록
	DWORD dodgeStartTime = 0; // 공격 시작 시간 기록
	
public:
	void PrepareAttack(); // 공격 예고
	void TryAttack(Member& enemy); // 0.7초 후 공격 시도
	void CancelAttack(); // 회피 시 공격 중단

	bool IsPreparingAttack() const { return isPreparingAttack; }

	bool IsDodgoing() const { return isDodging; }
	bool SuccessDodge() const { return successDodge; }
	int GetDodgeCount() const { return dodgeCount; }

	void ResetDodge() { dodgeCount = 0; }
	void IncreaseDodge() { dodgeCount++; }

	void Dodge(); // 회피
	void EndDodge(); // 회피 끝

	void TakeDamage(int dmg) override;

};

