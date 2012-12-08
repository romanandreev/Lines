#include <figure.h>

Figure::Figure(Board* board, int nx, int ny, int tp) {
    myboard = board;
    x = nx;
    y = ny;
    type = tp;
    selected = false;
}
int Figure::getType() {
    return type;
}
void Figure::select(bool f) {
    selected = f;
}

QRectF Figure::boundingRect() const {
    //return QRect(0, 0, W, H);
    int sh = myboard->myqtapp->scene->sh;
    int dx = myboard->myqtapp->scene->dx;
    int dy = myboard->myqtapp->scene->dy;
    return QRect(sh + dx * x, sh + dy * y, sh + dx * (x + 1), sh + dy * (y + 1));
}
void Figure::moveCell(int nx, int ny) {
    x = nx;
    y = ny;
}
