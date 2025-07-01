#pragma once
#include "Setting.h"
#include "Player.h"
#include "Enemy.h"

#define SPACE 32

using namespace std;

class GameSet : public Setting
{
private:
	bool isGameRunning = true; // ������ ���۵Ǿ��°�?
	bool isBattleStart = false; // ��Ʋ�� ���۵Ǿ��°�?
	const DWORD TIMER = 60000; // 60�� Ÿ�̸�
	DWORD gameStartTime = 0; // Ÿ�̸ӿ� ���� ���� �ð�
	int timeleft = 0; // Ÿ�̸� ���� �ð�
	int Result = 0; // ����� ����

	DWORD idleTime = 0; // ���̵� �ð� ���
	DWORD P_DamageTime = 0; // �÷��̾� ������ ��� �ð� ���
	DWORD A_DamageTime = 0; // �� ������ ��� �ð� ���

protected:
	Member member;
	Player player;
	Enemy enemy;
	bool idleBreath = true;  // ���̵� ������ �ִϸ��̼ǿ�

public :
	int GetResult() const{ return Result; }
	void InputKey(); // Ű �Է� ó��
	void UpdateGame(); // ���� ������Ʈ
	void RenderGame(); // ���� ȭ�� ǥ��
	void RunGame(); // ���� ���� ����
	void ResultGame(); // ���� ��� ��

	// ��� ó���� �Լ� ����

	void HowToPlayScreen(); // ���� ���� ��, ����

	void BeforeRunGame(); // RunGame ������ 3�� ī��Ʈ�ٿ�
	void ResetCursor(); // �� �������� Ŀ�� ����, ���� �׷��� ����� �Լ�
	void HpAndTimer(); // ȭ�� ��ܿ� �� ����� HP ��, ������ ��, Ÿ�̸� ���
	void PlayerPrint(); // �÷��̾� ���¿� ���� �׷��� ǥ��
	void EnemyPrint(); // �� ���¿� ���� �׷��� ǥ��
	void GameText(); // �ȳ� �ؽ�Ʈ (������, ȸ��, ���߷� ���� ��)
	void HowToPlay(); // ���� ��� ���� �� Ű �ȳ�

	void HpBarMaker(int hp); // HP ���ڿ� ���� BAR ǥ��
	void SwitchIdle(); // idle �ִϸ��̼� �ٲٱ�

};

