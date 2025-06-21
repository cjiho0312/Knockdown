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
    }

    player.TryAttack(enemy); // zŰ �Է� �� 0.7�� �� ���� ����
    player.EndDodge(); // xŰ �Է� �� 0.5�� �� ȸ�� ����, ȸ�� �������� Ȯ��
    player.CheckRA(); // repeatAttack ���� Ȯ��, �ҷ�����
    enemy.CheckECA(); // EnemyCanAttack ���� Ȯ��, �ҷ�����
    
    if (enemy.EnemyCanAttack() == true)
    {
        enemy.PrepareAttack(); // ���� �ڵ� ���� �غ�
    }
    enemy.TryAttack(player); // ���� �غ� �� ���¸� ����
    
}

void GameSet::RenderGame() // ���� ȭ�� ǥ��
{
    if (enemy.GetHP() < 10 && onceclear) // ���Ļ���
    {
        system("cls");
        onceclear = false;
    }

    CursorP(0, 0);
    cout << "========== KNOCKDOWN ==========\n";
    cout << "[Player HP]: " << player.GetHP() << " | [Dodge]: " << player.DodgeCount() << "\n";
    cout << "[Enemy  HP]: " << enemy.GetHP() << "\n";
    cout << "================================\n\n";
    cout << "Z: ����   X: ȸ��\n";

    
}

void GameSet::RunGame() // ���� ���� ����
{
    while (isGameRunning == TRUE)
    {
        RenderGame();
        InputKey();
        UpdateGame();

        
        Sleep(30); // ���� �ӵ� ����. ȭ�� ������ ���Ͽ� ª�� ����
    }

}

void GameSet::EndingGame() // ���� ����
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
