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
        Board(const int _Size, const int _Colors, const int _W, const int _H, const int _sh);
        ~Board();
        int getSize() const;
        void select(const int x, const int y);
        int getselectedx() const;
        int getselectedy() const;
        bool canDelete(const int flag);
        int getBack(const int x, const int y) const;
        bool bfs(const int x, const int y);
        void changeCell(const int x, const int y, const int c);
        int getCell(const int x, const int y) const;
        Figure* addCell(const int x, const int y, const int cl);
        void moveCell(const int x1, const int y1, const int x2, const int y2);
        QRectF boundingRect() const;
        QColor getColor(const int k) const;

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
        int** back;
    private:
        Figure*** board;
        int** was;
        int size;
        int cnt;
        int selectedx;
        int selectedy;

        QColor color[20];
    signals:
        void addToScore(const int);
        void deleteItem(Figure*);
};

#endif
