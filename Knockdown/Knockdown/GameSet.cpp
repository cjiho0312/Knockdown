#include "GameSet.h"

void GameSet::InputKey() // 키 입력 처리
{
    if (_kbhit())
    {
        int key = _getch();

        if (key == 'z')
        {
            if (!player.IsPreparingAttack()) // 공격 준비동작이 아닐 때 플레이어가 z를 누르면
            {
                player.PrepareAttack(); // 공격 준비 동작 시작
            }
            
            
        }
        else if (key == 'x') // x 누르면
        {
            if (player.IsPreparingAttack()) // 공격 중일 때는
            {
                player.CancelAttack(); // 공격 중단 후
            }
            player.Dodge(); // 회피 실행
        }
    }
}

void GameSet::UpdateGame() // 게임 업데이트
{
    if (!player.IsAlive() || !enemy.IsAlive()) // 플레이어와 적 둘 중 하나라도 살아있지 않다면
    {
        isGameRunning = false; // 게임 종료
    }
}

void GameSet::RenderGame() // 게임 화면 표시
{ 
    CursorP(0, 0);

    cout << "========== KNOCKDOWN ==========\n";
    cout << "[Player HP]: " << player.GetHP() << " | [Dodge]: " << player.GetDodgeCount() << "\n";
    cout << "[Enemy  HP]: " << enemy.GetHP() << "\n";
    cout << "================================\n\n";
    cout << "Z: 공격   X: 회피\n";
}

void GameSet::RunGame() // 게임 메인 루프
{
    while (isGameRunning == TRUE)
    {
        UpdateGame();
        RenderGame();
        InputKey();

        player.TryAttack(enemy); // z키 입력 시 0.7초 후 공격 실행
        player.EndDodge(); // x키 입력 시 0.5초 후 회피 종료, 회피 성공유무 확인

        Sleep(30); // 루프 속도 제한. 화면 깜빡임 보완용 짧은 지연
    }

}

void GameSet::EndingGame() // 게임 엔딩
{
    if (player.IsAlive() == TRUE)
    {
        cout << "Player Win!" << endl;
        exit(0); 
    }
    else if (player.IsAlive() == FALSE)
    {
        cout << "Player Loose..." << endl;
        exit(0);
    }
}
