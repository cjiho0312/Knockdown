#include "Setting.h"
using namespace std;

void Setting::InitialSetup() // �ʱ� ����
{
    system("mode con: cols=120 lines=40"); // �ܼ�â ũ�� ����
    system("title KNOCKDOWN"); // �ܼ�â �̸� ����
}

void Setting::CursorP(int x, int y) // Ŀ�� ��ġ �̵� �Լ�
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}

void Setting::CursorH() // Ŀ�� ����� �Լ�
{
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
