#ifndef MYQTAPP_H
#define MYQTAPP_H
#include "ui_form.h"
#include "myscene.h"
#include "board.h"


class myQtApp : public QDialog, private Ui::Dialog
{
    Q_OBJECT
public:
    myQtApp(QDialog *parent = 0);
    void AddCircles();
    void addToScore(int x);
    MyScene* scene;
    Board *board;
public slots:
    void StartGame();
    void deleteItem(Figure* f);
    void Quit();
    void mousePress(int x, int y);


private:
    bool locked;
    int Score;
};
#endif // MYQTAPP_H
