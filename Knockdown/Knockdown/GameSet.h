#pragma once
#include "Setting.h"
#include "Player.h"
#include "Enemy.h"

#define SPACE 32

using namespace std;

class GameSet : public Setting
{
private:
	bool isGameRunning = true; // 게임이 시작되었는가?
	bool isBattleStart = false; // 배틀이 시작되었는가?
	const DWORD TIMER = 60000; // 60초 타이머
	DWORD gameStartTime = 0; // 타이머용 게임 시작 시간
	int timeleft = 0; // 타이머 남은 시간
	int Result = 0; // 결과값 저장

	DWORD idleTime = 0; // 아이들 시간 기록
	DWORD P_DamageTime = 0; // 플레이어 데미지 출력 시간 기록
	DWORD A_DamageTime = 0; // 적 데미지 출력 시간 기록

protected:
	Member member;
	Player player;
	Enemy enemy;
	bool idleBreath = true;  // 아이들 숨쉬는 애니메이션용

public :
	int GetResult() const{ return Result; }
	void InputKey(); // 키 입력 처리
	void UpdateGame(); // 게임 업데이트
	void RenderGame(); // 게임 화면 표시
	void RunGame(); // 게임 메인 루프
	void ResultGame(); // 게임 결과 평가

	// 출력 처리용 함수 모음

	void HowToPlayScreen(); // 게임 실행 전, 설명

	void BeforeRunGame(); // RunGame 이전에 3초 카운트다운
	void ResetCursor(); // 매 루프마다 커서 리셋, 기존 그래픽 지우기 함수
	void HpAndTimer(); // 화면 상단에 각 멤버의 HP 바, 강공격 바, 타이머 출력
	void PlayerPrint(); // 플레이어 상태에 따라 그래픽 표시
	void EnemyPrint(); // 적 상태에 따라 그래픽 표시
	void GameText(); // 안내 텍스트 (데미지, 회피, 명중률 저하 등)
	void HowToPlay(); // 게임 방법 설명 및 키 안내

	void HpBarMaker(int hp); // HP 숫자에 따른 BAR 표시
	void SwitchIdle(); // idle 애니메이션 바꾸기

};

