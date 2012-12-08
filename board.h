#ifndef BOARD_H
#define BOARD_H
class Figure;
#include <myqtapp.h>
#include <QGraphicsObject>
#include <QTime>
#include <queue>

class Board : public QGraphicsObject {
    Q_OBJECT
    public:
        Board(int _Size, int _Colors, int _W, int _H, int _sh);
        int GetSize();
        void select(int x, int y);
        int getselectedx();
        int getselectedy();
        bool canDelete(int flag);
        int getBack(int x, int y);
        bool bfs(int x, int y);
        void changeCell(int x, int y, int c);
        int getCell(int x, int y);
        Figure* addCell(int x, int y, int cl);
        void moveCell(int x1, int y1, int x2, int y2);
        QRectF boundingRect() const;
        QColor getColor(int k) const;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        int Colors;
        int Size;
        int W, H;
        static const int DX[4];
        static const int DY[4];
        static const int MX[4];
        static const int MY[4];
        int dx, dy, sh;
    private:
        Figure*** board;
        int** was;
        int** back;
        int size;
        int cnt;
        int selectedx;
        int selectedy;

        QColor color[20];
    signals:
        void addToScore(int);
        void deleteItem(Figure*);
};

#endif
