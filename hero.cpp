#include "hero.h"
void hero_init(struct Hero* h) {
	h->x = 270;
	h->y = 500;
    h->width = 60;
    h->height = 60;
	h->life = 5;
	h->img = new IMAGE;
	loadimage(h->img, _T("test.jpg"),h->width,h->height);
}

void hero_draw(struct Hero* h) {
	putimage(h->x, h->y, h->img);
}

void hero_destory(struct Hero* h) {
	delete h->img;
}

void hero_move(struct Hero* h) {
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
void hero_shoot(struct Bullet* b[], struct Hero* h) {
	static int hero_bullet_cnt = 0;
	hero_bullet_cnt++;
	if (GetAsyncKeyState(VK_SPACE) && hero_bullet_cnt >= 20) {
		for (int i = 0; i < BULLET_MAX; i++) {
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