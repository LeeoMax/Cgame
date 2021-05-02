#define _CRT_SECURE_NO_WARNINGS 1

#include"game_sweep.h"

void menu()
{
	printf("*********************************\n");
	printf("**********   1.play   ***********\n");
	printf("**********   0.exit   ***********\n");
	printf("*********************************\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存储布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存储排查出的雷的信息

	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择:>");
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
			printf("选择错误，请重新输入!\n");
			break;
		}
	} while(input);
	return 0;

}




