#pragma once
#include <easyX.h>
#include <graphics.h>
#include "window.h"
#define HERO_BULLET_MAX 20
#define ENEMY_BULLET_MAX 20
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
void hero_bullet_move(struct Bullet* b[]);
void enemy_bullet_move(struct Bullet* e_b[]);
void bullet_delete(struct Bullet* b[]);
