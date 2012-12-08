#ifndef FIGURES_H
#define FIGURES_H
#include <figure.h>
#include <QPainter>

/*class Circle : public Figure {
    Q_OBJECT
    public:
        Circle(Board* board, int nx, int ny, int tp);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
};*/
class Square : public Figure {
    Q_OBJECT
    public:
        Square(Board* board, int nx, int ny, int tp);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
};
class Rhombus : public Figure {
    Q_OBJECT
    public:
        Rhombus(Board* board, int nx, int ny, int tp);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
};
/*class Star : public Figure {
    Q_OBJECT
    public:
        Star(Board* board, int nx, int ny, int tp);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
};*/
class Cross : public Figure {
    Q_OBJECT
    public:
        Cross(Board* board, int nx, int ny, int tp, int _xtype);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    private:
        int xtype;
};

#endif // FIGURES_H
