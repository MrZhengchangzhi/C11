#define _CRT_SECURE_NO_WARNINGS 1.
#include "game.h"

void Displayboard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ",arr[i][j]);
			if (j < col-1)
			{
				printf("|");
			}			
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
			if (j < col-1)
			{
				printf("|");
			}
		}
		printf("\n");
	}		
}

void Initboard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}		
	}
}

void Play_move(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入要下棋的坐标>:\n");
		scanf("%d%d", &x, &y);
		if (arr[x - 1][y - 1] == ' ')
		{
			arr[x - 1][y - 1] = '*';
			break;
		}
	}
	
	
}

void Comp_move(char arr[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
		
	}
	
	
}

int Full(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Is_win(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for(i=0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] &&arr[i][1]!=' ')
		{
			return arr[i][1];
		}
	}
	for(i=0; i< 3; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i]!=' ')
		{
			return arr[1][i];
		}
	}
	if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] !=' '))
	{
		return arr[1][1];
	}
	if ((arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' '))
	{
		return arr[1][1];
	}
	int num = Full(arr,row,col);
	if (num == 1)
	{
		return 'Q';
	}
	return  'c';
}

