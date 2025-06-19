#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include "Setting.h"

#define UP 72
#define DOWN 80
#define SPACE 32

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 커서 관련
CONSOLE_CURSOR_INFO cursorInfo;

void CursorP(int, int);

void InitialSetup() // 초기설정
{
    system("mode con: cols=120 lines=40 | title KNOCKDOWN"); // 콘솔창 크기 조절
}

void CursorP(int x, int y) // 메인화면 커서 위치 이동
{

    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);

}

void CursorH() // 커서 숨기기
{
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

int PrintMainMenu() // 메인 메뉴
{
    cout << "\n\n\n\n\n\n\n\n\n" << endl;
    cout << "                                                                              (   *    &    3                    " << endl;
    cout << "                      *        *        *        *        *                  (  |   ^ /   @     )                " << endl;
    cout << "                   ##   ##  ##   ##    ###      ####   ##   ##    *              |  /   ___ _ >  )               " << endl;
    cout << "                   ##  ##   ###  ##  ##   ##  ##    #  ##  ##   ####       *     | /  --                         " << endl;
    cout << "                   ####     ## # ##  ##   ##  ##       ####     ##  ##    ###        *                           " << endl;
    cout << "                   ##  ##   ##  ###  ##   ##  ##    #  ##  ##   ##   #  ##   ##   #     #      *                 " << endl;
    cout << "                   ##   ##  ##   ##    ###      ####   ##   ##  ##  ##  ##   ##  ##     ##  ##                   " << endl;
    cout << "                                                                ####    ##   ##  ##  #  ##  ###      #           " << endl;
    cout << "                                                                          ###     ### ###   ## #   #             " << endl;
    cout << "                                                                                   #   #    ##  ###              " << endl;
    cout << "                                                                                            ##   #               " << endl;
    cout << "                                                                                                                 " << endl;
    cout << "                                                                                                                 " << endl;
    cout << "                                                                                                                 " << endl;
    cout << "                                                     | GAME START |" << endl << endl;
    cout << "                                                        | EXIT |" << endl;
    cout << "\n\n\n\n\n                                                    Press SPACE BAR..." << endl;

    CursorP(51, 24);

    int CursorInput; // 방향키 입력 변수
    bool CursorPoint = 1; // 커서가 가리키고 있는 부분을 알려주는 변수
    bool MainmenuCursor = 1; // 스패이스바 누르기 전까지 대기하는 변수


    while (MainmenuCursor == 1)
    {
        CursorInput = _getch();
        
        if (CursorInput == 224) // 방향키 입력 시
        {
            CursorInput = _getch(); // 복합키워드 224를 제외한 숫자를 저장
        }

        if (CursorInput == UP) // START를 가리킴
        {
            CursorPoint = 1;
            CursorP(51, 24);
        }
        else if (CursorInput == DOWN) // EXIT을 가리킴
        {
            CursorPoint = 0;
            CursorP(51, 26);
        }

        if (CursorInput == SPACE) // SPACE 입력
        {
            if (CursorPoint == 1) // START를 가리키고 있을 경우
            {
                MainmenuCursor = 0;
            }
            else if (CursorPoint == 0) // EXIT를 가리키고 있을 경우
            {
                system("cls");
                exit(0);
            }
        }
    }
    return 0;
}


int main()
{
    InitialSetup(); // 초기 설정
    PrintMainMenu(); // 메인 메뉴 화면

    system("cls"); // 화면 clear
    



    return 0;
}