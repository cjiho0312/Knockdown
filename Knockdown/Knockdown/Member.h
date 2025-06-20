#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Member
{
protected:
	
	int hp; // 체력
	bool isAlive; // 상태
	

public:
	Member() : hp(20), isAlive(true) {} // 멤버 초기화 리스트 사용, HP는 20, isAlive true로 초기화.
	virtual ~Member() {} // 소멸자

	int GetHP() const { return hp; }
	bool IsAlive() const { return isAlive; }
	

	void Attack(Member& target);
	virtual void TakeDamage(int dmg);

};

