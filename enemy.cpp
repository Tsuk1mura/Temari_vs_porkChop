#include "enemy.h"
extern int score;
void enemy_init(struct Enemy* e[]) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		e[i] = new Enemy;
		//先不初始化x,y,等绘制的时候取随机值
		e[i]->width = 80;
		e[i]->height = 60;
		e[i]->life = 1;
		e[i]->img = new IMAGE;
		loadimage(e[i]->img, _T("enemy.png"), e[i]->width, e[i]->height);
		e[i]->show = false;
	}
}
void enemy_create(struct Enemy* e[]) {
	static int enemy_cnt = 0;
	enemy_cnt++;
	if (enemy_cnt % 70 == 0) {
		for (int i = 0; i < ENEMY_MAX; i++) {
			if (!e[i]->show) {
				e[i]->x = rand() % (WIDTH - e[i]->width);
				e[i]->y = -e[i]->height;
				e[i]->show = true;
				enemy_cnt = 0;
				break;
			}
		}
	}
}
void enemy_draw(struct Enemy* e[]) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (e[i]->show) {
			putimage(e[i]->x, e[i]->y, e[i]->img);
		}
	}
}
void enemy_shoot(struct Bullet* e_b[], struct Enemy* e[]) {//todo 实现敌人不同时发射子弹
	static int enemy_bullet_cnt = 0;
	enemy_bullet_cnt++;
	if (enemy_bullet_cnt % 60 == 0) {
		for (int i = 0; i < ENEMY_MAX; i++) {
			if (e[i]->show) {
				for (int j = 0; j < ENEMY_BULLET_MAX; j++) {
					if (!e_b[j]->show) {
						e_b[j]->x = e[i]->x + e[i]->width / 2 - e_b[j]->width / 2;
						e_b[j]->y = e[i]->y +e[i]->height + e_b[j]->height;
						e_b[j]->show = true;
						enemy_bullet_cnt = 0;
						break;
					}
				}
			}
		}
	}
}
void enemy_move(struct Enemy* e[]) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (e[i]->y > HEIGHT) {
			e[i]->show = false;
		}
		if (e[i]->show) {
			e[i]->y += ENEMY_SPEED;
		}
	}
}
void enemy_destoryed(struct Bullet* b[], struct Enemy* e[]) {
	for (int i = 0; i < HERO_BULLET_MAX; i++) {
		if (b[i]->show) {
			for (int j = 0; j < ENEMY_MAX; j++) {
				if (e[j]->show) {

					if (b[i]->x + b[i]->width > e[j]->x && 
						b[i]->x < e[j]->x + e[j]->width &&
						b[i]->y + b[i]->height > e[j]->y &&
						b[i]->y < e[j]->y + e[j]->height) {
						b[i]->show = false;
						e[j]->show = false;
						score += 1;
					}
				}
			}
		}
	}
}
void enemy_delete(struct Enemy* e[]) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		delete e[i]->img;
		delete e[i];
	}
}