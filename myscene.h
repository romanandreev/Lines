#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
class MyScene : public QGraphicsScene {
    Q_OBJECT
public:
    int W;
    int H;
    int sh;
    int Size;
    int dx, dy;
    MyScene(int _W, int _H, int _sh, int _Size);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void mousePress(int x, int y);


};
#endif // MYSCENE_H
