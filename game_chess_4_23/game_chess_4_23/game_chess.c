#define _CRT_SECURE_NO_WARNINGS 1

#include"game_chess.h"
//��ʼ�����̣�������������Ҫ���ӵĵط���ʼ��Ϊ�ո�
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
//��ӡ���̣������̴�ӡ��N*N����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" ---");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		int j = 0;
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
			for (j = 0; j < col; j++)
			{
				printf("|");
				printf("---");
			}
			printf("|");
			printf("\n");

		}
	}
	for (i = 0; i < row; i++)
	{
		printf(" ---");
	}
	printf("\n");

}
//������壬����Ϊx
//���Ҫ���������꣬Ȼ���ж�����ĺϷ��ԣ�������ж������Ƿ�ռ��
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	while (1)
	{
		printf("������Ҫ���ӵ�����:>");
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
				printf("�����ѱ�ռ�ã�����������!\n");
			}	
		}
		else
		{
			printf("����Ƿ����꣬����������!\n");
		}
	}
}

//�������壬����Ϊo
//�����������һ�����꣬�жϸ������Ƿ�ռ��
void ComputerMove(char board[ROW][COL], int row, int col)
{
	
	printf("������:>\n");
	while (1)
	{
		int x = rand() % row;//�������������ֵ��0~row-1֮��
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'o';
			break;
		}
	}
}

//�ж������Ƿ�����,���˷���1��û������0
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
	////�ж�������
	////������
	//for (i = 0; i < row; i++)
	//{
	//	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
	//	{
	//		return board[i][1];
	//	}
	//}
	////������
	//for (i = 0; i < col; i++)
	//{
	//	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
	//	{
	//		return board[1][i];
	//	}
	//}
	////�Խ���
	//if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	//{
	//	return board[1][1];
	//}
	//if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	//{
	//	return board[1][1];
	//}

	//�ж϶�����
	//����
	for (i = 0; i < row; i++)
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
	}

	//����
	for (j = 0; j < col; j++)
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
	}

	//�Խ���
	int count = 0;
	for (i = 0; i < row; i++)
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
	}

	for (i = 0; i < row; i++)
	{
		count++;
		if (board[i][row - i] == ' ' || board[i][row - i] != board[i + 1][row - i - 1])
		{
			count = 0;
		}
		if (count == ROW - 1)
		{
			return board[i][row - i];
		}
	}

	int ret = 0;
	ret = IsFull(board, ROW, COL);
	if (ret == 1)
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}

}




