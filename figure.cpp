#include <figure.h>

Figure::Figure(Board* board, const int nx, const int ny, const int tp) {
    myboard = board;
    x = nx;
    y = ny;
    type = tp;
    selected = false;
}
Figure::Figure(const Figure& f) {
    type = f.type;
    x = f.x;
    y = f.y;
    selected = f.selected;
    myboard = f.myboard;
}
Figure& Figure::operator = (const Figure& f) {
    type = f.type;
    x = f.x;
    y = f.y;
    selected = f.selected;
    myboard = f.myboard;
    return *this;
}

int Figure::getType() const {
    return type;
}
void Figure::select(const bool f) {
    selected = f;
}
QRectF Figure::boundingRect() const {
    int sh = myboard->sh;
    int dx = myboard->dx;
    int dy = myboard->dy;
    return QRect(sh + dx * x, sh + dy * y, sh + dx * (x + 1), sh + dy * (y + 1));
}
void Figure::moveCell(const int nx, const int ny) {
    x = nx;
    y = ny;
}
Figure* Figure::Copy() {
    return new Figure(*this);
}
