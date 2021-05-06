#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"

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
	printf("------扫雷游戏------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
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



//int GetMine_count(char mine[ROWS][COLS], int x, int y)
//{
//	return mine[x - 1][y - 1] +
//		mine[x - 1][y] +
//		mine[x - 1][y + 1] +
//		mine[x][y - 1] +
//		mine[x][y + 1] +
//		mine[x + 1][y - 1] +
//		mine[x + 1][y] +
//		mine[x + 1][y + 1] - 8 * '0';
//}


int GetMine_count(char mine[ROWS][COLS], int x, int y)
{
	int count_mine = 0;
	if (mine[x - 1][y - 1] == '1')
		count_mine++;
	if (mine[x - 1][y] == '1')
		count_mine++;
	if (mine[x - 1][y + 1] == '1')
		count_mine++;
	if (mine[x][y - 1] == '1')
		count_mine++;
	if (mine[x][y + 1] == '1')
		count_mine++;
	if (mine[x + 1][y - 1] == '1')
		count_mine++;
	if (mine[x + 1][y] == '1')
		count_mine++;
	if (mine[x + 1][y + 1] == '1')
		count_mine++;
	return count_mine;
}


//void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
//{
//	//如果该坐标位置处不是雷，并且它周围一圈也没有雷，该位置设置为空格，并展开
//	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
//	{
//		int n = 0;
//		n = GetMine_count(mine, x, y);
//		if (n == 0)
//		{
//			show[x][y] = ' ';
//			if (show[x - 1][y - 1] == '*')
//			{
//				OpenMine(mine, show, x - 1, y - 1);
//			}
//			if (show[x - 1][y] == '*')
//			{
//				OpenMine(mine, show, x - 1, y);
//			}
//			if (show[x - 1][y + 1]=='*')
//			{
//				OpenMine(mine, show, x - 1, y + 1);
//			}
//			if (show[x][y + 1]=='*')
//			{
//				OpenMine(mine, show, x, y + 1);
//			}
//			if (show[x + 1][y + 1] == '*')
//			{
//				OpenMine(mine, show, x + 1, y + 1);
//			}
//			if (show[x + 1][y] == '*')
//			{
//				OpenMine(mine, show, x + 1, y);
//			}
//			if (show[x + 1][y - 1] == '*')
//			{
//				OpenMine(mine, show, x + 1, y - 1);
//			}
//			if (show[x][y - 1] == '*')
//			{
//				OpenMine(mine, show, x, y - 1);
//			}
//		}
//		else
//		{
//			show[x][y] = n + '0';
//		}
//	}
//
//}

//展开函数
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//如果该坐标位置处不是雷，并且它周围一圈也没有雷，该位置设置为空格，并展开
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		int n = 0;
		n = GetMine_count(mine, x, y);
		if (n == 0)
		{
			show[x][y] = ' ';
			int i = 0;
			int j = 0;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*'&& mine[i][j] == '0')
			        {
				        OpenMine(mine, show, i, j);
			        }

				}
			}
			
		}
		else
		{
			show[x][y] = n + '0';
		}
	}

}
//int count = 0;
//int OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
//{
//	//如果该坐标位置处不是雷，并且它周围一圈也没有雷，该位置设置为空格，并展开
//	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
//	{
//		int n = 0;
//		n = GetMine_count(mine, x, y);
//		if (n == 0)
//		{
//			show[x][y] = ' ';
//			count++;
//			int i = 0;
//			int j = 0;
//			for (i = x - 1; i <= x + 1; i++)
//			{
//				for (j = y - 1; j <= y + 1; j++)
//				{
//					if (show[i][j] == '*' && mine[i][j] == '0')
//					{
//						OpenMine(mine, show, i, j);
//					}
//
//				}
//			}
//
//		}
//		else
//		{
//			show[x][y] = n + '0';
//			count++;
//		}
//	}
//	return count;
//
//}

void menu_mark()
{
	printf("***1.扫雷     2.标记雷     3.撤销已标记的雷***\n");
}

