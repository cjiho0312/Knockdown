#pragma once
#include "Member.h"
class Enemy : public Member
{
private:
	DWORD lastAttackTime = 0; // 마지막 공격 시간
	DWORD nextAttackDelay = 0; // 다음 공격 시간
	DWORD attackStartTime = 0; // 공격 시작 시간
	DWORD StateTime = 0; // 상태 지정 시간 기록

	bool isPreparingAttack = false; // 공격이 준비되었는가?
	bool enemyCanAttack = false; // 공격 가능한가?
	bool changeState = true; // SetEnemyState가 가능한가?

	STATE ENEMY; // 적 상태 선언

public:
	STATE GetEnemyState() const { return ENEMY; } // Enemy의 상태 반환
	void SetEnemyState(); // 출력을 위한 일정 시간 그래픽 함수

	void FirstAttack(); // 첫 공격 설정
	
	void PrepareAttack() override; // 적 공격 준비
	void TryAttack(Member& player) override; // 적 공격 시도
	void Attack(Member& player) override; // 공격

	void CheckECA(); // enemyCanAttack 상태 확인 및 수정

	bool EnemyCanAttack() const { return enemyCanAttack; }
	bool ChangeState() const { return changeState; }

	void TakeDamage(int dmg, const Member & Attacker) override;
};

