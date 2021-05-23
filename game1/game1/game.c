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
		// 1. ��ӡ��
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

		// 2. ��ӡ�ָ���
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
	printf("�����:> \n");
	printf("������Ҫ�µ�����:> ");

	while (1) {
		scanf("%d%d", &x, &y);
		// �ж�x,y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{

			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	printf("������:>\n");
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

// ���� 1 ��ʾ��������
// ���� 0 ����û��
int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0; // û��
			}
		}
	}
	return 1; // ����
}

// 4 ����Ϸ��״̬
// ���Ӯ - '*'
// ����Ӯ - '#'
// ƽ��   - 'Q'
// ����   - 'C'
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

	// �ж������Ƿ�����
	if (1 == IsFull(board, row, col))
	{
		return 'Q';
	}

	return 'C';
}