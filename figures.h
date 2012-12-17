#ifndef FIGURES_H
#define FIGURES_H
#include <figure.h>
#include <QPainter>

class Square : public Figure {
    Q_OBJECT
    public:
        Square(Board* board, const int nx, const int ny, const int tp);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        void tryToRemove();
};
class Rhombus : public Figure {
    Q_OBJECT
    public:
        Rhombus(Board* board, const int nx, const int ny, const int tp);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        void tryToRemove();
};
class Cross : public Figure {
    Q_OBJECT
    public:
        Cross(Board* board, const int nx, const int ny, const int tp, int _xtype);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        void tryToRemove();
    private:
        int xtype;
};

#endif // FIGURES_H
