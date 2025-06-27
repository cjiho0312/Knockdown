#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>


class Setting
{
protected:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 커서 관련
	CONSOLE_CURSOR_INFO cursorInfo;

public:
	void InitialSetup(); // 초기설정
	void CursorP(int x, int y); // 메인화면 커서 위치 이동
	void CursorH(); // 커서 숨기기
	void CursorV(); // 커서 보이기

};

