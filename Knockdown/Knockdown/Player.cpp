#include "Player.h"


void Player::SetPlayerState() // ���� �� ���� �ð��� ������ IDLE ���·� ���ƿ��� �� (ȸ�� ����)
{
    if (GetPlayerState() != 6 && ChangeState() && GetTickCount64() - StateTime >= 300) // �ǰ� ���� �ƴϰ�, ���� ���� ���� �����̰�, StateTime ���� 0.3�ʰ� �����°�?
    {
        PLAYER = IDLE; // �ٽ� IDLE ���·� ����
        changeState = false; // �ݺ� ���� �� �ǰԲ�
    }
}

void Player::PrepareAttack()
{
    if (!isPreparingAttack && !isDodging) // �ߺ� ������ ���� ���� ���ǹ�, ȸ�� ������ ���� �� ���� ����
    {
        isPreparingAttack = true;
        attackStartTime = GetTickCount64(); // ���� �ð� ����

        PLAYER = R_ATTACK; // ���� �غ� ����
    }
}

void Player::TryAttack(Member& enemy)
{
    if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack�� true�̰�, 0.7�ʰ� �����°�?
    {
        Attack(enemy); // ���� ���� ����
        isPreparingAttack = false; // ���� �ʱ�ȭ

        PLAYER = ATTACK; // ���� ����
        StateTime = GetTickCount64(); // ���� ���� �ð� ����
        changeState = true;
    }
}

void Player::Attack(Member& enemy)
{
    int dam = 0; // ������ ����

    int randValue = rand() % 100; // 0~99

    if (randValue < 60) // 60% Ȯ���� 1 ������
    {
        dam = 1;
    }
    else if (randValue < 90) // 30% Ȯ���� 2 ������
    {
        dam = 2;
    }
    else // 10% Ȯ���� 0 ������
    {
        dam = 0;
    }

    enemy.TakeDamage(dam, *this);

    repeatAttack += 1; // ���� ī��Ʈ ��

    AttackTime = GetTickCount64();
}

void Player::AAttack(Member& target)
{
    isAAttack = true;

    target.TakeDamage(3, *this); // 3 ������

    dodgeCount = 0; // ȸ�� ī��Ʈ �ʱ�ȭ

    PLAYER = A_ATTACK; // ������ ����

    StateTime = GetTickCount64(); // ���� ���� �ð� ����
    changeState = true;

    isAAttack = false; // ������ ����
}

void Player::CheckRA()
{
    if (repeatAttack >= 1) // ���� ���� ������ ��
    {
        if (GetTickCount64() - AttackTime >= 2000) // ������ �� ���� 2�ʰ� �����°�?
        {
            repeatAttack = 0; // ���� ���� ���� ����
        }
    }

    if (repeatAttack >= 4) // 4ȸ �̻� ���� ���� ������ ��
    {
        Tired();
    }

}

void Player::CheckRD()
{
    if (repeatDodge >= 1) // ���� ȸ�� ������ ��
    {
        if (GetTickCount64() - DodgeTime >= 1000) // ȸ�Ǹ� �� ���� 1�ʰ� �����°�?
        {
            repeatDodge = 0; // ���� ȸ�� ���� ����
        }
    }

}

void Player::Dodge()
{
    if (!isDodging) // �ߺ� ������ ���� ���� ���ǹ�
    {
        isDodging = true;
        dodgeStartTime = GetTickCount64(); // ȸ�� ���� �ð� ���

        PLAYER = DODGE; // ȸ�� ����
    }
}

void Player::EndDodge()
{
    if (isDodging && GetTickCount64() - dodgeStartTime >= 400) // isDodging�� true�̰�, 0.4�ʰ� �����°�?
    {
        isDodging = false;
        repeatDodge += 1; // ȸ�ǹݺ� ī��Ʈ ����
        DodgeTime = GetTickCount64();


        if (repeatDodge < 3)
        {
            PLAYER = IDLE; // ȸ�� ���� �� ���̵� ����
        }
        if (repeatDodge >= 3)
        {
            Tired();
        }
    }
}

void Player::Tired()
{
    PLAYER = TIRED; // ��ħ ����
    TiredTime = GetTickCount64(); // ���� ���� �ð� ����
    dodgeCount = 0; // ȸ�� ī��Ʈ �ʱ�ȭ

    isDodging = false; // ȸ�� ���̴� �� ���
    isPreparingAttack = false; // ���� ���̴� �� ���

    repeatDodge = 0; // ����ȸ�� ī��Ʈ �ʱ�ȭ
    repeatAttack = 0; // ���Ӱ��� ī��Ʈ �ʱ�ȭ

    soTired = true;
}

void Player::EndTired()
{
    if (soTired == true && GetTickCount64() - TiredTime >= 3000) // 3�� �� ��ħ���� ��
    {
        PLAYER = IDLE; // ��� ���·� ����
        soTired = false; // �ߺ� ���
    }
}

void Player::TakeDamage(int dmg, const Member& Attacker)
{
    if (isPreparingAttack)
    {
        CancelAttack();
    }

    hp -= dmg;

    damage = dmg;

    PLAYER = GETDAMAGE; // ������ �޴� ����

    StateTime = GetTickCount64(); // ���� ���� �ð� ����
    changeState = true;

    if (hp <= 0)
    {
        hp = 0;

        PLAYER = KO; // ������ ����

        isAlive = false;
    }
}




