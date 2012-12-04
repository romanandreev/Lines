#include <QtGui>
#include "source.h"


myQtApp::myQtApp(QDialog *parent) {
    setupUi(this);
    connect( pushButton, SIGNAL( clicked() ), this, SLOT( StartGame() ) );
   // connect( graphicsView, SIGNAL( mousePressEvent(QMouseEvent *event) ), this, SLOT( mousePress(QMouseEvent *event) ) );
}
int W = 400;
int H = 400;

QGraphicsScene* scene;
int Colors = 0;
int Size = 0;
class Board : public QGraphicsItem {
    public:
        Board();
        Board(int Size);
        int GetSize();
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
}
/*void MousePress(QMouseEvent *event)
{
    //board->add();
}*/

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
                painter->drawEllipse(sh + dx * i, sh + dy * i, dx, dy);
            }
        }
    }
}


void myQtApp::StartGame()
{
    Colors = spinBox_2->value();
    Size = spinBox->value();
    board = new Board(Size);
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, W, H);
    scene->addItem(board);
    graphicsView->setScene(scene);
    graphicsView->adjustSize();
    graphicsView->repaint();
}





