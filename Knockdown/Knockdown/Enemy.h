#pragma once
#include "Member.h"
class Enemy : public Member
{
private:
	DWORD lastAttackTime = 0; // 마지막 공격 시간
	DWORD nextAttackDelay = 0; // 다음 공격 시간
	DWORD attackStartTime = 0; // 공격 시작 시간

	bool isPreparingAttack = false; // 공격이 준비되었는가?
	bool enemyCanAttack = false; // 공격 가능한가?

public:
	void FirstAttack(); // 첫 공격 설정
	
	void PrepareAttack() override; // 적 공격 준비
	void TryAttack(Member& player) override; // 적 공격 시도
	void Attack(Member& player) override; // 공격

	void CheckECA(); // enemyCanAttack 상태 확인 및 수정

	bool EnemyCanAttack() const { return enemyCanAttack; }

	void TakeDamage(int dmg, const Member & Attacker) override;
};

