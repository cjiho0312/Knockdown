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
	Member member;
	Player player;
	Enemy enemy;

	bool onceclear = true; // ���Ļ���

public :

	void InputKey(); // Ű �Է� ó��
	void UpdateGame(); // ���� ������Ʈ
	void RenderGame(); // ���� ȭ�� ǥ��
	void RunGame(); // ���� ���� ����
	void EndingGame(); // ���� ����
};

