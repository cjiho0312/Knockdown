#include "Setting.h"
using namespace std;

void Setting::InitialSetup() // 초기 설정
{
    SetConsoleScreenBufferSize(hConsole, {120,40}); // 버퍼 크기 수정
    system("mode con: cols=120 lines=40"); // 콘솔창 크기 조절
    system("title KNOCKDOWN"); // 콘솔창 이름 설정
}

void Setting::CursorP(int x, int y) // 커서 위치 이동 함수
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
} 

void Setting::CursorH() // 커서 숨기기 함수
{
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void Setting::CursorV() // 커서 보이기 함수
{
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
