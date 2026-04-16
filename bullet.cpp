#include "bullet.h"
#include "hero.h"

void Bullet::bullet_init(Bullet* b[])
{
	for (int i = 0; i < HERO_BULLET_MAX; i++) {
		b[i] = new Bullet;
		b[i]->width = 5;
		b[i]->height = 15;
		b[i]->show = false;
	}
}
void Bullet::bullet_draw(Bullet* b[])
{
	setfillcolor(BLUE);
	for (int i = 0; i < HERO_BULLET_MAX; i++) {
		if (b[i]->show) {
			solidrectangle(b[i]->x, b[i]->y, b[i]->x + b[i]->width, b[i]->y + b[i]->height);
		}
	}
}

void Bullet::hero_bullet_move(Bullet* b[])
{
	for (int i = 0; i < HERO_BULLET_MAX; i++) {
		if ((b[i]->y + b[i]->height < 0)) {
			b[i]->show = false;
		}
		if (b[i]->show) {
			b[i]->y -= BULLET_SPEED;
		}
	}
}

void Bullet::enemy_bullet_move(Bullet* e_b[])
{
	for (int i = 0; i < ENEMY_BULLET_MAX; i++) {
		if ((e_b[i]->y + e_b[i]->height > HEIGHT)) {
			e_b[i]->show = false;
		}
		if (e_b[i]->show) {
			e_b[i]->y += BULLET_SPEED;
		}
	}
}

void Bullet::bullet_delete(Bullet* b[])
{
	for (int i = 0; i < HERO_BULLET_MAX; i++) {
		delete b[i];
	}
}
