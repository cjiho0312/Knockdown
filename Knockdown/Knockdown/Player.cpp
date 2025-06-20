#include "Player.h"


void Player::PrepareAttack()
{
    if (!isPreparingAttack && !isDodging) // �ߺ� ������ ���� ���� ���ǹ�, ȸ�� ������ ���� �� ���� ����
    {
        isPreparingAttack = true;
        attackStartTime = GetTickCount64(); // ���� �ð� ����
        cout << "�÷��̾ ���� ��� �÷Ƚ��ϴ�... (���� �غ� ��)" << endl;
    }
}

void Player::TryAttack(Member& enemy)
{
    if (isPreparingAttack && GetTickCount64() - attackStartTime >= 700) // isPreparingAttack�� true�̰�, 0.7�ʰ� �����°�?
    { 
        cout << "�� ������ ����˴ϴ�!\n";
        Attack(enemy); // ���� ���� ����
        isPreparingAttack = false; // ���� �ʱ�ȭ
    }
}

void Player::CancelAttack()
{
    isPreparingAttack = false;
}

void Player::Dodge()
{
    if (!isDodging) // �ߺ� ������ ���� ���� ���ǹ�
    {
        isDodging = true;
        dodgeStartTime = GetTickCount64();
	    cout << "ȸ�� ��..." << endl;
    }
}

void Player::EndDodge()
{
    if (isDodging && GetTickCount64() - dodgeStartTime >= 500) // isDodging�� true�̰�, 0.5�ʰ� �����°�?
    {
        if (successDodge) // ȸ�� ���� �Ǵ� ��
           {
           IncreaseDodge(); // ȸ�� ī��Ʈ +1
           cout << "ȸ�� ����" << endl;
           successDodge = false;
           }
        
           cout << "ȸ�� ����" << endl;
           isDodging = false;
    }
}

void Player::TakeDamage(int dmg)
{
    if (isPreparingAttack)
    {
        CancelAttack();
        cout << "���� �� �ǰ�! �ߴܵǾ����ϴ�." << endl;
    }
}



