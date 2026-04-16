#pragma once
#include <easyX.h>
#include <graphics.h>
#include "window.h"
#include "bullet.h"
#define ENEMY_SPEED 3
#define ENEMY_MAX 6

struct Enemy
{
	int x;
	int y;
	int width;
	int height;
	int life;
	IMAGE* img;
	bool show;
};
void enemy_init(struct Enemy* e[]);
void enemy_create(struct Enemy* e[]);
void enemy_draw(struct Enemy* e[]);
void enemy_shoot(struct Bullet* e_b[], struct Enemy* e[]);
void enemy_move(struct Enemy* e[]);
void enemy_destoryed(struct Bullet* b[], struct Enemy* e[]);
void enemy_delete(struct Enemy* e[]);