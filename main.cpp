#include <easyx.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include "hero.h"
using namespace std;
int main()
{
    initgraph(600, 800);
    cleardevice();
    Hero* temari = new Hero;
    hero_init(temari);
    hero_draw(temari);
    getchar();
    hero_destory(temari);
    delete temari;
    closegraph();
    return 0;
}