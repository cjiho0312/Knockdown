#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>

#define UP 72
#define DOWN 80
#define SPACE 32

class Setting
{
protected:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Ŀ�� ����
	CONSOLE_CURSOR_INFO cursorInfo;

public:
	void InitialSetup(); // �ʱ⼳��
	void CursorP(int x, int y); // ����ȭ�� Ŀ�� ��ġ �̵�
	void CursorH(); // Ŀ�� �����

};

