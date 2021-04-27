#define _CRT_SECURE_NO_WARNINGS 1

#include"game_chess.h"
//初始化棋盘，将棋盘中所有要落子的地方初始化为空格
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


//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			
//			printf(" %c ", board[i][j]);
//			if (j < col - 1)
//				printf("|");
//		}
//		printf("\n");
//		if (i < row - 1)
//		{
//			int j = 0;
//			for (j = 0; j < col; j++)
//			{
//				printf("---");
//				if (j < col - 1)
//					printf("|");
//			}
//			printf("\n");
//
//		}
//
//	}
//
//}
//打印棋盘，将棋盘打印成N*N方格


//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	printf(" --- --- ---\n");
//	for (i = 0; i < row; i++)
//	{
//		printf("| %c | %c | %c |\n",board[i][0],board[i][1],board[i][2]);
//		if (i < row - 1)
//		{
//			printf("|---|---|---|\n");
//		}
//	}
//	printf(" --- --- ---\n");
//}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	printf(" ");
	for (i = 0; i < col; i++)
	{
		printf("%4d", i + 1);
	}
	printf("\n");
	printf("  ");
	for (i = 0; i < col; i++)
	{
		printf(" ---");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		int j = 0;
		printf("%2d", i + 1);
		for (j = 0; j < col; j++)
		{
	
			printf("|");
			printf(" %c ", board[i][j]);
		}
		printf("|");
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			printf("  ");
			for (j = 0; j < col; j++)
			{
				printf("|");
				printf("---");
			}
			printf("|");
			printf("\n");

		}
	}
	printf("  ");
	for (i = 0; i < col; i++)
	{
		printf(" ---");
	}
	printf("\n");
}
//玩家下棋，落子为x
//玩家要先输入坐标，然后判断坐标的合法性，最后再判断坐标是否被占用
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要落子的坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}			
			else
			{
				printf("坐标已被占用，请重新输入!\n");
			}	
		}
		else
		{
			printf("输入非法坐标，请重新输入!\n");
		}
	}
}

//电脑下棋，落子为o
//电脑随机产生一个坐标，判断该坐标是否被占用
void ComputerMove(char board[ROW][COL], int row, int col)
{
	
	printf("电脑走:>\n");
	while (1)
	{
		int x = rand() % row;//随机产生的坐标值在0~row-1之间
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'o';
			break;
		}
	}
}




//判断棋盘是否满了,满了返回1，没满返回0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}


char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	////判断三子棋
	////横三行
	//for (i = 0; i < row; i++)
	//{
	//	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
	//	{
	//		return board[i][1];
	//	}
	//}
	////竖三列
	//for (i = 0; i < col; i++)
	//{
	//	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
	//	{
	//		return board[1][i];
	//	}
	//}
	////对角线
	//if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	//{
	//	return board[1][1];
	//}
	//if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	//{
	//	return board[1][1];
	//}

	//判断多子棋
	//横行
	/*for (i = 0; i < row; i++)
	{
		int j = 0;
		int count = 0;
		for (j = 0; j < col-1; j++)
		{
			count++;
			if (board[i][j] == ' ' || board[i][j] != board[i][j + 1])
			{
				count = 0;
			}
			if (count == ROW - 1)
			{
				return board[i][j];
			}
		}	
	}*/

	for (i = 0; i < row; i++)
	{
		int count1 = 0;
		int j = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i][j + 1])
			{
				count1++;
			}
			if (count1 == ROW - 1)
			{
				return board[i][j];
			}
		}
	}

	//竖列
	/*for (j = 0; j < col; j++)
	{
		int count = 0;
		for (i = 0; i < row - 1; i++)
		{
			count++;
			if (board[i][j] == ' ' || board[i][j] != board[i + 1][j])
			{
				count = 0;
			}
			if (count == ROW - 1)
			{
				return board[i][j];
			}
		}
	}*/


	for (j = 0; j < col; j++)
	{
		int count2 = 0;
		for (i = 0; i < row - 1; i++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j])
			{
				count2++;
			}
			if (count2 == ROW - 1)
			{
				return board[i][j];
			}
		}
	}

	//对角线
	/*int count = 0;
	for (i = 0; i < row-1; i++)
	{
		count++;
		if (board[i][i] == ' ' || board[i][i] != board[i + 1][i + 1])
		{
			count = 0;
		}
		if (count == ROW - 1)
		{
			return board[i][i];
		}
	}*/



	int count3 = 0;
	for (i = 0; i < row-1; i++)
	{
		if (board[i][i] != ' ' && board[i][i] == board[i + 1][i + 1])
		{
			count3++;
		}
		if (count3 == ROW - 1)
		{
			return board[i][i];
		}
	}




	//for (i = 0; i < row-1; i++)
	//{
	//	count++;
	//	if (board[i][row -1 - i] == ' ' || board[i][row - 1 - i] != board[i + 1][row - i - 2])
	//	{
	//		count = 0;
	//	}
	//	if (count == ROW - 1)
	//	{
	//		return board[i][row -1 - i];
	//	}
	//}

	int count4 = 0;
	for (i = 0; i < row-1 ; i++)
	{
		if (board[i][row-1-i] != ' ' && board[i][row-1-i] == board[i+1][row-2-i])
		{
			count4 ++;
		}
		if (count4 == ROW - 1)
		{
			return board[i][row-1-i];
		}

	}

	int ret = 0;
	ret = IsFull(board, ROW, COL);
	if (ret == 1)
	{
		return 'Q';
	}

	return 'C';


}




