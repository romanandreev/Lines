#include "myqtapp.h"
#include<QTime>
myQtApp::myQtApp(QDialog *parent) {
    setupUi(this);
    board = NULL;
    scene = NULL;
    locked = false;
    connect( pushButton, SIGNAL( clicked() ), this, SLOT( StartGame() ) );
    connect( pushButton_2, SIGNAL( clicked() ), this, SLOT( Quit() ) );
   // connect( pushButton_3, SIGNAL( clicked() ), this, SLOT( AddCircles() ) );
}

void myQtApp::Quit() {
    exit(0);
}

void myQtApp::AddCircles() {
    int free = 0;
    for (int x = 0; x < board->Size; x++) {
        for (int y = 0; y < board->Size; y++) {
            if (!board->getCell(x, y)) {
                free++;
            }
        }
    }
    for (int i = 0; i < std::min(free, 3); i++) {
        while (1) {
            int x = qrand() % board->Size;
            int y = qrand() % board->Size;
            if (board->getCell(x, y)) continue;
            Figure* f = board->addCell(x, y, qrand() % board->Colors + 1);
            scene->addItem(f);
            break;
        }
    }
    graphicsView->viewport()->update();
}




void myQtApp::mousePress(int x, int y) {
    if (locked) return;
    //label_3->setNum(x);

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
            board->select(-1, -1);
            while (1) {
                int nx = cx - board->DX[board->getBack(cx, cy)];
                int ny = cy - board->DY[board->getBack(cx, cy)];
                board->moveCell(cx, cy, nx, ny);
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


void myQtApp::deleteItem(Figure* f) {
    scene->removeItem(f);
}

void myQtApp::addToScore(int x) {
    Score += x;
}

void myQtApp::StartGame()
{
    Score = 0;
    label_4->setNum(Score);
    Board* board1 = board;
    MyScene* scene1 = scene;

    int Colors = spinBox_2->value();
    int Size = spinBox->value();
    board = new Board(Size, Colors, this);
    scene = new MyScene(400, 400, 4, Size);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    connect( scene, SIGNAL( mousePress(int, int) ), this, SLOT(  mousePress(int, int) ) );
    connect( board, SIGNAL( deleteItem(Figure*) ), this, SLOT(  deleteItem(Figure*) ) );

    scene->addItem(board);
    graphicsView->setScene(scene);
    graphicsView->adjustSize();

    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    graphicsView->viewport()->update();
    AddCircles();

    delete board1;
    delete scene1;
}

