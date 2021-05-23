#define ROW 10
#define COL 10
#define WINNUM 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ����
void InitBoard(char board[ROW][COL], int row, int col);

// ��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);

// 4 ����Ϸ��״̬
// ���Ӯ - '*'
// ����Ӯ - '#'
// ƽ��   - 'Q'
// ����   - 'C'

int IsWin(char board[ROW][COL], int row, int col);