#pragma once
#include "Setting.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class GameSet : public Setting
{
private:
	bool isGameRunning = true; // 게임이 시작되었는가?
	bool isBattleStart = false; // 배틀이 시작되었는가?
	const DWORD TIMER = 60000; // 60초 타이머
	DWORD gameStartTime = 0; // 60초 타이머용 게임 시작 시간
	int timeleft = 0; // 타이머 남은 시간
	int Result = 0; // 결과값 저장

protected:
	Member member;
	Player player;
	Enemy enemy;
	bool onceclear = true; // 추후삭제

public :
	int GetResult() const{ return Result; }
	void InputKey(); // 키 입력 처리
	void UpdateGame(); // 게임 업데이트
	void RenderGame(); // 게임 화면 표시
	void RunGame(); // 게임 메인 루프
	void ResultGame(); // 게임 결과 평가
};

