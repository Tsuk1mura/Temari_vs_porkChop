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

    DWORD  frame_start, frame_time;
    const int FPS = 120;          
    const int FRAME_DELAY = 1000 / FPS;

    Hero* temari = new Hero;
    Bullet* hero_bullets[HERO_BULLET_MAX];
    Bullet* enemy_bullets[ENEMY_BULLET_MAX];
    Enemy* enemys[ENEMY_MAX];

    Hero::hero_init(temari);
    Bullet::bullet_init(hero_bullets);
    Bullet::bullet_init(enemy_bullets);
    Enemy::enemy_init(enemys);
    while (1) {
        frame_start = GetTickCount();

        if (GetAsyncKeyState(VK_ESCAPE)) break; // 按ESC退出
        cleardevice();
        if(score){
            Hero::hero_move(temari);
            Hero::hero_shoot(hero_bullets, temari);
            Bullet::hero_bullet_move(hero_bullets);
            Hero::hero_destoryed(enemy_bullets, temari,enemys);
            Enemy::enemy_create(enemys);
            Enemy::enemy_move(enemys);
            Enemy::enemy_shoot(enemy_bullets, enemys);
            Bullet::enemy_bullet_move(enemy_bullets);
            Enemy::enemy_destoryed(hero_bullets, enemys);
        }
        Hero::hero_draw(temari);
        Bullet::bullet_draw(hero_bullets);
        Enemy::enemy_draw(enemys);
        Bullet::bullet_draw(enemy_bullets);
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
    Hero::hero_delete(temari);
    Bullet::bullet_delete(hero_bullets);
    Enemy::enemy_delete(enemys);
    closegraph();
    return 0;
}