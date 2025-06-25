#pragma once
#include "Member.h"
#include <windows.h>

class Player : public Member
{
private :
	DWORD dodgeStartTime = 0; // 회피 시작 시간 기록
	DWORD AttackTime = 0; // 공격 시작 시간 기록
	DWORD DodgeTime = 0; // 회피 끝 시간 기록 (반복회피 변수용)
	DWORD StateTime = 0; // 상태 지정 시간 기록
	DWORD TiredTime = 0; // 지침 상태 시간 기록
	bool changeState = true; // SetPlayerState가 가능한가?
	bool soTired = false; // 피곤한가?
	STATE PLAYER; // 플레이어 상태 선언
	
public:
	STATE GetPlayerState() const { return PLAYER; } // Player의 상태 반환
	void SetPlayerState(); // 출력을 위한 일정 시간 그래픽 함수
	bool ChangeState() const { return changeState; }
	
	void PrepareAttack() override; // 공격 준비
	void TryAttack(Member& enemy) override; // 공격 시도
	void Attack(Member& enemy);
	void AAttack(Member& target) override;

	bool IsDodging() const { return isDodging; }

	void CheckRA(); // repeatAttack 확인 및 불러오기
	void CheckRD(); // repeatDodge 확인 및 불러오기
	
	void Dodge(); // 회피
	void EndDodge(); // 회피 끝

	void Tired(); // 지침
	void EndTired(); // Tired 상태 끝인지 확인
	bool SoTired() { return soTired; }

	void TakeDamage(int dmg, const Member& Attacker) override;
 
};

