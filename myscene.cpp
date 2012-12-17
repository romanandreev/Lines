#include "myscene.h"
MyScene::MyScene(const int _W, const int _H, const int _sh, const int _Size) : W(_W), H(_H), sh(_sh), Size(_Size){
     setSceneRect(0, 0, W, H);
     dx = (W - sh * 2) / Size;
     dy = (H - sh * 2) / Size;
}
void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    //QGraphicsScene::mousePressEvent(event);
    emit mousePress((event->scenePos().x() - sh) / dx, (event->scenePos().y() - sh) / dy);
}
