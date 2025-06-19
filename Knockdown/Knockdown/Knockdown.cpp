#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include "Setting.h"
#include "Mainmenu.h"
#include "GameCore.h"
#include "Member.h"

using namespace std;

int main()
{
    Setting setting;
    setting.InitialSetup(); // 초기 설정
    
    Mainmenu mainmenu;
    mainmenu.printmain();

    system("cls"); // 화면 clear
    cout << "게임이 시작되었어요." << endl;
    



    return 0;
}