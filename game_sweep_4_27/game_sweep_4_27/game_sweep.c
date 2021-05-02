#define _CRT_SECURE_NO_WARNINGS 1


#include"game_sweep.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------扫雷游戏-----------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	//for (j = 0; j <= col; j++)
	//{
	//	printf("--");
	//}
	//printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		//printf("|");
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}



void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}

}



int GetMine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.输入需要排查的坐标
	//2.检查坐标处是不是雷
	//(1)如果是雷，很遗憾，你被炸死了，结束游戏
	//(2)如果不是雷，统计此坐标周围八个坐标有几个雷，个数存储到show数组中，游戏继续
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入需要排查的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了，游戏结束!\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				count = GetMine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\n");
		}

	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功!\n");
		DisplayBoard(mine, row, col);
	}
	
}



