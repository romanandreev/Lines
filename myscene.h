#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
class Board;
class Figure;

class MyScene : public QGraphicsScene {
    Q_OBJECT
public:
    MyScene(const int _W, const int _H, const int _sh, const int _Size);
    int W;
    int H;
    int sh;
    int Size;
    int dx, dy;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void mousePress(const int x, const int y);


};
#endif // MYSCENE_H
