#include "arrow.h"

void arrow_draw(struct Arrow &a) {
	settextcolor(WHITE);
	settextstyle(30, 0, _T("宋体"));
	outtextxy(a.x, a.y, _T(">>"));
}