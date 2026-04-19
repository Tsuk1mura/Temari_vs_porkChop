#include <easyx.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include "window.h"
#include "hero.h"
#include "bullet.h"
#include "enemy.h"
#include "arrow.h"
using namespace std;

int score = 1;
bool game_start = false;
bool game_pause = false;
bool game_story = false;

Arrow arrow;
int main()
{
    int witch_arrow[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            witch_arrow[i][j] = 0;
        }
    }
    witch_arrow[0][0] = 1;
    witch_arrow[1][0] = 1;
    witch_arrow[2][0] = 1;
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
        static int change_cnt = 0;
        change_cnt++;
        frame_start = GetTickCount();
        cleardevice();
        if (GetAsyncKeyState('E')) {
            break;
        }
        if (!game_start) {
            cleardevice();
            
            //todo 绘制主界面
            settextcolor(WHITE);
            settextstyle(30, 0, _T("宋体"));
            outtextxy(WIDTH / 2 - 50, 200, _T("START"));
            outtextxy(WIDTH / 2 - 50, 300, _T("STORY"));
            outtextxy(WIDTH / 2 - 50, 400, _T("EXIXT"));
            //todo 选择箭头绘制
            if (witch_arrow[0][0]) {
                arrow.x = WIDTH / 2 - 85;
                arrow.y = 200;
            }
            if (witch_arrow[0][1]) {
                arrow.x = WIDTH / 2 - 85;
                arrow.y = 300;
            }
            if (witch_arrow[0][2]) {
                arrow.x = WIDTH / 2 - 85;
                arrow.y = 400;
            }
            
            if (GetAsyncKeyState(VK_UP)) {
                if (change_cnt >= 10) {
                    if (witch_arrow[0][0]) {}

                    if (witch_arrow[0][1]) {
                        witch_arrow[0][0] = 1;
                        witch_arrow[0][1] = 0;
                        witch_arrow[0][2] = 0;
                    }
                    if (witch_arrow[0][2]) {
                        witch_arrow[0][0] = 0;
                        witch_arrow[0][1] = 1;
                        witch_arrow[0][2] = 0;
                    }
                    change_cnt = 0;
                }
            }
            if (GetAsyncKeyState(VK_DOWN)) {
                if (change_cnt >= 10) {
                    if (witch_arrow[0][2]) {}

                    if (witch_arrow[0][1]) {
                        witch_arrow[0][0] = 0;
                        witch_arrow[0][1] = 0;
                        witch_arrow[0][2] = 1;
                    }
                    if (witch_arrow[0][0]) {
                        witch_arrow[0][0] = 0;
                        witch_arrow[0][1] = 1;
                        witch_arrow[0][2] = 0;
                    }
                    change_cnt = 0;
                }
            }
            if (GetAsyncKeyState(VK_SPACE)) {
                if (change_cnt >= 10) {
                    if (witch_arrow[0][0]) game_start = true;
                    if (witch_arrow[0][1]) game_story = true;
                    if (witch_arrow[0][2]) break;
                    change_cnt = 0;
                }
            }
        }

        if (game_story) {//绘制帮助界面
            cleardevice();
            if (GetAsyncKeyState(VK_ESCAPE)) {
                if (change_cnt >= 10) {
                    change_cnt = 0;
                    game_story = false;
                }
            }
            settextcolor(WHITE);
            settextstyle(20, 0, _T("宋体"));
            outtextxy(100, 200, _T("月村手毬是一名喜欢吃炸猪排的小偶像"));
            outtextxy(100, 250, _T("但是她的队友某一天给她做的居然是——"));
            outtextxy(100, 300, _T("没有炸衣的炸猪排！"));
            outtextxy(100, 350, _T("这是月村手毬所不能容忍的"));
            outtextxy(100, 400, _T("请你操控月村手毬消灭所有没有炸衣的炸猪排"));
            outtextxy(100, 500, _T("（按ESC返回主菜单）"));
        }

        if (game_pause) {
            //todo 绘制暂停界面
            if (GetAsyncKeyState(VK_ESCAPE)) {
                if (change_cnt >= 10) {
                    change_cnt = 0;
                    game_pause = false;
                }
            }
            if (game_start) {
                settextcolor(WHITE);
                settextstyle(30, 0, _T("宋体"));
                outtextxy(WIDTH / 2 - 60, 200, _T("RESTART"));
                outtextxy(WIDTH / 2 - 90, 300, _T("BACKTOMENU"));
                outtextxy(WIDTH / 2 - 50, 400, _T("EXIXT"));
                outtextxy(WIDTH / 2 - 110, 100, _T("(ESC返回战斗)"));
            }
            if (witch_arrow[1][0]) {
                arrow.x = WIDTH / 2 -125;
                arrow.y = 200;
            }
            if (witch_arrow[1][1]) {
                arrow.x = WIDTH / 2 - 125;
                arrow.y = 300;
            }
            if (witch_arrow[1][2]) {
                arrow.x = WIDTH / 2 - 125;
                arrow.y = 400;
            }

            if (GetAsyncKeyState(VK_UP)) {
                if (change_cnt >= 10) {
                    if (witch_arrow[1][0]) {}

                    if (witch_arrow[1][1]) {
                        witch_arrow[1][0] = 1;
                        witch_arrow[1][1] = 0;
                        witch_arrow[1][2] = 0;
                    }
                    if (witch_arrow[1][2]) {
                        witch_arrow[1][0] = 0;
                        witch_arrow[1][1] = 1;
                        witch_arrow[1][2] = 0;
                    }
                    change_cnt = 0;
                }
            }
            if (GetAsyncKeyState(VK_DOWN)) {
                if (change_cnt >= 10) {
                    if (witch_arrow[1][2]) {}

                    if (witch_arrow[1][1]) {
                        witch_arrow[1][0] = 0;
                        witch_arrow[1][1] = 0;
                        witch_arrow[1][2] = 1;
                    }
                    if (witch_arrow[1][0]) {
                        witch_arrow[1][0] = 0;
                        witch_arrow[1][1] = 1;
                        witch_arrow[1][2] = 0;
                    }
                    change_cnt = 0;
                }
            }
            if (GetAsyncKeyState(VK_SPACE)) {
                if (change_cnt >= 10) {
                    if (witch_arrow[1][0]) {
                        Hero::hero_init(temari);
                        Bullet::bullet_init(hero_bullets);
                        Bullet::bullet_init(enemy_bullets);
                        Enemy::enemy_init(enemys);
                        score = 1;
                        game_pause = false;
                        game_start = true;
                    }
                    if (witch_arrow[1][1]) {
                        witch_arrow[0][0] = 1;
                        Hero::hero_init(temari);
                        Bullet::bullet_init(hero_bullets);
                        Bullet::bullet_init(enemy_bullets);
                        Enemy::enemy_init(enemys);
                        score = 1;
                        game_pause = false;
                        game_start = false;
                    }
                    if (witch_arrow[1][2]) break;
                    change_cnt = 0;
                }
            }
        }

        if(score && game_start && !game_pause){//游戏运行
            if (GetAsyncKeyState(VK_ESCAPE)) {
                if (change_cnt >= 10) {
                    change_cnt = 0;
                    game_pause = true;
                }
            } // 按ESC暂停
            Hero::hero_move(temari);
            Hero::hero_shoot(hero_bullets, temari);
            Bullet::hero_bullet_move(hero_bullets);
            Hero::hero_destoryed(enemy_bullets, temari, enemys);
            Enemy::enemy_create(enemys);
            Enemy::enemy_move(enemys);
            Enemy::enemy_shoot(enemy_bullets, enemys);
            Bullet::enemy_bullet_move(enemy_bullets);
            Enemy::enemy_destoryed(hero_bullets, enemys);
        }

        if (!score) {//死亡界面
            if (game_start) {
                settextcolor(WHITE);
                settextstyle(30, 0, _T("宋体"));
                outtextxy(WIDTH / 2 - 60, 300, _T("RESTART"));
                outtextxy(WIDTH / 2 - 90, 400, _T("BACKTOMENU"));
                outtextxy(WIDTH / 2 - 50, 500, _T("EXIXT"));
                settextcolor(RED);
                settextstyle(60, 0, _T("宋体"));
                outtextxy(WIDTH / 2 - 140, HEIGHT / 2 - 250, _T("GAME_OVER"));
                settextstyle(30, 0, _T("宋体"));
            }
            if (witch_arrow[2][0]) {
                arrow.x = WIDTH / 2 - 125;
                arrow.y = 300;
            }
            if (witch_arrow[2][1]) {
                arrow.x = WIDTH / 2 - 125;
                arrow.y = 400;
            }
            if (witch_arrow[2][2]) {
                arrow.x = WIDTH / 2 - 125;
                arrow.y = 500;
            }

            if (GetAsyncKeyState(VK_UP)) {
                if (change_cnt >= 10) {
                    if (witch_arrow[2][0]) {}

                    if (witch_arrow[2][1]) {
                        witch_arrow[2][0] = 1;
                        witch_arrow[2][1] = 0;
                        witch_arrow[2][2] = 0;
                    }
                    if (witch_arrow[2][2]) {
                        witch_arrow[2][0] = 0;
                        witch_arrow[2][1] = 1;
                        witch_arrow[2][2] = 0;
                    }
                    change_cnt = 0;
                }
            }
            if (GetAsyncKeyState(VK_DOWN)) {
                if (change_cnt >= 10) {
                    if (witch_arrow[2][2]) {}

                    if (witch_arrow[2][1]) {
                        witch_arrow[2][0] = 0;
                        witch_arrow[2][1] = 0;
                        witch_arrow[2][2] = 1;
                    }
                    if (witch_arrow[2][0]) {
                        witch_arrow[2][0] = 0;
                        witch_arrow[2][1] = 1;
                        witch_arrow[2][2] = 0;
                    }
                    change_cnt = 0;
                }
            }
            if (GetAsyncKeyState(VK_SPACE)) {
                if (change_cnt >= 10) {
                    if (witch_arrow[2][0]) {
                        Hero::hero_init(temari);
                        Bullet::bullet_init(hero_bullets);
                        Bullet::bullet_init(enemy_bullets);
                        Enemy::enemy_init(enemys);
                        score = 1;
                        game_start = true;
                    }
                    if (witch_arrow[2][1]) {
                        witch_arrow[0][0] = 1;
                        Hero::hero_init(temari);
                        Bullet::bullet_init(hero_bullets);
                        Bullet::bullet_init(enemy_bullets);
                        Enemy::enemy_init(enemys);
                        score = 1;
                        game_start = false;
                    }
                    if (witch_arrow[2][2]) break;
                    change_cnt = 0;
                }
            }
        }
        if (game_start) {//绘制分数
            TCHAR str[50];
            setbkmode(TRANSPARENT);
            settextcolor(WHITE);
            wsprintf(str, _T("SCORE: %d"), score);
            outtextxy(20, 20, str);
        }

        if ((!game_start || game_pause || !score )&& !game_story)arrow_draw(arrow);
        if (game_start) {
            Hero::hero_draw(temari);
            Bullet::bullet_draw(hero_bullets);
            Enemy::enemy_draw(enemys);
            Bullet::bullet_draw(enemy_bullets);
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