﻿#include <iostream>
#include "Setting.h"
#include "Mainmenu.h"
#include "GameSet.h"
#include "Member.h"
#include "Endding.h"

using namespace std;

int main()
{
    Setting setting;
    setting.InitialSetup(); // 초기 설정

    Mainmenu mainmenu;
    mainmenu.printmain(); // 메인화면


    while (true)
    {
    system("cls"); // 화면 clear
    setting.CursorH(); // 커서 숨기기

    GameSet gameset;
    gameset.HowToPlayScreen(); // 게임 방법 설명
    gameset.RunGame(); // 게임 실행

    Endding endding(gameset);
    endding.printEndding(); // 엔딩화면
    }

    return 0;
}