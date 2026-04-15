#pragma once
#include <easyX.h>
#include <graphics.h>
#include "window.h"
#define BULLET_MAX 20
#define BULLET_SPEED 10
struct Bullet {
	int x;
	int y;
	int width;
	int height;
	bool show;
};
void bullet_init(struct Bullet* b[]);
void bullet_draw(struct Bullet* b[]);
void bullet_shoot(struct Bullet* b[],struct Hero* h);
void bullet_move(struct Bullet* b[]);
