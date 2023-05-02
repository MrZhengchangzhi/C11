#define _CRT_SECURE_NO_WARNINGS 1.

#include "game.h"


void menu()
{
	printf("*****************************\n");
	printf("*****************************\n");
	printf("*****************************\n");
	printf("***  1.Play      0.Exit  ****\n");
	printf("*****************************\n");
	printf("*****************************\n");
}

void game()
{
	char arr[ROW][COL];	
	char ret = 0;
	Initboard(arr, ROW, COL);//初始化棋盘
	while (1)
	{
		Play_move(arr, ROW, COL);//请下棋
		Displayboard(arr, ROW, COL);
		ret=Is_win(arr, ROW, COL);
		if (ret != 'c')
			break;
		Comp_move(arr, ROW, COL);//电脑下棋
		Displayboard(arr, ROW, COL);	
		if (ret != 'c')
			break;
	}
	if (ret == '*')
	{
		printf("You Win\n");
	}
	else if (ret == '#')
	{
		printf("You Lose\n");
	}
	else
	{
		printf("平局\n");
	}
}

int main()
{
	int input = 0;	
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择游戏模式>:\n");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("游戏退出\n");
				break;			
			default:
				printf("选择错误，请重新选择>:\n");
				break;
		}
	} while (input);
	return 0;
}