#pragma once
#include <iostream>
#include <windows.h> // sistem �Լ� ���
#include <conio.h> // getch �� ����� �Լ� ���
#include <cstdlib> // ���� ����


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

