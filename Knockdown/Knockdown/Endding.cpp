#include "Endding.h"
using namespace std;


void Endding::printEndding()
{
	CursorP(0, 0);

	EndResult = gameset.GetResult(); // GameSet에서 Result값 받아오기

		string HAND[20]
		{
		"              ~_,",
		"           ~*    -",
		"          :,   .@!;- *",
		" ^~@     :,    ;:.   ;",
		" ~  #.   -.    *!    $.,,",
		"-@   # :$    $@    $#  ,@",
		" @   -**          #-   *,~.",
		" *.              :    ;   ;",
		" --                 .* , ~ ",
		"  --                    #",
		"  :                    *",
		"  =, ;           ~   ~=",
		"    -@            ! -;",
		"      @            ;@",
		"      @             @",
		"      #,            .;",
		"      #,             *-",
		"     ~-              =",
		"      -              .!",
		"     ,-               *"
		};

	if (EndResult == 0) // 비겼을 때
	{
		string TIMEOUT[10]{
		"  __~~~____~~~~___~~~~~_____~~___~~~~~____~~~___~~__",
		" //  ,___  .  .    ,   ___      ___  ,   , .____    ＼",
		"//     |   |  |＼  /|  |__     /   ＼ |   |   |      !",
		"!!     |   |  | ＼/ |  |       |.   | |   |   |      !",
		"!!     |   |  |  |  |  |__,    ＼__/  ＼__/   |      /",
		"＼＼___~~~~_______~~~____         ___~~~______~~~___/",
		"                        ＼＼    /",
		"                         ＼＼  /",
		"                          ＼＼/",
		"                           ＼/"
		};

		for (int i = 0; i < 10; i++)
		{
			CursorP(33, 6 + i);
			cout << TIMEOUT[i];
		}

		for (int i = 0; i < 20; i++)
		{
			CursorP(49, 17 + i);
			cout << HAND[i];
		}

		Sleep(2500);

		system("cls");

		CursorP(0, 0); // 엔딩 화면 출력

		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                            \u25A0\u25A0\u25A0    \u25A0\u25A0\u25A0      \u25A0\u25A0    \u25A0  \u25A0  \u25A0" << endl;
		cout << "                                                            \u25A0    \u25A0  \u25A0    \u25A0  \u25A0    \u25A0  \u25A0  \u25A0  \u25A0" << endl;
		cout << "                                                            \u25A0    \u25A0  \u25A0\u25A0\u25A0    \u25A0\u25A0\u25A0\u25A0  \u25A0  \u25A0  \u25A0" << endl;
		cout << "                                                            \u25A0    \u25A0  \u25A0  \u25A0    \u25A0    \u25A0  \u25A0  \u25A0  \u25A0" << endl;
		cout << "                             ::,~,                          \u25A0\u25A0\u25A0    \u25A0    \u25A0  \u25A0    \u25A0    \u25A0  \u25A0" << endl;
		cout << "                          &=.    *                                                     " << endl;
		cout << "                         @@ u _  _@                                                    " << endl;
		cout << "                    ;;```;@@     ;@!;;~~,,                                             " << endl;
		cout << "                   ;;   !@@@~:;;@@@:     ;,                                            " << endl;
		cout << "                  `;&   .@@@@;~;@@@#     ;;                                            " << endl;
		cout << "                   ;;    @@@@@@@@@@|    ;;                                             " << endl;
		cout << "                    !+   ,@@@@@@@@#    ;;                                              " << endl;
		cout << "                     !   ;@@@@@@@@)    ;                                               " << endl;
		cout << "                    .;   ;;.     .-;   :;                                              " << endl;
		cout << "                  ,;:.    ;;;;;, ; ;   ;#;                                             " << endl;
		cout << "                ;=.  !;    ;;,   -;    .,;;: :~                                        " << endl;
		cout << "                $    ,$ -~           ;:;:      ;;.                                     " << endl;
		cout << "                 ,$    $               ``` :,,,  `,                                    " << endl;
		cout << "                    ;;  $                      ;!  -,                                  " << endl;
		cout << "                     .;-:!                       ;   ~;                                " << endl;
		cout << "                 -$;;; . #                       ,!   ~~                               " << endl;
		cout << "                  -;,..;;.                        ,-:;;                                " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;

		EndInputKey();


	}	
	else if (EndResult == 2) // 이겼을 때
	{
		string KNOCKDOWN[10]{
		"  __~~~____~~~~___~~~~~_____~~___~~~~~____~~~___~~~~__",
		" //  ,    ,      _   ._  ,     ._     _        ,      ＼",
		"//   | /  |＼ | / ＼ / ＼ | /   | ＼  / ＼ | ! | |＼ |   !",
		"!!   |＼  | ＼| |  | |    |＼   |  | |   | | | | | ＼|   !",
		"!!   | ＼ |  `| ＼_/ ＼_/ | ＼  |__/ ＼_/  ＼|/  |  `|  /",
		"＼＼___~~~~__~~___~~~____         ___~~~___~~___~~~~__/",
		"                        ＼＼    /",
		"                         ＼＼  /",
		"                          ＼＼/",
		"                           ＼/"
		};

		for (int i = 0; i < 10; i++)
		{
			CursorP(32, 6 + i);
			cout << KNOCKDOWN[i];
		}

		for (int i = 0; i < 20; i++)
		{
			CursorP(49, 17 + i);
			cout << HAND[i];
		}

		Sleep(2500);

		system("cls");

		CursorP(0, 0); // 엔딩 화면 출력
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
		cout << "                                                                  \u25A0  \u25A0  \u25A0  \u25A0\u25A0\u25A0  \u25A0      \u25A0  \u25A0" << endl;
		cout << "                |                                                 \u25A0  \u25A0  \u25A0    \u25A0    \u25A0\u25A0    \u25A0  \u25A0" << endl;
		cout << "              - o -                    +                          \u25A0  \u25A0  \u25A0    \u25A0    \u25A0  \u25A0  \u25A0  \u25A0" << endl;
		cout << "                |           ~;~-~,                                \u25A0  \u25A0  \u25A0    \u25A0    \u25A0    \u25A0\u25A0" << endl;
		cout << "                        .;;;;;;;-,)                                 \u25A0  \u25A0    \u25A0\u25A0\u25A0  \u25A0      \u25A0  \u25A0" << endl;
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

		EndInputKey();
	}	
	else if (EndResult == 1) // 졌을 때
	{
		string KNOCKDOWN[10]{
		"  __~~~____~~~~___~~~~~_____~~___~~~~~____~~~___~~~~__",
		" //  ,    ,      _   ._  ,     ._     _        ,      ＼",
		"//   | /  |＼ | / ＼ / ＼ | /   | ＼  / ＼ | ! | |＼ |   !",
		"!!   |＼  | ＼| |  | |    |＼   |  | |   | | | | | ＼|   !",
		"!!   | ＼ |  `| ＼_/ ＼_/ | ＼  |__/ ＼_/  ＼|/  |  `|  /",
		"＼＼___~~~~__~~___~~~____         ___~~~___~~___~~~___/",
		"                        ＼＼    /",
		"                         ＼＼  /",
		"                          ＼＼/",
		"                           ＼/"
		};

		for (int i = 0; i < 10; i++)
		{
			CursorP(32, 6 + i);
			cout << KNOCKDOWN[i];
		}

		for (int i = 0; i < 20; i++)
		{
			CursorP(49, 17 + i);
			cout << HAND[i];
		}
		

		Sleep(2500);

		system("cls");

		CursorP(0, 0); // 엔딩 화면 출력
		cout << "                                                                                       " << endl;
		cout << "                                                                                       " << endl;
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


		EndInputKey();
	}
}

