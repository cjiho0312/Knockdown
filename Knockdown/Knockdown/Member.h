#pragma once
#include <iostream>
using namespace std;

class Member
{
protected:
	

public:
	Member() : HP(20), isAlive(true) {} // 멤버 초기화 리스트 사용, HP는 20, isAlive true로 초기화.
	virtual ~Member() {} // 소멸자

	int HP; // 체력
	bool isAlive; // 상태
	int DodgeCount; // 회피 횟수

	void Attack(Member& target);
	void TakeDamage(int dmg);

};

