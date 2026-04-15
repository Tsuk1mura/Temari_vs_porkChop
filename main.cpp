#include <easyx.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include "window.h"
#include "hero.h"
using namespace std;
int main()
{
    initgraph(WIDTH, HEIGHT);
    Hero* temari = new Hero;
    hero_init(temari);
    while (1) {
        if (GetAsyncKeyState(VK_ESCAPE)) break; // 按ESC退出
        cleardevice();
        hero_move(temari);
        hero_draw(temari);
        FlushBatchDraw();
        Sleep(5);
        
    }
    hero_destory(temari);
    delete temari;
    closegraph();
    return 0;
}