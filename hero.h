#pragma once
#include <easyX.h>
#include <graphics.h>
struct Hero{
	int x;
	int y;
	int life;
	int update_cnt;
	IMAGE* img;
};

void hero_init(struct Hero* h);
void hero_draw(struct Hero* h);
void hero_destory(struct Hero* h);