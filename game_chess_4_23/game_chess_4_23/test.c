#define _CRT_SECURE_NO_WARNINGS 1

#include"game_chess.h"
void menu()
{
	printf("********* ��������Ϸ *********\n");
	printf("*********   1.play   *********\n");
	printf("*********   0.exit   *********\n");
	printf("******************************\n");

}
void game()
{
	//�洢����
	char board[ROW][COL];
	char ret = 0;
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	
	while (1)
	{
		//�����
		PlayerMove(board, ROW, COL);
		//��ӡ����
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ��
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		break;
		//������
		ComputerMove(board, ROW, COL);
		//��ӡ����
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		break;
	}
	if (ret == 'x')
	{
		printf("��ϲ�㣬���Ӯ��!\n");
	}
	if (ret == 'o')
	{
		printf("���ź�������Ӯ��!\n");
	}
	if (ret == 'Q')
	{
		printf("���ƽ��!\n");
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
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default:
			printf("�����������������!\n");
			break;
		}
	}while (input);

	return 0;

}