#include "bullet.h"
#include "hero.h"

void bullet_init(struct Bullet* b[]) {
	for (int i = 0; i < BULLET_MAX; i++) {
		b[i] = new Bullet;
		b[i]->width = 5;
		b[i]->height = 15;
		b[i]->show = false;
	}
}
void bullet_draw(struct Bullet* b[]) {
	setfillcolor(BLUE);
	for (int i = 0; i < BULLET_MAX; i++) {
		if (b[i]->show) {
			solidrectangle(b[i]->x, b[i]->y, b[i]->x + b[i]->width, b[i]->y + b[i]->height);
		}
	}
	
}
void bullet_move(struct Bullet* b[]) {
	for (int i = 0; i < BULLET_MAX; i++) {
		if ((b[i]->y + b[i]->height < 0)){
			b[i]->show = false;
		}
		if (b[i]->show) {
			b[i]->y -= BULLET_SPEED;
		}
	}
}
void bullet_destory(struct Bullet* b[]) {
	for (int i = 0; i < BULLET_MAX; i++) {
		delete b[i];
	}
}