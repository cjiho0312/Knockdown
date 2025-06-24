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

    player.EndTired(); // 지침상태 2초 후 지침 상태 종료
    player.EndDodge(); // x키 입력 시 0.5초 후 회피 종료, 회피 성공유무 확인
    player.CheckRA(); // repeatAttack 상태 확인, 불러오기
    player.CheckRD(); // repeatDodge 상태 확인, 불러오기

    enemy.CheckECA(); // EnemyCanAttack 상태 확인, 불러오기
    
    
    if (enemy.EnemyCanAttack() == true)
    {
        enemy.PrepareAttack(); // 적의 자동 공격 준비
    }
    enemy.TryAttack(player); // 공격 준비 된 상태면 실행
    
    player.TryAttack(enemy); // z키 입력 시 0.7초 후 공격 실행

    player.SetPlayerState(); // 플레이어의 동작 0.3초 후 IDLE로 변경

    enemy.SetEnemyState(); // 적의 동작 0.3초 후 IDLE로 변경
}

void GameSet::RenderGame() // 게임 화면 표시
{

    ResetCursor(); // 매 루프마다 커서 리셋, 기존 그래픽 지우기 함수
    HpAndTimer(); // 화면 상단에 각 멤버의 HP 바, 강공격 바, 타이머 출력
    EnemyPrint(); // 적 상태에 따라 그래픽 표시
    PlayerPrint(); // 플레이어 상태에 따라 그래픽 표시
    GameText(); // 안내 텍스트 (데미지, 회피, 명중률 저하 등)
    HowToPlay(); // 게임 방법 설명 및 키 안내

    SwitchIdle(); // 0.5초마다 아이들 스위치



    /*
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
    */
    
}

