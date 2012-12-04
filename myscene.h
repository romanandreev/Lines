#ifndef MYSCENE_H
#define MYSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
class MyScene : public QGraphicsScene {
    Q_OBJECT
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void mousePress(int x, int y);
};
#endif // MYSCENE_H
