#include <QApplication>
#include "source.h"
#include <QTime>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    myQtApp *dialog = new myQtApp;
    dialog->show();
    return app.exec();
}
