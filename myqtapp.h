#ifndef MYQTAPP_H
#define MYQTAPP_H
#include "ui_form.h"
#include "figure.h"

class myQtApp : public QDialog, private Ui::Dialog
{
    Q_OBJECT
public:
    myQtApp(QDialog *parent = 0);
    void AddCircles();

public slots:
    void StartGame();
    void deleteItem(Figure* f);
    void Quit();
    void mousePress(int x, int y);
};
#endif // MYQTAPP_H
