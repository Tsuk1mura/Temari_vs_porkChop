#include <easyx.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include "window.h"
#include "hero.h"
#include "bullet.h"
#include "enemy.h"
using namespace std;

int score = 0;

int main()
{
    initgraph(WIDTH, HEIGHT);
    BeginBatchDraw();

    Hero* temari = new Hero;
    Bullet* bullets[BULLET_MAX];
    Enemy* enemys[ENEMY_MAX];
    hero_init(temari);
    bullet_init(bullets);
    enemy_init(enemys);

    DWORD  frame_start, frame_time;
    const int FPS = 120;          // 固定60帧
    const int FRAME_DELAY = 1000 / FPS;

    while (1) {
        frame_start = GetTickCount();

        if (GetAsyncKeyState(VK_ESCAPE)) break; // 按ESC退出
        cleardevice();

        hero_move(temari);
        hero_shoot(bullets, temari);
        bullet_move(bullets);
        hero_draw(temari);
        bullet_draw(bullets);
        enemy_create(enemys);
        enemy_move(enemys);
        enemy_crush_bullet(bullets,enemys);
        enemy_draw(enemys);
       
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        TCHAR str[50];
        wsprintf(str, _T("SCORE: %d"), score);
        outtextxy(20, 20, str);
        FlushBatchDraw();

        frame_time = GetTickCount() - frame_start;
        if (frame_time < FRAME_DELAY) {
            Sleep(FRAME_DELAY - frame_time);
        }
    }
    hero_destory(temari);
    delete temari;
    bullet_destory(bullets);
    enemy_destory(enemys);
    closegraph();
    return 0;
}