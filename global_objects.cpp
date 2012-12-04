#include "global_objects.h"

int W = 400;
int H = 400;
int sh = 4;
int Colors = 0;
int Size = 0;
int dx, dy;
int cnt = 0;
int Score = 0;
bool locked = false;

int DX[4] = {1, -1, 0, 0};
int DY[4] = {0, 0, 1, -1};
int MX[4] = {1, 0, 1, 1};
int MY[4] = {0, 1, 1, -1};
MyScene* scene;
Board *board;

