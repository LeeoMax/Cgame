#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("**********  ɨ����Ϸ  ***********\n");
	printf("********** 2.��Ϸ���� ***********\n");
	printf("********** 1.��ʼ��Ϸ ***********\n");
	printf("********** 0.�˳���Ϸ ***********\n");
	printf("*********************************\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };//�洢���úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//�洢�Ų�����׵���Ϣ

	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//�Ų���
	FindMine(mine, show, ROW, COL);

}
int main()
{

	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 2:
			printf("1.����̵�ʱ���ڸ��ݵ�����ӳ��ֵ������ҳ����з��׸��ӣ�ͬʱ������ף��ȵ�һ���׼�ȫ�̽��䡣\n");
			printf("2.��ɨ�׹����пɱ���׻���ȡ���ѱ�ǵ��ס�\n");
			printf("3.Ϊ����������У����������ĵ�һ������������ף����ᱻը����\n");
			break;
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default:
			printf("ѡ���������������!\n");
			break;
		}
	} while (input);
	return 0;

}