void Endding::EndInputKey()
{
	CursorV(); // 커서 보이게 함

	CursorP(77, 20);
	cout << "| RESTART |";
	CursorP(77, 22);
	cout << " | EXIT |";
	CursorP(74, 26);
	cout << "Press SPACE BAR...";

	CursorP(75, 20);

	int CursorInput; // 방향키 입력 변수
	bool CursorPoint = 1; // 커서가 가리키고 있는 부분을 알려주는 변수
	bool EnddingCursor = 1; // 스패이스바 누르기 전까지 대기하는 변수


	while (EnddingCursor == 1)
	{
		CursorInput = _getch();

		if (CursorInput == 224) // 방향키 입력 시
		{
			CursorInput = _getch(); // 복합키워드 224를 제외한 숫자를 저장
		}

		if (CursorInput == UP) // REGAME을 가리킴
		{
			CursorPoint = 1;
			CursorP(75, 20);
		}
		else if (CursorInput == DOWN) // EXIT을 가리킴
		{
			CursorPoint = 0;
			CursorP(75, 22);
		}

		if (CursorInput == SPACE) // SPACE 입력
		{
			if (CursorPoint == 1) // REGAME을 가리키고 있을 경우
			{
				EnddingCursor = 0;
			}
			else if (CursorPoint == 0) // EXIT를 가리키고 있을 경우
			{
				system("cls");
				exit(0);
			}
		}
	}
}
