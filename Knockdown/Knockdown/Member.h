#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Member
{
protected:
	
	int hp; // ü��
	bool isAlive; // ����
	

public:
	Member() : hp(20), isAlive(true) {} // ��� �ʱ�ȭ ����Ʈ ���, HP�� 20, isAlive true�� �ʱ�ȭ.
	virtual ~Member() {} // �Ҹ���

	int GetHP() const { return hp; }
	bool IsAlive() const { return isAlive; }
	

	void Attack(Member& target);
	virtual void TakeDamage(int dmg);

};

