#include "GameSet.h"

void GameSet::InputKey() // Ű �Է� ó��
{
    if (_kbhit())
    {
        int key = _getch();

        if (key == 'z')
        {
            player.Attack(enemy); // z ������ ���� ����
            cout << "player.hp : " << player.HP << endl; // ������
            cout << "enemy.hp : " << enemy.HP << endl; // ������
            
        }
        else if (key == 'x')
        {
            player.Dodge(); // x ������ ȸ�� ����
            cout << "DodgeCount : " << player.DodgeCount << endl; // ������
        }
    }
}

void GameSet::UpdateGame() // ���� ������Ʈ
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

void GameSet::RenderGame() // ���� ȭ�� ǥ��
{ 

}

void GameSet::RunGame() // ���� ���� ����
{
    RenderGame();

    cout << "������ ���۵Ǿ����ϴ�." << endl;
    cout << "player.hp : " << player.HP << endl;
    cout << "enemy.hp : " << enemy.HP << endl;

    while (isGameRunning == TRUE)
    {
        UpdateGame();
        RenderGame();
        InputKey();
    }

}

void GameSet::EndingGame() // ���� ����
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
