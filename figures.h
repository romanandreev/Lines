#ifndef FIGURES_H
#define FIGURES_H
#include <figure.h>
#include <QPainter>

class Square : public Figure {
    Q_OBJECT
    public:
        virtual Figure* Copy();
        Square(Board* board, const int nx, const int ny, const int tp);
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        virtual void tryToRemove();
};
class Rhombus : public Figure {
    Q_OBJECT
    public:
        virtual Figure* Copy();
        Rhombus(Board* board, const int nx, const int ny, const int tp);
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        virtual void tryToRemove();
};
class Cross : public Figure {
    Q_OBJECT
    public:
        virtual Figure* Copy();
        Cross(const Cross& c);
        ~Cross(){}
        Cross& operator = (const Cross& f);
        Cross(Board* board, const int nx, const int ny, const int tp, int _xtype);
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        virtual void tryToRemove();
    private:
        int xtype;
};

#endif // FIGURES_H
