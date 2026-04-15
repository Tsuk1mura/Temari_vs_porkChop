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