#include "hero.h"



void hero_ini(struct Hero* t) {
    loadimage(t->img, _T("test.png"), 307, 600);

    // 显示图片 (坐标x=0, y=0)
    putimage(0, 0, t->img);
}
void hero_destory(struct Hero* t) {

}