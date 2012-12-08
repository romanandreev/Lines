#ifndef FIGURES_H
#define FIGURES_H
#include <board.h>
#include <figure.h>
class Circle : public Figure {
    Q_OBJECT
    public:
        Circle(Board* board, int nx, int ny);
        int getType() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

};
#endif // FIGURES_H
