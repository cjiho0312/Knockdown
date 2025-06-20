#pragma once
#include "Setting.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

class GameSet : public Setting
{
private:
	bool isGameRunning = true;

protected:
	Player player;
	Enemy enemy;

public :

	void InputKey(); // Ű �Է� ó��
	void UpdateGame(); // ���� ������Ʈ
	void RenderGame(); // ���� ȭ�� ǥ��
	void RunGame(); // ���� ���� ����
	void EndingGame(); // ���� ����
};

