#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
class Board;
class Figure;

class MyScene : public QGraphicsScene {
    Q_OBJECT
public:
    MyScene(int _W, int _H, int _sh, int _Size);
    int W;
    int H;
    int sh;
    int Size;
    int dx, dy;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void mousePress(int x, int y);


};
#endif // MYSCENE_H
