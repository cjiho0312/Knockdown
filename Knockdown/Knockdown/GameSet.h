#pragma once
#include "Setting.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class GameSet : public Setting
{
private:
	bool isGameRunning = true; // ������ ���۵Ǿ��°�?
	bool isBattleStart = false; // ��Ʋ�� ���۵Ǿ��°�?
	const DWORD TIMER = 60000; // 60�� Ÿ�̸�
	DWORD gameStartTime = 0; // 60�� Ÿ�̸ӿ� ���� ���� �ð�
	int timeleft = 0; // Ÿ�̸� ���� �ð�
	int Result = 0; // ����� ����

protected:
	Member member;
	Player player;
	Enemy enemy;
	bool onceclear = true; // ���Ļ���

public :
	int GetResult() const{ return Result; }
	void InputKey(); // Ű �Է� ó��
	void UpdateGame(); // ���� ������Ʈ
	void RenderGame(); // ���� ȭ�� ǥ��
	void RunGame(); // ���� ���� ����
	void ResultGame(); // ���� ��� ��

	// ��� ó���� �Լ� ����
	void ResetCursor(); // �� �������� Ŀ�� ����, ���� �׷��� ����� �Լ�
	void HpAndTimer(); // ȭ�� ��ܿ� �� ����� HP ��, ������ ��, Ÿ�̸� ���
	void PlayerPrint(); // �÷��̾� ���¿� ���� �׷��� ǥ��
	void EnemyPrint(); // �� ���¿� ���� �׷��� ǥ��
	void GameText(); // �ȳ� �ؽ�Ʈ (������, ȸ��, ���߷� ���� ��)
	void HowToPlay(); // ���� ��� ���� �� Ű �ȳ�

	void HpBarMaker(int hp); // HP ���ڿ� ���� BAR ǥ��

};

