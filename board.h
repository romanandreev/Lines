#ifndef BOARD_H
#define BOARD_H
#include <QObject>
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
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    protected:

    private:
        int** board;
        int** was;
        int** back;
        int size;
        int selectedx;
        int selectedy;
        QColor color[20];
};

#endif
