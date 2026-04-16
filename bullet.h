#pragma once
#include <easyX.h>
#include <graphics.h>
#include "window.h"
#define HERO_BULLET_MAX 20
#define ENEMY_BULLET_MAX 20
#define BULLET_SPEED 10
class Bullet {
public:
	int x;
	int y;
	int width;
	int height;
	bool show;
	static void bullet_init(Bullet* b[]);
	static void bullet_draw(Bullet* b[]);
	static void hero_bullet_move(Bullet* b[]);
	static void enemy_bullet_move(Bullet* e_b[]);
	static void bullet_delete(Bullet* b[]);
};

