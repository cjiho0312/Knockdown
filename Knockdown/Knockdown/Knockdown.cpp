#include <iostream>

#include "Setting.h"
#include "Mainmenu.h"
#include "GameSet.h"
#include "Member.h"

using namespace std;

int main()
{
    Setting setting;
    setting.InitialSetup(); // 초기 설정
    
    Mainmenu mainmenu;
    mainmenu.printmain();

    system("cls"); // 화면 clear

    GameSet gameset;
    gameset.RunGame();
    
    gameset.EndingGame();
    

    return 0;
}