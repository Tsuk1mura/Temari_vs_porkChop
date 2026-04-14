#pragma once
#include "entity.h"

struct Hero
{
	Entity base_info;
	IMAGE* img;
	int life;
	int update_cnt;
};

void hero_ini(struct Hero* t);
void hero_destory(struct Hero* t);