//避免第一次就被炸死
void FirstMine(char mine[ROWS][COLS], int x, int y)
{
	int count_first = 1;
	int m = 0;
	int n = 0;
	while (count_first)
	{
			mine[x][y] = '0';
			m = rand() % (ROWS - 2) + 1;
			n = rand() % (COLS - 2) + 1;	
				if (mine[m][n] == '0')
				{
					mine[m][n] = '1';
					count_first--;
				}	
				
	}
}


////判断输赢
int JudgeWin(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int win = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*' || show[i][j] == '@')
			{
				win++;
			}
		}
	}
	return win;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.输入需要排查的坐标
	//2.检查坐标处是不是雷
	//(1)如果是雷，很遗憾，你被炸死了，结束游戏
	//(2)如果不是雷，统计此坐标周围八个坐标有几个雷，个数存储到show数组中，游戏继续
	int x = 0;
	int y = 0;
	int win = 0;
	int mine_num = 0;
	int input = 0;
	int cor_mine_num = 0;
	int first = 1;
	printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
		do
		{
			menu_mark();
			printf("请选择:>");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				//printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				printf("请输入需要排查的坐标:>");
				scanf("%d%d", &x, &y);
				if (x >= 1 && x <= row && y >= 1 && y <= col)
				{
					if (mine[x][y] == '1')
					{
						if (first == 1)
						{
							FirstMine(mine, x, y);
							DisplayBoard(mine, ROW, COL);
							OpenMine(mine, show, x, y);
							DisplayBoard(show, ROW, COL);
							first--;
							break;
						}
						if (first == 0)
						{
							printf("很遗憾，你被炸死了，游戏结束!\n");
							DisplayBoard(mine, ROW, COL);
							return;
						}
					}
					else
					{
						first = 0;
						OpenMine(mine, show, x, y);
						DisplayBoard(show, ROW, COL);

					}
				}
				else
				{
					printf("输入非法坐标，请重新输入!\n");
				}
				break;
			case 2:
				//printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				printf("请输入需要标记雷的坐标:>");
				scanf("%d%d", &x, &y);
				if (x >= 1 && x <= row && y >= 1 && y <= col)
				{
					if (show[x][y] == '*')
					{
						show[x][y] = '@';
						DisplayBoard(show, ROW, COL);
						mine_num++;
						if (mine[x][y] == '1')
						{
							cor_mine_num++;
						}
						if (cor_mine_num == EASY_COUNT)
						{
							printf("恭喜你，排雷成功!\n");
							DisplayBoard(mine, row, col);
							return;
						}
					}
					else if (show[x][y] == '@')
					{
						printf("输入坐标已被标记过，请重新输入!\n");
					}
					else
					{
						printf("输入坐标已被排查过，不是雷，无法标记，请重新输入!\n");
					}
				}
				else
				{
					printf("输入非法坐标，请重新输入!\n");
				}
				printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				break;
			case 3:
				//printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				printf("请输入需要取消标记雷的坐标:>");
				scanf("%d%d", &x, &y);
				if (x >= 1 && x <= row && y >= 1 && y <= col)
				{
					if (show[x][y] == '@')
					{
						show[x][y] = '*';
						DisplayBoard(show, ROW, COL);
						mine_num--;
						if (mine[x][y] == '1')
						{
							cor_mine_num--;
						}
						if (cor_mine_num == EASY_COUNT)
						{
							printf("恭喜你，排雷成功!\n");
							DisplayBoard(mine, row, col);
							return;
						}
					}
					else if (show[x][y] == '*')
					{
						printf("输入坐标未被标记过，无法取消标记，请重新输入!\n");
					}
					else
					{
						printf("输入坐标已被排查过，不是雷，无法取消标记，请重新输入!\n");
					}
				}
				else
				{
					printf("输入非法坐标，请重新输入!\n");
				}
				printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				break;
			default:
				printf("选择错误，请重新选择!\n");
				break;
			}
			win = JudgeWin(show, ROW, COL);
		} while (win > EASY_COUNT);

		if (win == EASY_COUNT)
		{
			printf("恭喜你，排雷成功!\n");
			DisplayBoard(mine, row, col);
	
		}
	}


