#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("**********  扫雷游戏  ***********\n");
	printf("********** 2.游戏规则 ***********\n");
	printf("********** 1.开始游戏 ***********\n");
	printf("********** 0.退出游戏 ***********\n");
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
		case 2:
			printf("1.在最短的时间内根据点击格子出现的数字找出所有非雷格子，同时避免踩雷，踩到一个雷即全盘皆输。\n");
			printf("2.在扫雷过程中可标记雷或者取消已标记的雷。\n");
			printf("3.为了提升体验感，玩家在输入的第一个坐标如果是雷，不会被炸死。\n");
			break;
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
	} while (input);
	return 0;

}