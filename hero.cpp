#include "hero.h"
void hero_init(struct Hero* h) {
	h->x = 300;
	h->y = 500;
	h->life = 5;
	h->img = new IMAGE; // EasyX 分配 IMAGE 内存
	loadimage(h->img, _T("test.png"), 30, 60);
}

void hero_draw(struct Hero* h) {
	putimage(h->x, h->y, h->img);
}

void hero_destory(struct Hero* h) {
	delete h->img;
}