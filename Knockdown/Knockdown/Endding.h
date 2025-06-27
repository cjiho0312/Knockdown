#pragma once
#include "Setting.h"
#include "GameSet.h"

#define UP 72
#define DOWN 80
#define SPACE 32

class Endding : public Setting
{
private:
	GameSet &gameset;
	int EndResult = 0;
public:
	Endding(GameSet& gs) : gameset(gs) {} // Endding �ʱ�ȭ
	/*
	-- ��� �ʱ�ȭ ����Ʈ -- 
	(GameSet& gs) -> �ڷ����� GameSet�� ����(����) �Ű�����
	: gamset(gs) -> Endding ������ gameset ��� ������ gs(main���� �޾ƿ�)�� �����ؼ� �ʱ�ȭ
	����(&)�� Ÿ���� �ݵ�� ��� �ʱ�ȭ ����Ʈ�� ����Ͽ��� ��. ������ ���ο��� ���� X!
	*/

	void printEndding(); // ���� ���
	void EndInputKey(); // �������� Ű �Է�
}; 