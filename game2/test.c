#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void test();
void game();
void menu();

int main()
{
	test();
	return 0;
}

void menu()
{
	printf("************************************\n");
	printf("************** 1. play *************\n");
	printf("************** 0. exit *************\n");
	printf("************************************\n");
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n\n");
			break;
		default:
			printf("ѡ���������ѡ��\n\n");
			break;
		}

	} while (input);
}

void game()
{
	printf("��ʼ��Ϸ\n\n");
}