#include <easyx.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include "window.h"
#include "hero.h"
#include "bullet.h"
#include "enemy.h"
using namespace std;

int score = 1;

int main()
{
    initgraph(WIDTH, HEIGHT);
    BeginBatchDraw();

    Hero* temari = new Hero;
    Bullet* hero_bullets[HERO_BULLET_MAX];
    Bullet* enemy_bullets[ENEMY_BULLET_MAX];
    Enemy* enemys[ENEMY_MAX];
    hero_init(temari);
    bullet_init(hero_bullets);
    bullet_init(enemy_bullets);
    enemy_init(enemys);

    DWORD  frame_start, frame_time;
    const int FPS = 120;          
    const int FRAME_DELAY = 1000 / FPS;

    while (1) {
        frame_start = GetTickCount();

        if (GetAsyncKeyState(VK_ESCAPE)) break; // 按ESC退出
        cleardevice();
        if(score){
            hero_move(temari);
            hero_shoot(hero_bullets, temari);
            hero_bullet_move(hero_bullets);
            hero_destoryed(enemy_bullets, temari,enemys);
            enemy_create(enemys);
            enemy_move(enemys);
            enemy_shoot(enemy_bullets, enemys);
            enemy_bullet_move(enemy_bullets);
            enemy_destoryed(hero_bullets, enemys);
        }
        hero_draw(temari);
        bullet_draw(hero_bullets);
        enemy_draw(enemys);
        bullet_draw(enemy_bullets);
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        TCHAR str[50];
        wsprintf(str, _T("SCORE: %d"), score);
        outtextxy(20, 20, str);
        if (!score) {
            settextcolor(RED);
            settextstyle(60, 0, _T(""));
            outtextxy(WIDTH / 2 - 170, HEIGHT / 2 - 30, _T("GAME_OVER"));
        }


        FlushBatchDraw();

        frame_time = GetTickCount() - frame_start;
        if (frame_time < FRAME_DELAY) {
            Sleep(FRAME_DELAY - frame_time);
        }
        
    }
    hero_delete(temari);
    bullet_delete(hero_bullets);
    enemy_delete(enemys);
    closegraph();
    return 0;
}