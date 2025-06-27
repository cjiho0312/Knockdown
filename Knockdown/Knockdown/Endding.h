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
	Endding(GameSet& gs) : gameset(gs) {} // Endding 초기화
	/*
	-- 멤버 초기화 리스트 -- 
	(GameSet& gs) -> 자료형이 GameSet인 참조(원본) 매개변수
	: gamset(gs) -> Endding 내부의 gameset 멤버 변수에 gs(main에서 받아옴)을 대입해서 초기화
	참조(&)형 타입은 반드시 멤버 초기화 리스트를 사용하여야 함. 생성자 내부에서 수행 X!
	*/

	void printEndding(); // 엔딩 출력
	void EndInputKey(); // 엔딩에서 키 입력
}; 