#include "Mainmenu.h"
using namespace std;

Mainmenu::Mainmenu(){}

void Mainmenu::printmain()
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
    cout << "                                                                                                                 " << endl << endl;
    cout << "                                                                                                                 " << endl;
    cout << "\n\n\n\n\n                                                    Press SPACE BAR..." << endl;

    CursorP(53, 24);
    cout << "| GAME START |";
    CursorP(56, 26);
    cout << "| EXIT |";

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
}