void GameSet::RunGame() // 게임 메인 루프
{
    BeforeRunGame();

    system("cls"); // 화면 clear

    isBattleStart = true;
    gameStartTime = GetTickCount64(); // 게임 시작 시간 저장
    idleTime = GetTickCount64(); // 아이들 타임 첫 설정
    enemy.FirstAttack(); // 적의 첫 공격 제어 (시작하자마자 공격할 수 없도록)

    while (isGameRunning == TRUE) // 게임 루프
    {
        RenderGame();

        if (player.GetPlayerState() != 6) { InputKey(); }

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



// 아래는 출력 관련 조각 함수들



void GameSet::BeforeRunGame()
{
    // 3
    CursorP(56, 10);
    cout << "\u25A0\u25A0\u25A0" << endl;
    CursorP(56, 11);
    cout << "    \u25A0" << endl;
    CursorP(56, 12);
    cout << "\u25A0\u25A0\u25A0" << endl;
    CursorP(56, 13);
    cout << "    \u25A0" << endl;
    CursorP(56, 14);
    cout << "\u25A0\u25A0\u25A0" << endl;
    Sleep(1000);

    // 2
    CursorP(56, 10);
    cout << "\u25A0\u25A0\u25A0" << endl;
    CursorP(56, 11);
    cout << "    \u25A0" << endl;
    CursorP(56, 12);
    cout << "\u25A0\u25A0\u25A0" << endl;
    CursorP(56, 13);
    cout << "\u25A0    " << endl;
    CursorP(56, 14);
    cout << "\u25A0\u25A0\u25A0" << endl;
    Sleep(1000);

    // 1
    CursorP(56, 10);
    cout << "  \u25A0  " << endl;
    CursorP(56, 11);
    cout << "  \u25A0  " << endl;
    CursorP(56, 12);
    cout << "  \u25A0  " << endl;
    CursorP(56, 13);
    cout << "  \u25A0  " << endl;
    CursorP(56, 14);
    cout << "  \u25A0  " << endl;
    Sleep(1000);

    // GO! 추후 FIGHT로 변경
    CursorP(49, 10);
    cout << "\u25A0\u25A0\u25A0\u25A0  \u25A0\u25A0\u25A0\u25A0  \u25A0" << endl;
    CursorP(49, 11);
    cout << "\u25A0        \u25A0    \u25A0  \u25A0" << endl;
    CursorP(49, 12);
    cout << "\u25A0  \u25A0\u25A0  \u25A0    \u25A0  \u25A0" << endl;
    CursorP(49, 13);
    cout << "\u25A0    \u25A0  \u25A0    \u25A0" << endl;
    CursorP(49, 14);
    cout << "\u25A0\u25A0\u25A0\u25A0  \u25A0\u25A0\u25A0\u25A0  \u25A0" << endl;
    Sleep(1000);


}

void GameSet::ResetCursor()
{
    // 멤버 겹치는 부분 화면 리셋
    int PrintHigh = 22;
    for (int i = 0; i < PrintHigh; i++)
    {
        CursorP(50, 12 + i);
        cout << "                         " << endl; 
    }
   
    CursorP(0, 0); // 커서 초기화
    
    // 창크기 참고 : 120 / 40
}

void GameSet::HpAndTimer()
{
    timeleft = (TIMER - (GetTickCount64() - gameStartTime)) / 1000; // 타이머 출력용

    CursorP(57, 1); // '타이머'
    cout << "TIMER";

    CursorP(2, 2); // 플레이어 HP
    cout << "PLAYER [                                                                                ";
    CursorP(10, 2);
    HpBarMaker(player.GetHP());
    CursorP(50, 2);
    cout << "]";

    CursorP(7, 4); // 플레이어 (강공격) 스테미너 \u25CF, \u25CB
    cout << "SPECIAL [\u25CB\u25CB\u25CB";
    CursorP(16, 4);
    for (int i = 0; i < player.DodgeCount(); i++)
    {
        cout << "\u25CF";
    }
    CursorP(22, 4);
    cout << "]";
    

    CursorP(69, 2); // 적 HP
    cout << "[                                                                                     ";
    CursorP(70, 2);
    HpBarMaker(enemy.GetHP());
    CursorP(110, 2);
    cout << "] ENEMY";

    // CursorP(2, 6);
    // cout << "-------------------------------------------------------------------------------------------------------------------";

    CursorP(58, 2); // 타이머 출력
    cout << "<";
    if (timeleft >= 10)
    {
    cout << timeleft;
    }
    else if (timeleft < 10)
    {
    cout << " " << timeleft;
    }
    cout << ">";
}

void GameSet::PlayerPrint() //22줄
{
    CursorP(1, 12);
    switch (player.GetPlayerState())
    {
    case 0 : // IDLE 상태
        if (idleBreath == true)
        {
            
        cout << "                      ~;~-~,                       " << endl;
        cout << "                  .;;;;;;;-,)                      " << endl;
        cout << "                .;~ ;/                             " << endl;
        cout << "               !  *;/  ::,~,                       " << endl;
        cout << "               ,:   &=. _  *                       " << endl;
        cout << "                !   @@    3 @              :;-     " << endl;
        cout << "                 # ;@@.   ~@@!;;~~;;;:--  ~;   )   " << endl;
        cout << "                  !@@@~:;;@@@:    .,:;;;;~  :;     " << endl;
        cout << "                  .@@@@;~;@@@#;;;`                 " << endl;
        cout << "                   @@@@@@@@@@=                     " << endl;
        cout << "                    @@@@@@@@@-                     " << endl;
        cout << "                   @@@@@@@@@@-                     " << endl;
        cout << "              .;~;;       .-~~;:;                  " << endl;
        cout << "            ,;:.;;    ;;;,       ;#;               " << endl;
        cout << "          ;=.    ;$;;,   -;:~ ~;;:  :~;            " << endl;
        cout << "           $   ,$            ;:;:      ;;.         " << endl;
        cout << "           ,$   !:               ~:;;    ,!:       " << endl;
        cout << "            ,$   $                   :;;;  :;~     " << endl;
        cout << "              ;;  $                      ;!  -$,   " << endl;
        cout << "               .;-:!                       ;   ~;  " << endl;
        cout << "           -$;;; . #                       ,!   ~~ " << endl;
        cout << "            -;,..;;.                        ,-:;;  " << endl;

        }
        else if (idleBreath == false)
        {
        cout << "                                                   " << endl;
        cout << "                      ~;~-~,                       " << endl;
        cout << "                  .;;;;;;;-,)                      " << endl;
        cout << "                .;~ ;/                             " << endl;
        cout << "               !  *;/  ::,~,                       " << endl;
        cout << "               ,:   &=. _  *                       " << endl;
        cout << "                !   @@    3 @              :;-     " << endl;
        cout << "                 # ;@@.   ~@@!;;~~;;;:--  ~;   )   " << endl;
        cout << "                  !@@@~:;;@@@:    .,:;;;;~  :;     " << endl;
        cout << "                  .@@@@;~;@@@#;;;`                 " << endl;
        cout << "                   @@@@@@@@@@=                     " << endl;
        cout << "                    @@@@@@@@@-                     " << endl;
        cout << "                   @@@@@@@@@@-                     " << endl;
        cout << "              .;~;;       .-~~;:;                  " << endl;
        cout << "            ,;:.;;    ;;;,       ;#;               " << endl;
        cout << "          ;=.    ;$;;,   -;:~ ~;;:  :~;            " << endl;
        cout << "          $    ,$            ;:;:      ;;.         " << endl;
        cout << "           ,$    $               ``` :,,,  `,      " << endl;
        cout << "              ;;  $                      ;!  -,    " << endl;
        cout << "               .;-:!                       ;   ~;  " << endl;
        cout << "           -$;;; . #                       ,!   ~~ " << endl;
        cout << "            -;,..;;.                        ,-:;;  " << endl;
        }

        break;
    case 1 : // 공격 준비 상태
        
        cout << "                    ~;~-~,                         " << endl;
        cout << "                .;;;;;;;-,)                        " << endl;
        cout << "              .;~ ;/                               " << endl;
        cout << "              !  *;/  ::,~,                        " << endl;
        cout << "               ,:   &=._  _ *                      " << endl;
        cout << "               ;!   @@  ;:  @;;.,                  " << endl;
        cout << "                 #;;~',.   ~@@!   ),               " << endl;
        cout << "                 !!    ~:;=;     ),                " << endl;
        cout << "                  .@;  ` ``     ;;`                " << endl;
        cout << "                   @@;,     ,,;=                   " << endl;
        cout << "                    @@@,...@@-                     " << endl;
        cout << "                   @@@@@@@@@@-                     " << endl;
        cout << "              .;~;;       .-~~;);                  " << endl;
        cout << "            ,;:.;; ) ;/      ;);                   " << endl;
        cout << "          ;=.    ;$/:    ~ ;/                      " << endl;
        cout << "           $   ,$    $     (                       " << endl;
        cout << "           ,$   !:   ~:   ,!:                      " << endl;
        cout << "            ,$   $   `$ _  ;                       " << endl;
        cout << "              ;;  $    ~`    -,                    " << endl;
        cout << "               .;-:!     ` -  :``                  " << endl;
        cout << "           -$;;; . #                               " << endl;
        cout << "            -;,..;;.                               " << endl;


        break;
    case 2 : // 공격 상태

        cout << "                                                                  " << endl;
        cout << "                                                                  " << endl;
        cout << "                                                                  " << endl;
        cout << "                                      &;:,~,                      " << endl;
        cout << "                                    &=.   _*                      " << endl;
        cout << "                                    @@      3               _ -   " << endl;
        cout << "                             ,;;;;`;@@.   ~@@!;;~~;;;:--  ~;    ) " << endl;
        cout << "                     ,_,;;`````   !@@@~:;;@@@:    .,:;;;;~  :```  " << endl;
        cout << "                   `~`` ..;-``;`;;.@@@@;~;@@@#;```                " << endl;
        cout << "             ( ~ ;; ``            @@@@@@@@`                       " << endl;
        cout << "                                ~@@@@@@@@`                        " << endl;
        cout << "                              ~@@@@@@@@@                          " << endl;
        cout << "                            .;~;;  -~:;                           " << endl;
        cout << "                          ~;:.;;     ;#;                          " << endl;
        cout << "                          ;=.    ;$; ~:  ~;                       " << endl;
        cout << "                         $   ,$  ;:;:    ;;.                      " << endl;
        cout << "                      ~,$     !:   ~:;  , !:                      " << endl;
        cout << "                     ,$    $    ~:;;  ;~                          " << endl;
        cout << "                  ~ $    ;;  ~;!  -$,                             " << endl;
        cout << "                .;-:!  ?/   ~;   /~;                              " << endl;
        cout << "               -$; . ;    ~ ,!   ~                                " << endl;
        cout << "         __ -;,. ;;   ,-:;                                        " << endl;


        break;
    case 3 : // 피격 상태
        cout << "              . ;:;                                " << endl;
        cout << "            .; @-;                                 " << endl;
        cout << "           ,$  #     ;;;~;                  /      " << endl;
        cout << "           *  ,*   ;;      $~             /        " << endl;
        cout << "          ~~,-$    @: =  = $,-;~,,      /  *       " << endl;
        cout << "          ~    ;;;.@!  ``  @@-     *   *    .      " << endl;
        cout << "          ,~;:     @@@;;!!@@@;~ ,; .$    .         " << endl;
        cout << "              :;,;;@@@!   @@@@:  $  ~  .    *      " << endl;
        cout << "                   @@@@@@@@@@@   :~ ,$   .     *   " << endl;
        cout << "                   @@@@@@@@@@@    @~.@- ＼ *       " << endl;
        cout << "                    @@@@@@@@@@     .;.;   ＼ .     " << endl;
        cout << "                    #@@@@@:;;~~;!;,        ＼      " << endl;
        cout << "                   ;;:         ,# .!;              " << endl;
        cout << "                 ;=    ~!;~;;-;$    ;;             " << endl;
        cout << "                ;;;;;;$.     . ;;   -;             " << endl;
        cout << "               .=   ,!          .;~: ;             " << endl;
        cout << "               .;   :.           .=  ;! ;;         " << endl;
        cout << "                ;:  :-            ;;  :;;;#        " << endl;
        cout << "                 ;;  #.                            " << endl;
        cout << "                  @  .!                            " << endl;
        cout << "               .=;   ;*                            " << endl;
        cout << "                ;;;;~                              " << endl;
        break;
    case 4 : // 회피 상태
        cout << "                                                   " << endl;
        cout << "                                                   " << endl;
        cout << "          .:;;;;.~                                 " << endl;
        cout << "          ~   _  ;!~                               " << endl;
        cout << "          ~     3 !.                               " << endl;
        cout << "          .;   , @          . ~                    " << endl;
        cout << "        ,*;,@$~ #*;;.       ,~ ;,                  " << endl;
        cout << "        ~:   -@@@@@, ~:,;-;`  :`                   " << endl;
        cout << "       *    #@@@@@@~;,    ,,;                      " << endl;
        cout << "       =   -@@@@@@@! $;-;;                         " << endl;
        cout << "       *         ``~  ;                            " << endl;
        cout << "        $;;;;;;;;=@@@:--;;~                        " << endl;
        cout << "             @;;;;;,    ;.  ~;;,,,                 " << endl;
        cout << "            :@;- ;:,    ::  ,     !~               " << endl;
        cout << "           .#    :!;;;;;;#:- !:,,   ;:~            " << endl;
        cout << "             ,# ;;;   #            .;;   ~;;,, ,   " << endl;
        cout << "               #      #.              ;;-      ~  ~" << endl;
        cout << "               ~      # ~                  ``%;`;  " << endl;
        cout << "             @    @ ~                              " << endl;
        cout << "             @  ;.                                 " << endl;
        cout << "            @.   ;@ ~                              " << endl;
        cout << "            ;` -; ~~                               " << endl;
        break;
    case 5 : // 강공격 상태
        cout << "    *                                 ~;~-~,                      " << endl;
        cout << "                       |          .;;;;;;;-,)              ＼     " << endl;
        cout << "                     - o -      .;~ ;/                 +  ＼      " << endl;
        cout << "                       |       !     ; &;:,~,              . ＼ . " << endl;
        cout << "                               ,:    &=.   +:                 .＼ " << endl;
        cout << "          +                     !    @!      3               _ -  " << endl;
        cout << "                                 #  ;@@.   ~@@!;;~~;;;:--  ~;    )" << endl;
        cout << "                                  !@@@~:;;@@@:    .,:;;;;~  :`/` ." << endl;
        cout << "                           *      .@@@@;~;@@@#;```       .  / .   " << endl;
        cout << "      *       |                   @@@@@@@@`               /     . " << endl;
        cout << "            - o -               ~@@@@@@@@`              / /       " << endl;
        cout << "              |               ~@@@@@@@@@           +              " << endl;
        cout << "                            .;~;;  -~:;                           " << endl;
        cout << "                          ~;:.;;     ;#;                          " << endl;
        cout << "                 *        ;=.    ;$; ~:  ~;                       " << endl;
        cout << "                         $   ,$  ;:;:    ;;.                  *   " << endl;
        cout << "                      ~,$     !:   ~:;  , !:           |          " << endl;
        cout << "     +               ,$    $    ~:;;  ;~             - o -        " << endl;
        cout << "                  ~ $    ;;  ~;!  -$,                  |          " << endl;
        cout << "                .;-:!  ?/   ~;   /~;                              " << endl;
        cout << "               -$; . ;    ~ ,!   ~       +                        " << endl;
        cout << "         __ -;,. ;;   ,-:;                                        " << endl;
        break;
    case 6 : // 지침 상태
        cout << "                                                   " << endl;
        cout << "                                                   " << endl;
        cout << "                                                   " << endl;
        cout << "                                                   " << endl;
        cout << "                       ::,~,                       " << endl;
        cout << "                    &=.    *                       " << endl;
        cout << "                   @@ u _  _@                      " << endl;
        cout << "              ;;```;@@ U   ;@!;;~~,,               " << endl;
        cout << "             ;;  u!@@@~:;;@@@: u   ;,              " << endl;
        cout << "            `;&   .@@@@;~;@@@#     ;;              " << endl;
        cout << "             ;; U  @@@@@@@@@@|   u;;               " << endl;
        cout << "              !+   ,@@@@@@@@#    ;;                " << endl;
        cout << "               !   ;@@@@@@@@)  U ;                 " << endl;
        cout << "              .;   ;;.     .-;   :;                " << endl;
        cout << "            ,;:.    ;;;;;, ; ;   ;#;               " << endl;
        cout << "          ;=.  !;    ;;,   -;    .,;;: :~          " << endl;
        cout << "          $    ,$ -~           ;:;:   u  ;;.       " << endl;
        cout << "           ,$    $  U            ``` :,,,  `,      " << endl;
        cout << "              ;;  $               u      ;!  -,    " << endl;
        cout << "               .;-:!                       ;   ~;  " << endl;
        cout << "           -$;;; . #                   U   ,!   ~~ " << endl;
        cout << "            -;,..;;.                        ,-:;;  " << endl;
        break;
    case 7: // 쓰러짐 상태
        cout << "\n\n\n\n\n\n\n\n\n\n           쓰려지는 중입니다...";
        break;
    }
   
    
    
}

void GameSet::EnemyPrint()
{
    const int enemyPrintHigh = 22; // 적 출력 높이

#pragma region ASCII

    string enemyIdleAscii[enemyPrintHigh] = { // IDLE
 "                                              ",
 "                ..                            ",
 "               ``;;;;;*~                      ",
 "                ;    ;;;@                     ",
 "               ;;  / ]:;;                     ",
 "                = ;;;;,/  ``*,                ",
 "       ;;,,   ;!;;;*;    -:  =,               ",
 " .*;* (   `; /.      $     ;  @               ",
 " (  ``;;;;~;;     / ,@     ,  ;               ",
 "  `.;,,     :    ~;;~     ,  @                ",
 "       `` - ~;;*!         :  @                ",
 "               *~         ; ;                 ",
 "               ;@=@@@@@@@@@@@                 ",
 "            :@@@@@@@@@@@@@@@@                 ",
 "          .@;;#@@@@@@@@@@@@@;                 ",
 "         ;;     ;*@!!$;.;!;@                  ",
 "        =:   ;,;;$- -$ ;    @                 ",
 "         !;       -$ -$.    --                ",
 "          `;;-      @ :@=-   =                ",
 "             :;;,  !;;~     @                 ",
 "           _;;;,    =~;;;;;;;                 ",
 "         ,=;;;;;;;;;;                         "
    };

    string enemyIdle2Ascii[enemyPrintHigh] = { // IDLE2
"                                              ",
"                                              ",
"                ..                            ",
"               ``;;;;;*~                      ",
"                ;    ;;;@                     ",
"               ;;  / ]:;;                     ",
"                = ;;;;,/  ``*,                ",
"       ;;,,   ;!;;;*;    -:  =,               ",
" .*;* (   `; /.      $     ;  @               ",
" (  ``;;;;~;;     / ,@     ,  ;               ",
"  `.;,,     :    ~;;~     ,  @                ",
"       `` - ~;;*!         :  @                ",
"               *~         ; ;                 ",
"               ;@=@@@@@@@@@@@                 ",
"            :@@@@@@@@@@@@@@@@                 ",
"          .@;;#@@@@@@@@@@@@@;                 ",
"        ;;      ;*@!!$;.; ;!;@                ",
"       =:    ;,;;$- -$ ;   @                  ",
"        `;;-      @ :@=-   =                  ",
"             :;;,  !;;~     @                 ",
"           _;;;,    =~;;;;;;;                 ",
"         ,=;;;;;;;;;;                         "
    };

    string enemyR_AttackAscii[enemyPrintHigh] = { // R_ATTACK
"                                              ",
"                                              ",
"                      ..                      ",
"                     ``;;;;;*~                ",
"                      ;    ;;;@               ",
"                     ;;  / ]:;;               ",
"                       = ;;;;,/  *,           ",
"                  ,;;;;*;    -:  =,;,         ",
"           _     /.     $     ;  @ ';         ",
"         (  `;;;    / ,@     ,  ;   ;;        ",
"          ,    :    ~;;~     ,  @    ;;       ",
"           ` - ~;;*!         :@ -~ `          ",
"                *~         ; ;                ",
"                ;@=@@@@@@@@@@@                ",
"             :@@@@@@@@@@@@@@@@                ",
"          .@;;#@@@@@@@@@@@@@;                 ",
"        ;;      ;*@!!$;.; ;!;@                ",
"       =:    ;,;;$- -$ ;   @                  ",
"        `;;-      @ :@=-   =                  ",
"             :;;,  !;;~     @                 ",
"           _;;;,    =~;;;;;;;                 ",
"         ,=;;;;;;;;;;                         "
    };

    string enemyAttackAscii[enemyPrintHigh] = { // R_ATTACK
"                                                                  ",
"                                                                  ",
"                      ..                                          ",
"                     ``;;;;;*~                                    ",
"                      ;    ;;;@                                   ",
"                     ;;  / ]:;;                                   ",
".;;;.. ,.,,,,,   ,,,;; = ;;;;,/ -,                                ",
"(  !!  ``;    ;;``     ,;;;;*;    -:                              ",
" ;;.``` ;;;,  ,,      /.     $    . @                             ",
"                (  ;;;    / ,@     . ;                            ",
"                 .   :    ~;;~      , @                           ",
"                  ` - ~;;*!          : -                          ",
"                           *~         ; ;                         ",
"                            ;@=@@@@@@@@@@@                        ",
"                            :@@@@@@@@@@@@@@                       ",
"                            .@;;#@@@@@@@@@@@                      ",
"                          ;;      ;*@!!  ! ;;                     ",
"                         =:     ,;;$ #      @;                    ",
"                          `;;-      @ ;;,   `;;                   ",
"                             :;;,  !;;~   ;;!   @;                ",
"                             _;;;,    =     ,;    ;;              ",
"                           ,=;;;;;;;;;;   ;;;;;;;;                "
    };

    string enemyDamageAscii[enemyPrintHigh] = { // TAKEDAMAGE
"                                              ",
"                                              ",
"                                              ",
"                ..                            ",
"               ``;;;;;*~                      ",
"       ＼        ;x   ;;;@                    ",
"      ＼   ＼ .  ;;  / ]:;;                   ",
"         .＼ ＼  = ;;;;,/  ``*,               ",
"     .    ,,,  ;!;;;*;    -:  =,              ",
"        ( ..`; /.    $     ;   @              ",
"     ( `    ~; ,, / ,@     ,    ;             ",
"       `;,,~;;*    !        : @               ",
"        .   /  /  ! *~       ;;               ",
"      .  /   / ;@=@@@@@@@@@@@                 ",
"     /  . / :@@@@@@@@@@@@@@@@                 ",
"          .@;;#@@@@@@@@@@@@@;                 ",
"        ;;      ;*@!!$;.; ;!;@                ",
"       =:    ;,;;$- -$ ;   @                  ",
"        `;;-      @ :@=-   =                  ",
"             :;;,  !;;~     @                 ",
"           _;;;,    =~;;;;;;;                 ",
"         ,=;;;;;;;;;;                         "
    };

#pragma endregion

    CursorP(74, 12);

    switch (enemy.GetEnemyState())
    {
    case 0: // 대기 상태
        if (idleBreath == true)
        {
            for (int i = 0; i < enemyPrintHigh; i++)
            {
                CursorP(74, 12 + i);
                cout << enemyIdleAscii[i];
            }
        }
        else if (idleBreath == false)
        {
            for (int i = 0; i < enemyPrintHigh; i++)
            {
                CursorP(74, 12 + i);
                cout << enemyIdle2Ascii[i];
            }
        }
        

        break;
    case 1: // 공격 준비 상태
        for (int i = 0; i < enemyPrintHigh; i++)
        {
            CursorP(74, 12 + i);
            cout << enemyR_AttackAscii[i];
        }
        break;
    case 2: // 공격 상태
        for (int i = 0; i < enemyPrintHigh; i++)
        {
            CursorP(54, 12 + i);
            cout << enemyAttackAscii[i];
        }
        break;
    case 3: // 피격 상태
        for (int i = 0; i < enemyPrintHigh; i++)
        {
            CursorP(74, 12 + i);
            cout << enemyDamageAscii[i];
        }
        break;
    case 4: // 회피 상태
        cout << "                                        회피 중입니다...";
        break;
    case 6: // 쓰러짐 상태
        cout << "                                        쓰려지는 중입니다...";
        break;
    }
}

void GameSet::GameText()
{
    //초기화 (화면 지우기)

    if (GetTickCount64() - P_DamageTime >= 500) // 플레이어 데미지 지우기
    {
        CursorP(40, 8);
        cout << "       ";
        CursorP(40, 9);
        cout << "       ";
        CursorP(40, 10);
        cout << "       ";
    }

    if (GetTickCount64() - A_DamageTime >= 500) // 적 데미지 지우기
    {
        CursorP(75, 8);
        cout << "       ";
        CursorP(75, 9);
        cout << "       ";
        CursorP(75, 10);
        cout << "       ";
    }

    CursorP(37, 7); // 보조 text 칸 지우기
    if (player.RepeatAttack() <= 1)
    {
        cout << "                                                                   ";
    }


    //플레이어 관련 text 

    if (player.GetPlayerState() == 3) // 피격 상태일 때
    {
        
        if (player.Damage() == 0)
        {
            CursorP(40, 8);
            cout << " __ ";
            CursorP(40, 9);
            cout << "|  |";
            CursorP(40, 10);
            cout << "|__|";
        }
        else if (player.Damage() == 1)
        {
            CursorP(40, 8);
            cout << " _  ";
            CursorP(40, 9);
            cout << "  | ";
            CursorP(40, 10);
            cout << " _|_";
        }
        else if (player.Damage() == 2)
        {
            CursorP(40, 8);
            cout << " __ ";
            CursorP(40, 9);
            cout << " __|";
            CursorP(40, 10);
            cout << "|__ ";
        }
        else if (player.Damage() == 3)
        {
            CursorP(40, 8);
            cout << " __ ";
            CursorP(40, 9);
            cout << " __|";
            CursorP(40, 10);
            cout << " __|";
        }

        P_DamageTime = GetTickCount64();
    }

    if (player.GetPlayerState() == 2) // 공격 상태일 때
    {
        CursorP(37, 7);
        if (player.RepeatAttack() >= 2)
        {
            cout << "주의 : 연속 공격은 공격 명중률을 하락시킵니다!";
        }
    }

    if (player.GetPlayerState() == 6) // 지침 상태일 때
    {
        CursorP(37, 7);
        
            cout << "주의 : 빠른 연속 회피는 몸을 지치게 만듭니다! ";
        
    }

     
     
    //적 관련 text

    if (enemy.GetEnemyState() == 3) // 피격 상태일 때
    {
        if (enemy.Damage() == 0)
        {
            CursorP(75, 8);
            cout << " __ ";
            CursorP(75, 9);
            cout << "|  |";
            CursorP(75, 10);
            cout << "|__|";
        }
        else if (enemy.Damage() == 1)
        {
            CursorP(75, 8);
            cout << " _  ";
            CursorP(75, 9);
            cout << "  | ";
            CursorP(75, 10);
            cout << " _|_";
        }
        else if (enemy.Damage() == 2)
        {
            CursorP(75, 8);
            cout << " __ ";
            CursorP(75, 9);
            cout << " __|";
            CursorP(75, 10);
            cout << "|__ ";
        }
        else if (enemy.Damage() == 3)
        {
            CursorP(75, 8);
            cout << " __ ";
            CursorP(75, 9);
            cout << " __|";
            CursorP(75, 10);
            cout << " __|";
        }
        A_DamageTime = GetTickCount64();
    }


}

void GameSet::HowToPlay()
{

    CursorP(2, 37);
    cout << "--------------------------------------------------------------------------------------------------------------------";

    CursorP(33, 38);
    cout << "[Z] ATTACK       [X] DODGE       [A] SPECIAL ATTACK";
}

void GameSet::HpBarMaker(int hp)
{
    for (int i = 0; i < hp; i++)
    {
        cout << "\u25A0"; //\u25A0
    }
}

void GameSet::SwitchIdle()
{
    if (GetTickCount64() - idleTime >= 500) // idleTime 이후 0.5초 지나면
    {
        if (idleBreath == false)
        {
            idleBreath = true;
        }

        else if (idleBreath == true)
        {
            idleBreath = false;
        }

        idleTime = GetTickCount64(); // 아이들 출력 시간 저장
    }
}
