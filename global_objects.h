#ifndef GLOBAL_OBJECTS_H
#define GLOBAL_OBJECTS_H
#include <QtGui>
//#include <QtTest>
//#include <QtTest/QTest>
#include <queue>
#include <vector>
#include <algorithm>
#include "myscene.h"
#include "board.h"

extern int W;
extern int H;
extern int sh;
extern int Colors;
extern int Size;
extern int dx, dy;
extern int cnt;
extern int Score;
extern bool locked;

extern int DX[4];
extern int DY[4];
extern int MX[4];
extern int MY[4];
extern MyScene* scene;
extern Board *board;
#endif // GLOBAL_OBJECTS_H
