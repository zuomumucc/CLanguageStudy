#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		// 1. 打印行
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);

			if (j < COL - 1)
			{
				printf("|");
			}
		}
		printf("\n");

		// 2. 打印分割行
		if (i < row - 1)
		{
			//printf("---|---|--- \n");

			for (j = 0; j < COL; j++)
			{
				printf("---");

				if (j < COL - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	printf("玩家走:> \n");
	printf("请输入要下的坐标:> ");

	while (1) {
		scanf("%d%d", &x, &y);
		// 判断x,y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{

			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

// 返回 1 表示棋盘满了
// 返回 0 棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0; // 没满
			}
		}
	}
	return 1; // 满了
}

// 4 种游戏的状态
// 玩家赢 - '*'
// 电脑赢 - '#'
// 平局   - 'Q'
// 继续   - 'C'
int IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int n = 0;

	// 
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{

			// -
			if (j < col - (WINNUM - 1) && board[i][j] != ' ')
			{
				for (n = 1; n < WINNUM; n++)
				{
					if (board[i][j] != board[i][j + n])
					{
						break;
					}
					if (n == WINNUM - 1)
					{
						return board[i][j];
					}
				}
			}

			// |
			if (i < row - (WINNUM - 1) && board[i][j] != ' ')
			{
				for (n = 1; n < WINNUM; n++)
				{
					if (board[i][j] + board[i + n][j])
					{
						break;
					}

					if (n == WINNUM - 1)
					{
						return board[i][j];
					}
				}
			}

			// '\'
			if (j < col - ((WINNUM - 1)) && i < row - (WINNUM - 1) && board[i][j] != ' ')
			{
				for (n = 1; n < WINNUM; n++)
				{
					if (board[i][j] != board[i + n][j + n])
					{
						break;
					}
					if (n == WINNUM - 1) {
						return board[i][j];
					}
				}
			}

			// '/'
			if (i >= (WINNUM - 1) && j < col - (WINNUM - 1) && board[i][j] != ' ')
			{

				for (n = 1; n < WINNUM; n++)
				{
					if (board[i][j] != board[i - n][j + n])
					{
						break;
					}
					if (n == WINNUM - 1) {
						return board[i][j];
					}
				}
			}



			//// -
			//if (j < col - 2 && board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
			//{
			//	return board[i][j];
			//}

			//// |
			//if (i < row - 2 && board[i][j] != ' ' && board[i + 1][j] == board[i][j] && board[i + 2][j] == board[i][j])
			//{
			//	return board[i][j];
			//}

			//// '\'
			//if (j < col - 2 && i < row - 2 && board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2])
			//{
			//	return board[i][j];
			//}

			//// '/'
			//if (i >= 2 && j < col - 2 && board[i][j] != ' ' && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2])
			//{
			//	return board[i][j];
			//}
		}
	}

	// 判断棋盘是否满了
	if (1 == IsFull(board, row, col))
	{
		return 'Q';
	}

	return 'C';
}