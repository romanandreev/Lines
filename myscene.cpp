#include "myscene.h"
void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    //addEllipse(event->scenePos().x(), event->scenePos().y(), 20, 20);
    emit mousePress(event->scenePos().x(), event->scenePos().y());
}
