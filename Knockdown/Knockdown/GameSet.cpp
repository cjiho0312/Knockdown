#include "GameSet.h"

void GameSet::InputKey() // 키 입력 처리
{
    if (_kbhit())
    {
        int key = _getch();

        if (key == 'z')
        {
            player.Attack(enemy); // z 누르면 공격 실행
            cout << "player.hp : " << player.HP << endl; // 디버깅용
            cout << "enemy.hp : " << enemy.HP << endl; // 디버깅용
            
        }
        else if (key == 'x')
        {
            player.Dodge(); // x 누르면 회피 실행
            cout << "DodgeCount : " << player.DodgeCount << endl; // 디버깅용
        }
    }
}

void GameSet::UpdateGame() // 게임 업데이트
{
    if (player.HP <= 0)
    {
        isGameRunning = FALSE;
    }
    else if (enemy.HP <= 0)
    {
        isGameRunning = FALSE;
    }
}

void GameSet::RenderGame() // 게임 화면 표시
{ 

}

void GameSet::RunGame() // 게임 메인 루프
{
    RenderGame();

    cout << "게임이 시작되었습니다." << endl;
    cout << "player.hp : " << player.HP << endl;
    cout << "enemy.hp : " << enemy.HP << endl;

    while (isGameRunning == TRUE)
    {
        UpdateGame();
        RenderGame();
        InputKey();
    }

}

void GameSet::EndingGame() // 게임 엔딩
{
    if (player.isAlive == TRUE)
    {
        cout << "Player Win!" << endl;
        exit(0);
    }
    else if (player.isAlive == FALSE)
    {
        cout << "Player Loose..." << endl;
        exit(0);
    }
}
