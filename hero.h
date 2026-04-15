#pragma once
#include <easyX.h>
#include <graphics.h>
#include "window.h"
#define PLANE_SPEED 6
struct Hero{
	int x;
	int y;
	int width;
	int height;
	int life;
	int update_cnt;
	IMAGE* img;
};

void hero_init(struct Hero* h);
void hero_draw(struct Hero* h);
void hero_destory(struct Hero* h);
void hero_move(struct Hero* h);