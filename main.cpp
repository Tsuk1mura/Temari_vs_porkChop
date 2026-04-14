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
    hero_ini(temari);

    getchar();
    closegraph();
    return 0;
}