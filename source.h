#ifndef SOURCE_H
#define SOURCE_H

#include "ui_form.h"


class myQtApp : public QDialog, private Ui::Dialog
{
    Q_OBJECT

public:
    myQtApp(QDialog *parent = 0);


public slots:
    void StartGame();
    void AddCircles();
    void Quit();  
    void mousePress(int x, int y);
};
class MyScene : public QGraphicsScene {
    Q_OBJECT
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void mousePress(int x, int y);
};


#endif
