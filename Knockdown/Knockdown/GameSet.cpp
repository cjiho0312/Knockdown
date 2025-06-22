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
        else if (key == 'a')
        {
            if (!player.IsPreparingAttack() && !player.IsDodging() && player.DodgeCount() >= 3)
                // 공격, 회피 중이지 않고, 회피 카운트가 3 이상일 경우
            {
                player.AAttack(enemy);
            }
        }
    }
}

void GameSet::UpdateGame() // 게임 업데이트
{
    if (!player.IsAlive() || !enemy.IsAlive()) // 플레이어와 적 둘 중 하나라도 살아있지 않다면
    {
        isGameRunning = false; // 게임 종료 
        return;
    }

    if (!isBattleStart) return; // GO! 전이면 아무 것도 하지 않음

    if (GetTickCount64() - gameStartTime >= TIMER) // 타이머 끝나면 게임 종료
    {
        cout << "TIME OVER" << endl;
        isGameRunning = false;
        return;
    }

    player.EndDodge(); // x키 입력 시 0.5초 후 회피 종료, 회피 성공유무 확인
    player.CheckRA(); // repeatAttack 상태 확인, 불러오기
    enemy.CheckECA(); // EnemyCanAttack 상태 확인, 불러오기
    
    if (enemy.EnemyCanAttack() == true)
    {
        enemy.PrepareAttack(); // 적의 자동 공격 준비
    }
    enemy.TryAttack(player); // 공격 준비 된 상태면 실행
    
    player.TryAttack(enemy); // z키 입력 시 0.7초 후 공격 실행
}

void GameSet::RenderGame() // 게임 화면 표시
{
    timeleft = (TIMER - (GetTickCount64() - gameStartTime)) / 1000 ;

    if (enemy.GetHP() < 10 && onceclear) // 추후삭제. 남은 뎀지가 안 보여서.. 디버깅용
    {
        system("cls");
        onceclear = false;
    }

    CursorP(0, 0);
    cout << "========== KNOCKDOWN ==========    " << timeleft;
    cout << "\n[Player HP]: " << player.GetHP() << " | [Dodge]: " << player.DodgeCount() << "\n";
    cout << "[Enemy  HP]: " << enemy.GetHP() << "\n";
    cout << "================================\n\n";
    cout << "Z: 공격   X: 회피\n";

    
}

void GameSet::RunGame() // 게임 메인 루프
{
    cout << "3" << endl;
    Sleep(1000);
    cout << "2" << endl;
    Sleep(1000);
    cout << "1" << endl;
    Sleep(1000);
    cout << "GO!" << endl;
    Sleep(1000);
    
    isBattleStart = true;
    gameStartTime = GetTickCount64(); // 게임 시작 시간 저장
    enemy.FirstAttack(); // 적의 첫 공격 제어 (시작하자마자 공격할 수 없도록)

    while (isGameRunning == TRUE) // 게임 루프
    {
        RenderGame();
        InputKey();
        UpdateGame();

        Sleep(30); // 루프 속도 제한. 화면 깜빡임 보완용 짧은 지연
    }
}

void GameSet::ResultGame() // 게임 결과값
{
    if (player.GetHP() > enemy.GetHP())
    {
        Result = 2; // 이기면 2
    }
    else if (player.GetHP() < enemy.GetHP())
    {
        Result = 1; // 지면 1
    }
    else
    {
        Result = 0; // 비기면 0
    }
}
