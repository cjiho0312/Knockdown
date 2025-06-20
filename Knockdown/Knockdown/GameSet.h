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

	void InputKey(); // 키 입력 처리
	void UpdateGame(); // 게임 업데이트
	void RenderGame(); // 게임 화면 표시
	void RunGame(); // 게임 메인 루프
	void EndingGame(); // 게임 엔딩
};

