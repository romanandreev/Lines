#include "board.h"
#include "global_objects.h"

Board::Board() {
    Board(9);
}

Board::Board(int Size) {
    size = Size;
    dx = (W - sh * 2) / size;
    dy = (H - sh * 2) / size;
    selectedx = -1;
    selectedy = -1;
    board = new int*[size];
    was = new int*[size];
    back = new int*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new int[size];
        was[i] = new int[size];
        back[i] = new int[size];
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
            was[i][j] = 0;
            back[i][j] = 0;
        }
    }

    color[0] = QColor(255, 0, 0);
    color[1] = QColor(0, 255, 0);
    color[2] = QColor(0, 0, 255);
    color[3] = QColor(255, 255, 0);
    color[4] = QColor(0, 255, 255);
    color[5] = QColor(255, 0, 255);
    color[6] = QColor(255, 192, 203);
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
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j]) {
                painter->setBrush(color[board[i][j] - 1]);
                painter->drawEllipse(sh + dx * i, sh + dy * j, dx, dy);
                if (i == selectedx && j == selectedy) {
                    painter->drawLine(sh + dx * i, sh + dy * j + dy / 2, sh + dx * (i + 1), sh + dy * j + dy / 2);
                    painter->drawLine(sh + dx * i + dx / 2, sh + dy * j, sh + dx * i + dx / 2, sh + dy * (j + 1));
                }
            }
        }
    }
}
void Board::select(int x, int y) {
    selectedx = x;
    selectedy = y;
}

void Board::changeCell(int x, int y, int c) {
    board[x][y] = c;
}
int Board::getCell(int x, int y) {
    return board[x][y];
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
            back[x][y] = board[x][y];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                if (board[x][y] && (x == 0 || y == 0 || board[x - 1 * MX[i]][y - 1 * MY[i]] != board[x][y])) {
                    int cl = board[x][y];
                    int k;
                    for (k = 0; x + k * MX[i] < size && y + k * MY[i] < size && board[x + k * MX[i]][y + k * MY[i]] == cl; k++);
                    if (k >= 5) {
                        for (k = 0; x + k * MX[i] < size && y + k * MY[i] < size && board[x + k * MX[i]][y + k * MY[i]] == cl; k++) {
                            back[x + k * MX[i]][y + k * MY[i]] = 0;
                        }
                    }
                }
            }
        }
    }
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (board[x][y] != back[x][y]) {
                del++;
            }
        }
    }
    Score += flag * del * (del - 1) / 2;
    if (del) {
        QTime dieTime = QTime::currentTime().addMSecs(300);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            board[x][y] = back[x][y];
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
                    (board[nx][ny] == 0 || (nx == selectedx && ny == selectedy))) {
                was[nx][ny] = cnt;
                back[nx][ny] = i;
                q.push(std::make_pair(nx, ny));
            }
        }
    }
    return false;
}

