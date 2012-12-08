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
    int sh = myboard->sh;
    int dx = myboard->dx;
    int dy = myboard->dy;
    return QRect(sh + dx * x, sh + dy * y, sh + dx * (x + 1), sh + dy * (y + 1));
}
void Figure::moveCell(int nx, int ny) {
    x = nx;
    y = ny;
}
