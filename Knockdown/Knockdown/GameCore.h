#pragma once
#include "Setting.h"
using namespace std;

class GameCore : public Setting
{
public:
    void Init();      // ���� �ʱ�ȭ
    void Update();    // �� ������ ������Ʈ
    void Render();    // ȭ�� ���
    void Run();       // ���� ���� ����
};

