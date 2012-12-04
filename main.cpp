#include <QApplication>

#include "source.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    myQtApp *dialog = new myQtApp;
    dialog->show();
    return app.exec();
}
