#pragma once
#include<easyX.h>
struct Entity
{
	void (*draw)(struct Entity*);//»æÖÆ
	void (*update)(struct Entity*);//¸üĞÂ

	int x;
	int y;

	int width;
	int height;
};
