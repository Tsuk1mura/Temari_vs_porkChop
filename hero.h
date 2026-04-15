#pragma once
#include <easyX.h>
#include <graphics.h>
#include "window.h"
#include "bullet.h"
#define PLANE_SPEED 6
struct Hero{
	int x;
	int y;
	int width;
	int height;
	int life;
	IMAGE* img;
};

void hero_init(struct Hero* h);
void hero_draw(struct Hero* h);
void hero_destory(struct Hero* h);
void hero_move(struct Hero* h);
void hero_shoot(struct Bullet* b[], struct Hero* h);