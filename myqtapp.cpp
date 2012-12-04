#include "myqtapp.h"
#include "global_objects.h"
myQtApp::myQtApp(QDialog *parent) {
    setupUi(this);
    connect( pushButton, SIGNAL( clicked() ), this, SLOT( StartGame() ) );
    connect( pushButton_2, SIGNAL( clicked() ), this, SLOT( Quit() ) );
   // connect( pushButton_3, SIGNAL( clicked() ), this, SLOT( AddCircles() ) );
}

void myQtApp::Quit() {
    exit(0);
}

void myQtApp::AddCircles() {
    int free = 0;
    for (int x = 0; x < Size; x++) {
        for (int y = 0; y < Size; y++) {
            if (!board->getCell(x, y)) {
                free++;
            }
        }
    }
    for (int i = 0; i < std::min(free, 3); i++) {
        while (1) {
            int x = qrand() % board->GetSize();
            int y = qrand() % board->GetSize();
            if (board->getCell(x, y)) continue;
            board->changeCell(x, y, qrand() % Colors + 1);
            break;
        }
    }
    graphicsView->viewport()->update();
}




void myQtApp::mousePress(int x, int y) {
    if (locked) return;
    //label_3->setNum(x);
    x = (x - sh) / dx;
    y = (y - sh) / dy;
    if (x < 0 || x >= board->GetSize() || y < 0 || y >= board->GetSize()) {
        return;
    }
    if (board->getCell(x, y)) {
        if (x == board->getselectedx() && y == board->getselectedy()) {
            board->select(-1, -1);
        } else{
            board->select(x, y);
        }
    } else {
        if (board->bfs(x, y)) {
            locked = true;

            int cx = board->getselectedx();
            int cy = board->getselectedy();
            int cl = board->getCell(cx, cy);
            while (1) {
                int nx = cx - DX[board->getBack(cx, cy)];
                int ny = cy - DY[board->getBack(cx, cy)];
                board->changeCell(nx, ny, cl);
                board->changeCell(cx, cy, 0);
                graphicsView->viewport()->update();
                if (nx == x && ny == y) {
                    break;
                }
                QTime dieTime = QTime::currentTime().addMSecs(100);
                while( QTime::currentTime() < dieTime )
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                cx = nx;
                cy = ny;
            }
            board->select(-1, -1);
            if (!board->canDelete(1)) {

                AddCircles();
                board->canDelete(0);
            }
            locked = false;
        }
    }
    label_4->setNum(Score);
    graphicsView->viewport()->update();
}




void myQtApp::StartGame()
{
    Score = 0;
    label_4->setNum(Score);
    Board* board1 = board;
    MyScene* scene1 = scene;

    Colors = spinBox_2->value();
    Size = spinBox->value();
    board = new Board(Size);
    scene = new MyScene();
    connect( scene, SIGNAL( mousePress(int, int) ), this, SLOT(  mousePress(int, int) ) );
    scene->setSceneRect(0, 0, W, H);
    scene->addItem(board);
    graphicsView->setScene(scene);
    graphicsView->adjustSize();
    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    AddCircles();

    delete board1;
    delete scene1;
}

