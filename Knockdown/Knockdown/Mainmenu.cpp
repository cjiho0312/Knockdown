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

    int CursorInput; // ����Ű �Է� ����
    bool CursorPoint = 1; // Ŀ���� ����Ű�� �ִ� �κ��� �˷��ִ� ����
    bool MainmenuCursor = 1; // �����̽��� ������ ������ ����ϴ� ����


    while (MainmenuCursor == 1)
    {
        CursorInput = _getch();

        if (CursorInput == 224) // ����Ű �Է� ��
        {
            CursorInput = _getch(); // ����Ű���� 224�� ������ ���ڸ� ����
        }

        if (CursorInput == UP) // START�� ����Ŵ
        {
            CursorPoint = 1;
            CursorP(51, 24);
        }
        else if (CursorInput == DOWN) // EXIT�� ����Ŵ
        {
            CursorPoint = 0;
            CursorP(51, 26);
        }

        if (CursorInput == SPACE) // SPACE �Է�
        {
            if (CursorPoint == 1) // START�� ����Ű�� ���� ���
            {
                MainmenuCursor = 0;
            }
            else if (CursorPoint == 0) // EXIT�� ����Ű�� ���� ���
            {
                system("cls");
                exit(0);
            }
        }
    }
}
