#ifndef BOARD_H
#define BOARD_H
#include <QObject>
#include <figure.h>
#include <QGraphicsItem>

class Board : public QGraphicsObject {
    Q_OBJECT
    public:
        Board();
        Board(int Size);
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
    protected:

    private:
        Figure*** board;
        int** was;
        int** back;
        int size;
        int selectedx;
        int selectedy;
        QColor color[20];
    signals:
        void deleteItem(Figure*);
};

#endif
