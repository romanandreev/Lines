#include "board.h"

Board::Board(int _Size = 9, int _Colors = 4, myQtApp* qtapp = NULL) {
    Size = _Size;
    Colors = _Colors;
    myqtapp = qtapp;
    size = Size;
    cnt = 0;

    selectedx = -1;
    selectedy = -1;
    board = new Figure**[size];
    was = new int*[size];
    back = new int*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new Figure*[size];
        was[i] = new int[size];
        back[i] = new int[size];
        for (int j = 0; j < size; j++) {
            board[i][j] = NULL;
            was[i][j] = 0;
            back[i][j] = 0;
        }
    }

    color[1] = QColor(255, 0, 0);
    color[2] = QColor(0, 255, 0);
    color[3] = QColor(30, 144, 255);
    color[4] = QColor(255, 255, 0);
    color[5] = QColor(0, 255, 255);
    color[6] = QColor(255, 0, 255);
    color[7] = QColor(255, 192, 203);
    color[8] = QColor(190, 39, 143);
}

int Board::GetSize() {
    return size;
}
QRectF Board::boundingRect() const {
    return QRectF(0, 0, W, H);
}
void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(QColor(0, 0 ,0));

    for (int i = 0; i <= size; i++) {
        painter->drawLine(sh, i * dy + sh, dx * size + sh, i * dy + sh);
        painter->drawLine(i * dx + sh, sh, i * dx + sh, dy * size + sh);
    }
}
void Board::select(int x, int y) {
    if (selectedx >= 0 && selectedy >= 0 && selectedx < Size && selectedy < Size &&
            board[selectedx][selectedy] != NULL)
        board[selectedx][selectedy]->select(false);
    selectedx = x;
    selectedy = y;
    if (x >= 0 && y >= 0 && x < Size && y < Size && board[x][y] != NULL)
        board[x][y]->select(true);
}

/*void Board::changeCell(int x, int y, int c) {
    board[x][y] = c;
}*/
int Board::getCell(int x, int y) {
    return (x < 0 || x >= Size || y < 0 || y >= Size || board[x][y] == NULL) ? 0 : board[x][y]->getType();
}
int Board::getBack(int x, int y) {
    return back[x][y];
}
int Board::getselectedx() {
    return selectedx;
}
int Board::getselectedy() {
    return selectedy;
}

bool Board::canDelete(int flag) {
    int del = 0;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            back[x][y] = 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                if (board[x][y] != NULL &&
                        (getCell(x - 1 * MX[i], y - 1 * MY[i]) != getCell(x, y))) {
                    int cl = board[x][y]->getType();
                    int k;
                    for (k = 0; x + k * MX[i] < size && y + k * MY[i] < size &&
                         getCell(x + k * MX[i], y + k * MY[i]) == cl; k++);
                    if (k >= 5) {
                        for (int k2 = 0; k2 < k; k2++ ) {
                            back[x + k2 * MX[i]][y + k2 * MY[i]] = 0;
                        }
                    }
                }
            }
        }
    }
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (back[x][y] == 0) {
                del++;                
            }
        }
    }
    myqtapp->addToScore(flag * del * (del - 1) / 2);
    if (del) {
        QTime dieTime = QTime::currentTime().addMSecs(300);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (back[x][y] == 0) {
                emit deleteItem(board[x][y]);
                board[x][y] = NULL;
            }
        }
    }
    return del > 0;
}

bool Board::bfs(int x, int y) {
    std::queue<std::pair<int, int> > q;
    q.push(std::make_pair(x, y));
    cnt++;
    was[x][y] = cnt;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == selectedx && y == selectedy) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (nx >= 0 && nx < Size && ny >= 0 && ny < Size && was[nx][ny] != cnt &&
                    (board[nx][ny] == NULL || (nx == selectedx && ny == selectedy))) {
                was[nx][ny] = cnt;
                back[nx][ny] = i;
                q.push(std::make_pair(nx, ny));
            }
        }
    }
    return false;
}
QColor Board::getColor(int k) const {
    return color[k];
}
Figure* Board::addCell(int x, int y, int cl) {
    Figure* f = NULL;
    switch ((cl - 1) % 4 + 1) {
        case 1:
        f = new Circle(this, x, y, cl);
        break;
        case 2:
        f = new Square(this, x, y, cl);
        break;
        case 3:
        f = new Rhombus(this, x, y, cl);
        break;
        case 4:
        f = new Star(this, x, y, cl);
        break;
    }
    return board[x][y] = f;
}

void Board::moveCell(int x1, int y1, int x2, int y2) {
    board[x1][y1]->moveCell(x2, y2);
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = NULL;
}
