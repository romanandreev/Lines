#ifndef FIGURE_H
#define FIGURE_H
#include <QObject>
#include <QGraphicsItem>
#include<board.h>

class Figure : public QGraphicsObject {
    Q_OBJECT
    public:
    ~Figure(){}
    Figure(const Figure& f);
    Figure& operator = (const Figure& f);
    virtual Figure* Copy();
    Figure(Board* board, const int nx, const int ny, const int tp);
    void moveCell(const int nx, const int ny);
    virtual QRectF boundingRect() const;
    int getType() const;
    void select(const bool f);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget){}
    virtual void tryToRemove(){}
protected:
    int type;
    int x, y;
    bool selected;
    Board* myboard;
};


#endif // FIGURE_H
