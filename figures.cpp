#include <figures.h>
#include <math.h>
const double PI=acos(-1.);

Square::Square(Board* board, const int nx, const int ny, const int tp) :Figure(board, nx, ny, tp){}
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
void Square::tryToRemove() {
    for (int k = 2; k <= myboard->getSize(); ++k) {
        bool good = true;
        for (int t = 0; t <= k; ++t) {
            good &= myboard->getCell(x + k, y + t) == type &&
                    myboard->getCell(x + t, y + k) == type &&
                    myboard->getCell(x, y + t) == type &&
                    myboard->getCell(x + t, y) == type;
        }
        if (good) {
            for (int t = 0; t <= k; ++t) {
                myboard->back[x + k][y + t] = 0;
                myboard->back[x][y + t] = 0;
                myboard->back[x + t][y + k] = 0;
                myboard->back[x + t][y] = 0;
            }
        }
    }
}

Rhombus::Rhombus(Board* board, const int nx, const int ny, const int tp) :Figure(board, nx, ny, tp){}
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
void Rhombus::tryToRemove() {
    for (int k = 1; k <= myboard->getSize(); ++k) {
        bool good = true;
        for (int t = 0; t <= k; ++t) {
            good &= myboard->getCell(x + t, y + t) == type &&
                    myboard->getCell(x + t, y - t) == type &&
                    myboard->getCell(x + k + t, y + k - t) == type &&
                    myboard->getCell(x + k + t, y - k + t) == type;
        }
        if (good) {
            for (int t = 0; t <= k; ++t) {
                myboard->back[x + t][y + t] = 0;
                myboard->back[x + t][y - t] = 0;
                myboard->back[x + k + t][y + k - t] = 0;
                myboard->back[x + k + t][y - k + t] = 0;
            }
        }
    }
}

Cross::Cross(Board* board, const int nx, const int ny, const int tp, const int _xtype) :Figure(board, nx, ny, tp){xtype = _xtype;}
void Cross::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) {
    int sh = myboard->sh;
    int dx = myboard->dx;
    int dy = myboard->dy;
    painter->setBrush(myboard->getColor(type));
    QPolygon polygon;
    int N = 12;
    double dalp = PI / N + xtype * PI / 4;
    for (int i = 0; i < N; ++i) {
        polygon << QPoint(sh + dx * x + dx / 2 + (dx / 2 - sh) * cos(2 * PI / N * i + dalp) * (i % 3 == 1 ? 0.37 : 1),
                           sh + dy * y + dy / 2 + (dy / 2 - sh) * sin(2 * PI / N * i + dalp) * (i % 3 == 1 ? 0.37 : 1));
    }
    painter->drawPolygon(polygon);
    if (selected) {
        painter->drawLine(sh + dx * x, sh + dy * y + dy / 2, sh + dx * (x + 1), sh + dy * y + dy / 2);
        painter->drawLine(sh + dx * x + dx / 2, sh + dy * y, sh + dx * x + dx / 2, sh + dy * (y + 1));
    }
}
void Cross::tryToRemove() {
    int k = 0;
    if (xtype == 0) {
        for (;myboard->getCell(x - k - 1, y) == type && myboard->getCell(x + k + 1, y) == type &&
              myboard->getCell(x, y + k + 1) == type && myboard->getCell(x, y - k - 1) == type; ++k);
        if (k >= 1) {
            for (int t = 0; t <= k; ++t) {
                myboard->back[x - t][y] = 0;
                myboard->back[x + t][y] = 0;
                myboard->back[x][y - t] = 0;
                myboard->back[x][y + t] = 0;
            }
        }
    } else {
        for (;myboard->getCell(x - k - 1, y - k - 1) == type && myboard->getCell(x + k + 1, y - k - 1) == type &&
              myboard->getCell(x + k + 1, y + k + 1) == type && myboard->getCell(x - k - 1, y + k + 1) == type; ++k);
        if (k >= 1) {
            for (int t = 0; t <= k; ++t) {
                myboard->back[x - t][y - t] = 0;
                myboard->back[x + t][y - t] = 0;
                myboard->back[x - t][y + t] = 0;
                myboard->back[x + t][y + t] = 0;
            }
        }
    }
}