//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	//1.输入需要排查的坐标
//	//2.检查坐标处是不是雷
//	//(1)如果是雷，很遗憾，你被炸死了，结束游戏
//	//(2)如果不是雷，统计此坐标周围八个坐标有几个雷，个数存储到show数组中，游戏继续
//	int x = 0;
//	int y = 0;
//	int win = 0;
//	int mine_num = 0;
//	int input = 0;
//	int cor_mine_num = 0;
//	int first = 1;
//	printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//	
//
//	while (win < row * col - EASY_COUNT)
//	{
//		menu_mark();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			//printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			printf("请输入需要排查的坐标:>");
//			scanf("%d%d", &x, &y);
//			if (x >= 1 && x <= row && y >= 1 && y <= col)
//			{
//				if (mine[x][y] == '1')
//				{
//					if (first == 1)
//					{
//						FirstMine(mine, x, y);
//						DisplayBoard(mine, ROW, COL);
//						OpenMine(mine, show, x, y);
//						DisplayBoard(show, ROW, COL);
//						first--;
//						break;
//					}
//					if (first == 0)
//					{
//						printf("很遗憾，你被炸死了，游戏结束!\n");
//						DisplayBoard(mine, ROW, COL);
//						return;
//					}
//				}
//				else
//				{
//					first = 0;
//					win = OpenMine(mine, show, x, y);
//					DisplayBoard(show, ROW, COL);
//
//				}
//			}
//			else
//			{
//				printf("输入非法坐标，请重新输入!\n");
//			}
//			break;
//		case 2:
//			//printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			printf("请输入需要标记雷的坐标:>");
//			scanf("%d%d", &x, &y);
//			if (x >= 1 && x <= row && y >= 1 && y <= col)
//			{
//				if (show[x][y] == '*')
//				{
//					show[x][y] = '@';
//					DisplayBoard(show, ROW, COL);
//					mine_num++;
//					if (mine[x][y] == '1')
//					{
//						cor_mine_num++;
//					}
//					if (cor_mine_num == EASY_COUNT)
//					{
//						printf("恭喜你，排雷成功!\n");
//						DisplayBoard(mine, row, col);
//						return;
//					}
//				}
//				else if (show[x][y] == '@')
//				{
//					printf("输入坐标已被标记过，请重新输入!\n");
//				}
//				else
//				{
//					printf("输入坐标已被排查过，不是雷，无法标记，请重新输入!\n");
//				}
//			}
//			else
//			{
//				printf("输入非法坐标，请重新输入!\n");
//			}
//			printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			break;
//		case 3:
//			//printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			printf("请输入需要取消标记雷的坐标:>");
//			scanf("%d%d", &x, &y);
//			if (x >= 1 && x <= row && y >= 1 && y <= col)
//			{
//				if (show[x][y] == '@')
//				{
//					show[x][y] = '*';
//					DisplayBoard(show, ROW, COL);
//					mine_num--;
//					if (mine[x][y] == '1')
//					{
//						cor_mine_num--;
//					}
//					if (cor_mine_num == EASY_COUNT)
//					{
//						printf("恭喜你，排雷成功!\n");
//						DisplayBoard(mine, row, col);
//						return;
//					}
//				}
//				else if (show[x][y] == '*')
//				{
//					printf("输入坐标未被标记过，无法取消标记，请重新输入!\n");
//				}
//				else
//				{
//					printf("输入坐标已被排查过，不是雷，无法取消标记，请重新输入!\n");
//				}
//			}
//			else
//			{
//				printf("输入非法坐标，请重新输入!\n");
//			}
//			printf("共有雷个数为:%d，当前标记雷个数为:%d，成功标记雷的个数为:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			break;
//		default:
//			printf("选择错误，请重新选择!\n");
//			break;
//		}
//	} 		
//	if (win == row*col-EASY_COUNT)
//	{
//		printf("恭喜你，排雷成功!\n");
//		DisplayBoard(mine, row, col);
//
//	}
//}
		



