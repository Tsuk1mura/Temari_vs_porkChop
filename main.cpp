#include <easyx.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include "window.h"
#include "hero.h"
#include "bullet.h"
using namespace std;

int main()
{
    initgraph(WIDTH, HEIGHT);
    BeginBatchDraw();

    Hero* temari = new Hero;
    Bullet* bullets[BULLET_MAX];
    hero_init(temari);
    bullet_init(bullets);

    DWORD  frame_start, frame_time;
    const int FPS = 120;          // 固定60帧
    const int FRAME_DELAY = 1000 / FPS;

    while (1) {
        frame_start = GetTickCount();

        if (GetAsyncKeyState(VK_ESCAPE)) break; // 按ESC退出
        cleardevice();

        hero_move(temari);
        bullet_shoot(bullets, temari);
        bullet_move(bullets);
        hero_draw(temari);
        bullet_draw(bullets);
        FlushBatchDraw();

        frame_time = GetTickCount() - frame_start;
        if (frame_time < FRAME_DELAY) {
            Sleep(FRAME_DELAY - frame_time);
        }
    }
    hero_destory(temari);
    delete temari;
    closegraph();
    return 0;
}