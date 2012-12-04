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
   // void MousePress(QMouseEvent *event);
};


#endif
