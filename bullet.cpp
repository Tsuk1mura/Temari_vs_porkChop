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
void bullet_shoot(struct Bullet* b[],struct Hero* h) {
	static int cnt = 0;
	cnt++;
	if (GetAsyncKeyState(VK_SPACE) && cnt >= 20) {
		for (int i = 0; i < BULLET_MAX; i++) {
			if (!b[i]->show) {
				b[i]->x = h->x + h->width / 2 - b[i]->width / 2;
				b[i]->y = h->y - b[i]->height;
				b[i]->show = true;
				cnt = 0;
				break;
			}
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