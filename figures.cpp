#include <figures.h>
#include <global_objects.h>
#include<iostream>
Circle::Circle(Board* board, int nx, int ny) :Figure(board, nx, ny){type = 1;}
int Circle::getType() const {
    return 1;
}
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) {
    painter->setBrush(myboard->getColor(type));
    painter->drawEllipse(sh + dx * x, sh + dy * y, dx, dy);
    if (selected) {
        painter->drawLine(sh + dx * x, sh + dy * y + dy / 2, sh + dx * (x + 1), sh + dy * y + dy / 2);
        painter->drawLine(sh + dx * x + dx / 2, sh + dy * y, sh + dx * x + dx / 2, sh + dy * (y + 1));
    }
}


