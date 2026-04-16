#include "hero.h"
extern int score;
void Hero::hero_init(Hero* h)
{
	h->x = 270;
	h->y = 500;
	h->width = 60;
	h->height = 60;
	h->life = 5;
	h->img = new IMAGE;
	loadimage(h->img, _T("test.jpg"), h->width, h->height);
}

void Hero::hero_draw(Hero* h)
{
	putimage(h->x, h->y, h->img);
}

void Hero::hero_move(Hero* h)
{
	if (GetAsyncKeyState('A') && h->x > 0) {
		h->x -= PLANE_SPEED;
	}
	if (GetAsyncKeyState('D') && h->x < WIDTH - h->width) {
		h->x += PLANE_SPEED;
	}
	if (GetAsyncKeyState('W') && h->y > 0) {
		h->y -= PLANE_SPEED;
	}
	if (GetAsyncKeyState('S') && h->y < HEIGHT - h->height) {
		h->y += PLANE_SPEED;
	}
}

void Hero::hero_shoot(Bullet* b[], Hero* h)
{
	static int hero_bullet_cnt = 0;
	hero_bullet_cnt++;
	if (GetAsyncKeyState(VK_SPACE) && hero_bullet_cnt >= 20) {
		for (int i = 0; i < HERO_BULLET_MAX; i++) {
			if (!b[i]->show) {
				b[i]->x = h->x + h->width / 2 - b[i]->width / 2;
				b[i]->y = h->y - b[i]->height;
				b[i]->show = true;
				hero_bullet_cnt = 0;
				break;
			}
		}
	}
}

void Hero::hero_destoryed(Bullet* e_b[], Hero* h, Enemy* e[])
{
	for (int i = 0; i < ENEMY_BULLET_MAX; i++) {
		if (e_b[i]->show) {
			if (score) {
				if (e_b[i]->x + e_b[i]->width > h->x &&
					e_b[i]->x < h->x + h->width &&
					e_b[i]->y + e_b[i]->height > h->y &&
					e_b[i]->y < h->y + h->height) {
					e_b[i]->show = false;
					score -= 1;
				}
			}
		}
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (e[i]->show) {
			if (score) {
				if (e[i]->x + e[i]->width > h->x &&
					e[i]->x < h->x + h->width &&
					e[i]->y + e[i]->height > h->y &&
					e[i]->y < h->y + h->height) {
					e[i]->show = false;
					score -= 1;
				}
			}
		}
	}
}

void Hero::hero_delete(Hero* h)
{
	delete h->img;
	delete h;
}
