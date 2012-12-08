#include <figures.h>
#include <math.h>
const double PI=acos(-1.);
/*Circle::Circle(Board* board, int nx, int ny, int tp) :Figure(board, nx, ny, tp){}
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) {
    int sh = myboard->sh;
    int dx = myboard->dx;
    int dy = myboard->dy;

    painter->setBrush(myboard->getColor(type));
    painter->drawEllipse(sh + dx * x + sh, sh + dy * y + sh, dx - 2 * sh, dy - 2 * sh);
    if (selected) {
        painter->drawLine(sh + dx * x, sh + dy * y + dy / 2, sh + dx * (x + 1), sh + dy * y + dy / 2);
        painter->drawLine(sh + dx * x + dx / 2, sh + dy * y, sh + dx * x + dx / 2, sh + dy * (y + 1));
    }
}*/

Square::Square(Board* board, int nx, int ny, int tp) :Figure(board, nx, ny, tp){}
void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) {
    int sh = myboard->sh;
    int dx = myboard->dx;
    int dy = myboard->dy;
    painter->setBrush(myboard->getColor(type));
    painter->drawRect(sh + dx * x + sh, sh + dy * y + sh, dx - 2 * sh, dy - 2 * sh);
    painter->setBrush(QColor(255, 255, 255));
    painter->drawRect(sh + sh + dx * x + (dx - 2 * sh) / 4, sh + sh + dy * y + (dy - 2 * sh) / 4, (dx - 2 * sh) / 2, (dy - 2 * sh) / 2);
    if (selected) {
        painter->drawLine(sh + dx * x, sh + dy * y + dy / 2, sh + dx * (x + 1), sh + dy * y + dy / 2);
        painter->drawLine(sh + dx * x + dx / 2, sh + dy * y, sh + dx * x + dx / 2, sh + dy * (y + 1));
    }
}

Rhombus::Rhombus(Board* board, int nx, int ny, int tp) :Figure(board, nx, ny, tp){}
void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) {
    int sh = myboard->sh;
    int dx = myboard->dx;
    int dy = myboard->dy;
    painter->setBrush(myboard->getColor(type));
    QPolygon polygon;
    polygon.setPoints(4, sh + dx * x + sh, sh + dy * y + dy / 2, sh + dx * x + dx / 2, sh + dy * y + sh,
                         sh + dx * (x + 1) - sh, sh + dy * y + dy / 2, sh + dx * x + dx / 2, sh + dy * (y + 1) - sh);
    painter->drawPolygon(polygon);
    painter->setBrush(QColor(255, 255, 255));
    polygon.clear();
    polygon.setPoints(4, sh + dx * x + sh + dx / 4, sh + dy * y + dy / 2, sh + dx * x + dx / 2, sh + dy * y + sh + dy / 4,
                         sh + dx * (x + 1) - sh - dx / 4, sh + dy * y + dy / 2, sh + dx * x + dx / 2, sh + dy * (y + 1) - sh - dy / 4);
    painter->drawPolygon(polygon);
    if (selected) {
        painter->drawLine(sh + dx * x, sh + dy * y + dy / 2, sh + dx * (x + 1), sh + dy * y + dy / 2);
        painter->drawLine(sh + dx * x + dx / 2, sh + dy * y, sh + dx * x + dx / 2, sh + dy * (y + 1));
    }
}
/*Star::Star(Board* board, int nx, int ny, int tp) :Figure(board, nx, ny, tp){}
void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) {
    int sh = myboard->sh;
    int dx = myboard->dx;
    int dy = myboard->dy;
    painter->setBrush(myboard->getColor(type));
    QPolygon polygon;
    int N = 10;
    for (int i = 0; i < N; i++) {
        polygon << QPoint(sh + dx * x + dx / 2 + (dx / 2 - sh) * cos(2 * PI / N * i) * (i % 2 ? 0.6 : 1),
                           sh + dy * y + dy / 2 + (dy / 2 - sh) * sin(2 * PI / N * i) * (i % 2 ? 0.6 : 1));
    }
    painter->drawPolygon(polygon);
    if (selected) {
        painter->drawLine(sh + dx * x, sh + dy * y + dy / 2, sh + dx * (x + 1), sh + dy * y + dy / 2);
        painter->drawLine(sh + dx * x + dx / 2, sh + dy * y, sh + dx * x + dx / 2, sh + dy * (y + 1));
    }
}*/
Cross::Cross(Board* board, int nx, int ny, int tp, int _xtype) :Figure(board, nx, ny, tp){xtype = _xtype;}
void Cross::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) {
    int sh = myboard->sh;
    int dx = myboard->dx;
    int dy = myboard->dy;
    painter->setBrush(myboard->getColor(type));
    QPolygon polygon;
    int N = 12;
    double dalp = PI / N + xtype * PI / 4;
    for (int i = 0; i < N; i++) {
        polygon << QPoint(sh + dx * x + dx / 2 + (dx / 2 - sh) * cos(2 * PI / N * i + dalp) * (i % 3 == 1 ? 0.37 : 1),
                           sh + dy * y + dy / 2 + (dy / 2 - sh) * sin(2 * PI / N * i + dalp) * (i % 3 == 1 ? 0.37 : 1));
    }
    painter->drawPolygon(polygon);
    if (selected) {
        painter->drawLine(sh + dx * x, sh + dy * y + dy / 2, sh + dx * (x + 1), sh + dy * y + dy / 2);
        painter->drawLine(sh + dx * x + dx / 2, sh + dy * y, sh + dx * x + dx / 2, sh + dy * (y + 1));
    }
}



