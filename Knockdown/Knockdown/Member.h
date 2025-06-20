#pragma once
class Member
{
private:
	int HP; // 체력
	bool isAlive; // 상태

public:
	Member() : HP(20), isAlive(true) {} // 멤버 초기화 리스트 사용, HP는 20, isAlive true로 초기화.
	virtual ~Member() {} // 소멸자



};

