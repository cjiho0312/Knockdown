#include "Endding.h"
using namespace std;


void Endding::printEndding()
{
	CursorP(0, 0);

	EndResult = gameset.GetResult(); // GameSet���� Result�� �޾ƿ���

	if (EndResult == 0) // ����� ��
	{
		string TIMEOUT[10]{
		"  __~~~____~~~~___~~~~~_____~~___~~~~~____~~~___~~__",
		" //  ,___  .  .    ,   ___      ___  ,   , .___~    ��",
		"//     |   |  |��  /|  |__     /   �� |   |   |      !",
		"!!     |   |  | ��/ |  |       |.   | |   |   |      !",
		"!!     |   |  |  |  |  |__,    ��__/  ��__/   |      /",
		"����___~~~~_______~~~____         ___~~~______~~~___/",
		"                        ����    /",
		"                         ����  /",
		"                          ����/",
		"                           ��/"
		};

		for (int i = 0; i < 10; i++)
		{
			CursorP(33, 6 + i);
			cout << TIMEOUT[i];
		}
		Sleep(2000);

		system("cls");

	}	
	else if (EndResult == 2) // �̰��� ��
	{
		string KNOCKDOWN[10]{
		"  __~~~____~~~~___~~~~~_____~~___~~~~~____~~~___~~~~__",
		" //  ,    ,      _   ._  ,     ._     _        ,      ��",
		"//   | /  |�� | / �� / �� | /   | ��  / �� | ! | |�� |   !",
		"!!   |��  | ��| |  | |    |��   |  | |   | | | | | ��|   !",
		"!!   | �� |  `| ��_/ ��_/ | ��  |__/ ��_/  ��|/  |  `|  /",
		"����___~~~~__~~___~~~____         ___~~~___~~___~~~~__/",
		"                        ����    /",
		"                         ����  /",
		"                          ����/",
		"                           ��/"
		};

		for (int i = 0; i < 10; i++)
		{
			CursorP(32, 6 + i);
			cout << KNOCKDOWN[i];
		}
		Sleep(2000);

		system("cls");

		CursorP(0, 0); // ���� ȭ�� ���
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                    \u25A0  \u25A0  \u25A0  \u25A0\u25A0\u25A0  \u25A0      \u25A0  \u25A0" << endl;
		cout << "                |                                                   \u25A0  \u25A0  \u25A0    \u25A0    \u25A0\u25A0    \u25A0  \u25A0" << endl;
		cout << "              - o -                    +                            \u25A0  \u25A0  \u25A0    \u25A0    \u25A0  \u25A0  \u25A0  \u25A0" << endl;
		cout << "                |           ~;~-~,                                  \u25A0  \u25A0  \u25A0    \u25A0    \u25A0    \u25A0\u25A0" << endl;
		cout << "                        .;;;;;;;-,)                                   \u25A0  \u25A0    \u25A0\u25A0\u25A0  \u25A0      \u25A0  \u25A0" << endl;
		cout << "           +          .;~ ;/                *                                          " << endl;
		cout << "                     !  *;/  ::,~,                                                     " << endl;
		cout << "                     ,:   &=.    *                                                     " << endl;
		cout << "                      !   @@ _  _ @              :;-                                   " << endl;
		cout << "              *        # ;@@.  v  @@!;;~~;;;:--  ~;  )                                 " << endl;
		cout << "                        !@@@~:;;@@@:    .,:;;;;~  :;                                   " << endl;
		cout << "                        .@@@@;~;@@@#;;;`                                               " << endl;
		cout << "                  +      @@@@@@@@@@=          *                                        " << endl;
		cout << "                          @@@@@@@@@-                  |                                " << endl;
		cout << "         *               @@@@@@@@@@-    +           - o -                              " << endl;
		cout << "                    .;~;;       .-~~;:;               |                                " << endl;
		cout << "                  ,;:.;;    ;;;,       ;#;                                             " << endl;
		cout << "                ;=.    ;$;;,   -;:~ ~;;:  :~;      +                                   " << endl;
		cout << "                 $   ,$            ;:;:      ;;.                                       " << endl;
		cout << "           |     ,$   !:   +           ~:;;    ,!:                                     " << endl;
		cout << "         - o -    ,$   $                   :;;;  :;~                                   " << endl;
		cout << "           |        ;;  $          +           ;!  -$,                                 " << endl;
		cout << "                     .;-:!                       ;   ~;                                " << endl;
		cout << "                 -$;;; . #                       ,!   ~~                               " << endl;
		cout << "                  -;,..;;.                        ,-:;;                                " << endl;


	}	
	else if (EndResult == 1) // ���� ��
	{
		string KNOCKDOWN[10]{
		"  __~~~____~~~~___~~~~~_____~~___~~~~~____~~~___~~~~__",
		" //  ,    ,      _   ._  ,     ._     _        ,      ��",
		"//   | /  |�� | / �� / �� | /   | ��  / �� | ! | |�� |   !",
		"!!   |��  | ��| |  | |    |��   |  | |   | | | | | ��|   !",
		"!!   | �� |  `| ��_/ ��_/ | ��  |__/ ��_/  ��|/  |  `|  /",
		"����___~~~~__~~___~~~____         ___~~~___~~___~~~___/",
		"                        ����    /",
		"                         ����  /",
		"                          ����/",
		"                           ��/"
		};

		for (int i = 0; i < 10; i++)
		{
			CursorP(32, 6 + i);
			cout << KNOCKDOWN[i];
		}
		Sleep(2000);

		system("cls");

		CursorP(0, 0); // ���� ȭ�� ���
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                              \u25A0         \u25A0\u25A0      \u25A0\u25A0\u25A0  \u25A0\u25A0\u25A0\u25A0      " << endl;
		cout << "                                                              \u25A0       \u25A0    \u25A0  \u25A0        \u25A0  " << endl;
		cout << "                                                              \u25A0       \u25A0    \u25A0  \u25A0\u25A0\u25A0\u25A0  \u25A0\u25A0\u25A0\u25A0   " << endl;
		cout << "                                                              \u25A0       \u25A0    \u25A0        \u25A0  \u25A0     " << endl;
		cout << "                                                              \u25A0\u25A0\u25A0\u25A0   \u25A0\u25A0    \u25A0\u25A0\u25A0    \u25A0\u25A0\u25A0\u25A0  \u25A0  \u25A0  \u25A0  " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                              !                                                        " << endl;
		cout << "                             !                                                         " << endl;
		cout << "                              !                                                        " << endl;
		cout << "                        !    !                                                         " << endl;
		cout << "                       !      !    !                                                   " << endl;
		cout << "                        !           !                                                  " << endl;
		cout << "                                   !                                                   " << endl;
		cout << "                     ,, ,#@$;@@@@@&=;,,,                                               " << endl;
		cout << "                  ,,;;. @#````  `#!@    ;;..                                           " << endl;
		cout << "               ,;;.    `@!       ;#@ ` ,,,;;  ``;, ..;                                 " << endl;
		cout << "              (  :^`)&   @!;;;;;;;@@  (@ !  #  ~    ; ~                                " << endl;
		cout << "              `;;;#,; , ;@@!;;;/ @@;;;;$,,,/;,,;#;;'@;;                                " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;

	}
}
