#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Member
{
protected:
	
	int hp; // 체력
	bool isAlive; // 상태
	
	bool isPreparingAttack = false; // 공격 준비 상태인지 알려줌
	DWORD attackStartTime = 0; // 공격 시작 시간 기록

	bool isDodging = false; // 회피 중인 상태인지 알려줌
	bool isAAttack = false; // 강공격 상태인지 알려줌

	int repeatAttack = 0; // 연속 공격 횟수
	int dodgeCount = 0; // 회피 횟수

public:

	Member() : hp(20), isAlive(true) {} // 멤버 초기화 리스트 사용, HP는 20, isAlive true로 초기화.
	virtual ~Member() {} // 소멸자

	int GetHP() const { return hp; }
	bool IsAlive() const { return isAlive; }
	
	bool IsPreparingAttack() const { return isPreparingAttack; }

	bool IsDodgig() const { return isDodging; }
	bool IsAAttack() const { return isAAttack; }

	int RepeatAttack() const { return repeatAttack; }

	virtual void PrepareAttack(); // 공격 예고
	virtual void TryAttack(Member& enemy); // 0.7초 후 공격 시도

	void CancelAttack(); // 회피 시 공격 중단

	virtual void Attack(Member& target); // 공격
	virtual void TakeDamage(int dmg, const Member& Attacker); // 데미지 받기

	void AAttack(Member& target); // 강공격

	void ResetDodge() { dodgeCount = 0; } // 회피 횟수 초기화
	void IncreaseDodge() { dodgeCount++; } // 회피 횟수 증가
	int DodgeCount() const { return dodgeCount; }

};

