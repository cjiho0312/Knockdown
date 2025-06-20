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
    }
}

void GameSet::UpdateGame() // ���� ������Ʈ
{
    if (!player.IsAlive() || !enemy.IsAlive()) // �÷��̾�� �� �� �� �ϳ��� ������� �ʴٸ�
    {
        isGameRunning = false; // ���� ����
    }
}

void GameSet::RenderGame() // ���� ȭ�� ǥ��
{ 
    CursorP(0, 0);

    cout << "========== KNOCKDOWN ==========\n";
    cout << "[Player HP]: " << player.GetHP() << " | [Dodge]: " << player.GetDodgeCount() << "\n";
    cout << "[Enemy  HP]: " << enemy.GetHP() << "\n";
    cout << "================================\n\n";
    cout << "Z: ����   X: ȸ��\n";
}

void GameSet::RunGame() // ���� ���� ����
{
    while (isGameRunning == TRUE)
    {
        UpdateGame();
        RenderGame();
        InputKey();

        player.TryAttack(enemy); // zŰ �Է� �� 0.7�� �� ���� ����
        player.EndDodge(); // xŰ �Է� �� 0.5�� �� ȸ�� ����, ȸ�� �������� Ȯ��

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
