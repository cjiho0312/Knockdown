#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>


class Setting
{
protected:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Ŀ�� ����
	CONSOLE_CURSOR_INFO cursorInfo;

public:
	void InitialSetup(); // �ʱ⼳��
	void CursorP(int x, int y); // ����ȭ�� Ŀ�� ��ġ �̵�
	void CursorH(); // Ŀ�� �����
	void CursorV(); // Ŀ�� ���̱�

};

