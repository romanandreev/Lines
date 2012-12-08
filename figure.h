#ifndef FIGURE_H
#define FIGURE_H
#include <QObject>
#include <QGraphicsItem>
#include<board.h>

class Figure : public QGraphicsObject {
    Q_OBJECT
    public:
    Figure(Board* board, int nx, int ny, int tp);
    void moveCell(int nx, int ny);
    QRectF boundingRect() const;
    int getType();
    void select(bool f);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget){}
protected:
    int type;
    int x, y;
    bool selected;
    Board* myboard;
};


#endif // FIGURE_H
