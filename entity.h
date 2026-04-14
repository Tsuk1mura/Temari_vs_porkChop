#pragma once
#include<easyX.h>
struct Entity
{
	void (*draw)(struct Entity*);//绘制实体
	void (*update)(struct Entity*);//更新实体

	int x;
	int y;

	int width;
	int height;
};
