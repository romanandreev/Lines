#include <QtGui>
#include "source.h"

MyScene* scene;

myQtApp::myQtApp(QDialog *parent) {
    setupUi(this);
    connect( pushButton, SIGNAL( clicked() ), this, SLOT( StartGame() ) );
    connect( pushButton_2, SIGNAL( clicked() ), this, SLOT( Quit() ) );
    connect( pushButton_3, SIGNAL( clicked() ), this, SLOT( AddCircles() ) );    
}



int W = 400;
int H = 400;


int Colors = 0;
int Size = 0;
class Board : public QGraphicsItem {
    public:
        Board();
        Board(int Size);
        int GetSize();
        void changeCell(int x, int y, int c);
        int getCell(int x, int y);

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    protected:

    private:
        int** board;
        int size;
        QColor color[20];
};
Board *board;
Board::Board() {
    Board(10);
}

Board::Board(int Size) {
    size = Size;
    board = new int*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new int[size];
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
    board[1][1] = 1;
    board[2][3] = 2;

    color[0] = QColor(255, 0, 0);
    color[1] = QColor(0, 255, 0);
    color[2] = QColor(0, 0, 255);
    color[3] = QColor(255, 255, 0);
    color[4] = QColor(0, 255, 255);
    color[5] = QColor(255, 0, 255);

}

void myQtApp::Quit() {
    exit(0);
}


int Board::GetSize() {
    return size;
}
QRectF Board::boundingRect() const {
    return QRectF(0, 0, W, H);
}
void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(QColor(0, 0 ,0));
    int sh = 4;
    int dx = (W - sh * 2) / size;
    int dy = (H - sh * 2) / size;
    for (int i = 0; i <= size; i++) {
        painter->drawLine(sh, i * dy + sh, dx * size + sh, i * dy + sh);
        painter->drawLine(i * dx + sh, sh, i * dx + sh, dy * size + sh);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j]) {
                painter->setBrush(color[board[i][j] - 1]);
                painter->drawEllipse(sh + dx * i, sh + dy * j, dx, dy);
            }
        }
    }
}
void Board::changeCell(int x, int y, int c) {
    board[x][y] = c;
}
int Board::getCell(int x, int y) {
    return board[x][y];
}

void myQtApp::AddCircles() {
    int x = qrand() % board->GetSize();
    int y = qrand() % board->GetSize();
    if (!board->getCell(x, y))
        board->changeCell(x, y, qrand() % Colors + 1);

    graphicsView->viewport()->update();
}

void myQtApp::mousePress(int x, int y) {
    //label_3->setNum(x);
}


void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    //addEllipse(event->scenePos().x(), event->scenePos().y(), 20, 20);
    emit mousePress(event->scenePos().x(), event->scenePos().y());
}

void myQtApp::StartGame()
{

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





