#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void test();
void menu();
void game();

// ������������Ϸ

int main()
{
	test();
	return 0;
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("%d����\n", WINNUM);
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

void menu()
{
	printf("***************************************************\n");
	printf("**************** 1. play  0. exit* ****************\n");
	printf("***************************************************\n");
}


//    |   |
// ---|---|---
//    |   |
// ---|---|---
//    |   |

// ��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	// ���� - ����߳���������Ϣ
	char board[ROW][COL] = {0};

	// ��ʼ������
	InitBoard(board, ROW, COL);

	// ��ӡ����
	DisplayBoard(board, ROW, COL);

	// ����
	while (1)
	{
		// �������
		PlayerMove(board, ROW, COL);

		// ��ӡ����
		DisplayBoard(board, ROW, COL);
		// �ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		// ��������
		ComputerMove(board, ROW, COL);

		// ��ӡ����
		DisplayBoard(board, ROW, COL);
		// �ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("���Ӯ!!!\n\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ!!!\n\n");
	}
	else
	{
		printf("ƽ��!!!\n\n");
	}
}