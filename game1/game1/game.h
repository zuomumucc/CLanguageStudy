#define ROW 10
#define COL 10
#define WINNUM 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 声明
void InitBoard(char board[ROW][COL], int row, int col);

// 打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);

// 4 种游戏的状态
// 玩家赢 - '*'
// 电脑赢 - '#'
// 平局   - 'Q'
// 继续   - 'C'

int IsWin(char board[ROW][COL], int row, int col);