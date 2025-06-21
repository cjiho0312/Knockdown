#include "Player.h"


void Player::Attack(Member& enemy)
{
    int damage = 0; // ������ ����

    int randValue = rand() % 100; // 0~99

    if (randValue < 60) // 60% Ȯ���� 1 ������
    {
        damage = 1;
    }
    else if (randValue < 90) // 30% Ȯ���� 2 ������
    {
        damage = 2;
    }
    else // 10% Ȯ���� 0 ������
    {
        damage = 0;
    }

    cout << damage << "��ŭ �������� �������ϴ�." << endl;

    enemy.TakeDamage(damage, *this);

    repeatAttack += 1; // ���� ī��Ʈ ��
    AttackTime = GetTickCount64();
}

void Player::CheckRA()
{
    if (repeatAttack >= 2) // ���� ���� ������ ��
    {
        if (GetTickCount64() - AttackTime >= 3000) // ������ �� ���� 3�ʰ� �����°�?
        {
            repeatAttack = 0; // ���� ���� ���� ����
            cout << "���� ���� ���� ����.." << endl;
        }
    }
}

void Player::Dodge()
{
    if (!isDodging) // �ߺ� ������ ���� ���� ���ǹ�
    {
        isDodging = true;
        dodgeStartTime = GetTickCount64();
	    cout << "(ȸ�� ��)" << endl;
    }
}

void Player::EndDodge()
{
    if (isDodging && GetTickCount64() - dodgeStartTime >= 500) // isDodging�� true�̰�, 0.5�ʰ� �����°�?
    {
        cout << "(ȸ�� ����)" << endl;
        isDodging = false;
    }
}

void Player::TakeDamage(int dmg, const Member& Attacker)
{
    if (isPreparingAttack)
    {
        CancelAttack();
        cout << "���� �� �ǰ�! �ߴܵǾ����ϴ�." << endl;

    }

    hp -= dmg;

    if (hp <= 0)
    {
        hp = 0;
        cout << "�׾����ϴ�!" << endl;
        isAlive = false;
    }
}



