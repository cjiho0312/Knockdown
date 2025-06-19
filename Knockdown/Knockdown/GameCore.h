#pragma once
#include "Setting.h"
using namespace std;

class GameCore : public Setting
{
public:
    void Init();      // 변수 초기화
    void Update();    // 매 프레임 업데이트
    void Render();    // 화면 출력
    void Run();       // 메인 게임 루프
};

