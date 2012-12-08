#ifndef FIGURE_H
#define FIGURE_H
#include <QObject>
#include <cassert>
#include <QGraphicsItem>
class Board;
class Figure : public QGraphicsObject {
    Q_OBJECT
    public:
    Figure(Board* board, int nx, int ny);
    void moveCell(int nx, int ny);
    QRectF boundingRect() const;
    virtual int getType() const {return 0;}
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget){}
protected:
    int type;
    int x, y;
    bool selected;
    Board* myboard;
};


#endif // FIGURE_H
