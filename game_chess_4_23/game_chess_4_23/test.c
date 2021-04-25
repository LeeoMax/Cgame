#define _CRT_SECURE_NO_WARNINGS 1

#include"game_chess.h"
void menu()
{
	printf("********* 三子棋游戏 *********\n");
	printf("*********   1.play   *********\n");
	printf("*********   0.exit   *********\n");
	printf("******************************\n");

}
void game()
{
	//存储数据
	char board[ROW][COL];
	char ret = 0;
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	
	while (1)
	{
		//玩家走
		PlayerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢了
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		break;
		//电脑走
		ComputerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		break;
	}
	if (ret == 'x')
	{
		printf("恭喜你，玩家赢了!\n");
	}
	if (ret == 'o')
	{
		printf("很遗憾，电脑赢了!\n");
	}
	if (ret == 'Q')
	{
		printf("打成平局!\n");
	}
	DisplayBoard(board, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	}while (input);

	return 0;

}