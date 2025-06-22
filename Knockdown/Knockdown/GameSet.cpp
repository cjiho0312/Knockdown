#include "GameSet.h"

void GameSet::InputKey() // Ű �Է� ó��
{
    if (_kbhit())
    {
        int key = _getch();

        if (key == 'z')
        {
            if (!player.IsPreparingAttack()) // ���� �غ����� �ƴ� �� �÷��̾ z�� ������
            {
                player.PrepareAttack(); // ���� �غ� ���� ����
            }
            
            
        }
        else if (key == 'x') // x ������
        {
            if (player.IsPreparingAttack()) // ���� ���� ����
            {
                player.CancelAttack(); // ���� �ߴ� ��
            }
            player.Dodge(); // ȸ�� ����
        }
        else if (key == 'a')
        {
            if (!player.IsPreparingAttack() && !player.IsDodging() && player.DodgeCount() >= 3)
                // ����, ȸ�� ������ �ʰ�, ȸ�� ī��Ʈ�� 3 �̻��� ���
            {
                player.AAttack(enemy);
            }
        }
    }
}

void GameSet::UpdateGame() // ���� ������Ʈ
{
    if (!player.IsAlive() || !enemy.IsAlive()) // �÷��̾�� �� �� �� �ϳ��� ������� �ʴٸ�
    {
        isGameRunning = false; // ���� ���� 
        return;
    }

    if (!isBattleStart) return; // GO! ���̸� �ƹ� �͵� ���� ����

    if (GetTickCount64() - gameStartTime >= TIMER) // Ÿ�̸� ������ ���� ����
    {
        cout << "TIME OVER" << endl;
        isGameRunning = false;
        return;
    }

    player.EndDodge(); // xŰ �Է� �� 0.5�� �� ȸ�� ����, ȸ�� �������� Ȯ��
    player.CheckRA(); // repeatAttack ���� Ȯ��, �ҷ�����
    enemy.CheckECA(); // EnemyCanAttack ���� Ȯ��, �ҷ�����
    
    if (enemy.EnemyCanAttack() == true)
    {
        enemy.PrepareAttack(); // ���� �ڵ� ���� �غ�
    }
    enemy.TryAttack(player); // ���� �غ� �� ���¸� ����
    
    player.TryAttack(enemy); // zŰ �Է� �� 0.7�� �� ���� ����
}

void GameSet::RenderGame() // ���� ȭ�� ǥ��
{
    timeleft = (TIMER - (GetTickCount64() - gameStartTime)) / 1000 ;

    if (enemy.GetHP() < 10 && onceclear) // ���Ļ���. ���� ������ �� ������.. ������
    {
        system("cls");
        onceclear = false;
    }

    CursorP(0, 0);
    cout << "========== KNOCKDOWN ==========    " << timeleft;
    cout << "\n[Player HP]: " << player.GetHP() << " | [Dodge]: " << player.DodgeCount() << "\n";
    cout << "[Enemy  HP]: " << enemy.GetHP() << "\n";
    cout << "================================\n\n";
    cout << "Z: ����   X: ȸ��\n";

    
}

void GameSet::RunGame() // ���� ���� ����
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
    gameStartTime = GetTickCount64(); // ���� ���� �ð� ����
    enemy.FirstAttack(); // ���� ù ���� ���� (�������ڸ��� ������ �� ������)

    while (isGameRunning == TRUE) // ���� ����
    {
        RenderGame();
        InputKey();
        UpdateGame();

        Sleep(30); // ���� �ӵ� ����. ȭ�� ������ ���Ͽ� ª�� ����
    }
}

void GameSet::ResultGame() // ���� �����
{
    if (player.GetHP() > enemy.GetHP())
    {
        Result = 2; // �̱�� 2
    }
    else if (player.GetHP() < enemy.GetHP())
    {
        Result = 1; // ���� 1
    }
    else
    {
        Result = 0; // ���� 0
    }
}
