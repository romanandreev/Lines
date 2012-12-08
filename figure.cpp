#include <figure.h>
#include <global_objects.h>

Figure::Figure(Board* board, int nx, int ny) {
    myboard = board;
    x = nx;
    y = ny;
    selected = false;
}
QRectF Figure::boundingRect() const {
    //return QRect(0, 0, W, H);
    return QRect(sh + dx * x, sh + dy * y, sh + dx * (x + 1), sh + dy * (y + 1));
}
void Figure::moveCell(int nx, int ny) {
    x = nx;
    y = ny;
}
