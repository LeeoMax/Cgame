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
	printf("------ɨ����Ϸ------\n");
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
//	//���������λ�ô������ף���������ΧһȦҲû���ף���λ������Ϊ�ո񣬲�չ��
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

//չ������
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//���������λ�ô������ף���������ΧһȦҲû���ף���λ������Ϊ�ո񣬲�չ��
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
//	//���������λ�ô������ף���������ΧһȦҲû���ף���λ������Ϊ�ո񣬲�չ��
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
	printf("***1.ɨ��     2.�����     3.�����ѱ�ǵ���***\n");
}

//�����һ�ξͱ�ը��
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


////�ж���Ӯ
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
	//1.������Ҫ�Ų������
	//2.������괦�ǲ�����
	//(1)������ף����ź����㱻ը���ˣ�������Ϸ
	//(2)��������ף�ͳ�ƴ�������Χ�˸������м����ף������洢��show�����У���Ϸ����
	int x = 0;
	int y = 0;
	int win = 0;
	int mine_num = 0;
	int input = 0;
	int cor_mine_num = 0;
	int first = 1;
	printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
		do
		{
			menu_mark();
			printf("��ѡ��:>");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				//printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				printf("��������Ҫ�Ų������:>");
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
							printf("���ź����㱻ը���ˣ���Ϸ����!\n");
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
					printf("����Ƿ����꣬����������!\n");
				}
				break;
			case 2:
				//printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				printf("��������Ҫ����׵�����:>");
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
							printf("��ϲ�㣬���׳ɹ�!\n");
							DisplayBoard(mine, row, col);
							return;
						}
					}
					else if (show[x][y] == '@')
					{
						printf("���������ѱ���ǹ�������������!\n");
					}
					else
					{
						printf("���������ѱ��Ų���������ף��޷���ǣ�����������!\n");
					}
				}
				else
				{
					printf("����Ƿ����꣬����������!\n");
				}
				printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				break;
			case 3:
				//printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				printf("��������Ҫȡ������׵�����:>");
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
							printf("��ϲ�㣬���׳ɹ�!\n");
							DisplayBoard(mine, row, col);
							return;
						}
					}
					else if (show[x][y] == '*')
					{
						printf("��������δ����ǹ����޷�ȡ����ǣ�����������!\n");
					}
					else
					{
						printf("���������ѱ��Ų���������ף��޷�ȡ����ǣ�����������!\n");
					}
				}
				else
				{
					printf("����Ƿ����꣬����������!\n");
				}
				printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
				break;
			default:
				printf("ѡ�����������ѡ��!\n");
				break;
			}
			win = JudgeWin(show, ROW, COL);
		} while (win > EASY_COUNT);

		if (win == EASY_COUNT)
		{
			printf("��ϲ�㣬���׳ɹ�!\n");
			DisplayBoard(mine, row, col);
	
		}
	}


//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	//1.������Ҫ�Ų������
//	//2.������괦�ǲ�����
//	//(1)������ף����ź����㱻ը���ˣ�������Ϸ
//	//(2)��������ף�ͳ�ƴ�������Χ�˸������м����ף������洢��show�����У���Ϸ����
//	int x = 0;
//	int y = 0;
//	int win = 0;
//	int mine_num = 0;
//	int input = 0;
//	int cor_mine_num = 0;
//	int first = 1;
//	printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//	
//
//	while (win < row * col - EASY_COUNT)
//	{
//		menu_mark();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			//printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			printf("��������Ҫ�Ų������:>");
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
//						printf("���ź����㱻ը���ˣ���Ϸ����!\n");
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
//				printf("����Ƿ����꣬����������!\n");
//			}
//			break;
//		case 2:
//			//printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			printf("��������Ҫ����׵�����:>");
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
//						printf("��ϲ�㣬���׳ɹ�!\n");
//						DisplayBoard(mine, row, col);
//						return;
//					}
//				}
//				else if (show[x][y] == '@')
//				{
//					printf("���������ѱ���ǹ�������������!\n");
//				}
//				else
//				{
//					printf("���������ѱ��Ų���������ף��޷���ǣ�����������!\n");
//				}
//			}
//			else
//			{
//				printf("����Ƿ����꣬����������!\n");
//			}
//			printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			break;
//		case 3:
//			//printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			printf("��������Ҫȡ������׵�����:>");
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
//						printf("��ϲ�㣬���׳ɹ�!\n");
//						DisplayBoard(mine, row, col);
//						return;
//					}
//				}
//				else if (show[x][y] == '*')
//				{
//					printf("��������δ����ǹ����޷�ȡ����ǣ�����������!\n");
//				}
//				else
//				{
//					printf("���������ѱ��Ų���������ף��޷�ȡ����ǣ�����������!\n");
//				}
//			}
//			else
//			{
//				printf("����Ƿ����꣬����������!\n");
//			}
//			printf("�����׸���Ϊ:%d����ǰ����׸���Ϊ:%d���ɹ�����׵ĸ���Ϊ:%d\n", EASY_COUNT, mine_num, cor_mine_num);
//			break;
//		default:
//			printf("ѡ�����������ѡ��!\n");
//			break;
//		}
//	} 		
//	if (win == row*col-EASY_COUNT)
//	{
//		printf("��ϲ�㣬���׳ɹ�!\n");
//		DisplayBoard(mine, row, col);
//
//	}
//}
		



