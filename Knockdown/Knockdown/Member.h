#pragma once
#include <iostream>
using namespace std;

class Member
{
protected:
	

public:
	Member() : HP(20), isAlive(true) {} // ��� �ʱ�ȭ ����Ʈ ���, HP�� 20, isAlive true�� �ʱ�ȭ.
	virtual ~Member() {} // �Ҹ���

	int HP; // ü��
	bool isAlive; // ����
	int DodgeCount; // ȸ�� Ƚ��

	void Attack(Member& target);
	void TakeDamage(int dmg);

};

