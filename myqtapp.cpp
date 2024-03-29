#include "myqtapp.h"
#include<QTime>
#include<vector>

myQtApp::myQtApp(QDialog *parent) {
    setupUi(this);
    board = NULL;
    scene = NULL;
    locked = false;
    connect( pushButton, SIGNAL( clicked() ), this, SLOT( StartGame() ) );
    connect( pushButton_2, SIGNAL( clicked() ), this, SLOT( Quit() ) );
}

void myQtApp::Quit() {
    exit(0);
}

void myQtApp::AddCircles() {   
    std::vector<std::pair<int, int> > free;    
    //int free = 0;
    for (int x = 0; x < board->Size; ++x) {
        for (int y = 0; y < board->Size; ++y) {
            if (!board->getCell(x, y)) {
                free.push_back(std::make_pair(x, y));
            }
        }
    }
    for (int i = 0; i < std::min((int)free.size(), 3); ++i) {
        while (1) {
            int id = qrand() % ((int)free.size());
            int x = free[id].first;
            int y = free[id].second;
            swap(free[id], free[(int)free.size() - 1]);
            free.pop_back();
            Figure* f = board->addCell(x, y, qrand() % board->Colors + 1);
            scene->addItem(f);
            break;
        }
    }
    graphicsView->viewport()->update();
}




void myQtApp::mousePress(const int x, const int y) {
    if (locked) return;

    if (x < 0 || x >= board->getSize() || y < 0 || y >= board->getSize()) {
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

void myQtApp::addToScore(const int x) {
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
    int W = 400;
    int H = 400;
    int sh = 3;
    board = new Board(Size, Colors, W, H, sh);
    scene = new MyScene(W, H, sh, Size);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    connect( scene, SIGNAL( mousePress(int, int) ), this, SLOT(  mousePress(int, int) ) );
    connect( board, SIGNAL( deleteItem(Figure*) ), this, SLOT(  deleteItem(Figure*) ) );
    connect( board, SIGNAL( addToScore(int) ), this, SLOT(  addToScore(int) ) );
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

