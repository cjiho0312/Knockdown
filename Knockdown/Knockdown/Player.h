#pragma once
#include "Member.h"
#include <windows.h>

class Player : public Member
{
private :
	DWORD dodgeStartTime = 0; // 회피 시작 시간 기록
	DWORD AttackTime = 0; // 회피 시작 시간 기록

	STATE PLAYER; // 플레이어 상태 선언
	
public:
	STATE GetPlayerState() const { return PLAYER; } // Player의 상태 반환
	
	void PrepareAttack() override; // 공격 준비
	void TryAttack(Member& enemy) override; // 공격 시도
	void Attack(Member& enemy);
	void AAttack(Member& target) override;

	bool IsDodging() const { return isDodging; }

	void CheckRA(); // repeatAttack 확인 및 불러오기
	
	void Dodge(); // 회피
	void EndDodge(); // 회피 끝

	void TakeDamage(int dmg, const Member& Attacker) override;
 
};

