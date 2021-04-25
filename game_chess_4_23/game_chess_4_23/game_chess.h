#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//���ŵĶ��壬N*N������
#define ROW 3
#define COL 3

//��������

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL],int row,int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//���ء�x��--���Ӯ
//���� 'o' --����Ӯ
//���ء�Q��--ƽ��
//���� 'C' --��Ϸ����
char IsWin(char board[ROW][COL], int row, int col);
