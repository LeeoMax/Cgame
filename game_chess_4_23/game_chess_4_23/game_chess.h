#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//符号的定义，N*N的棋盘
#define ROW 3
#define COL 3

//函数声明

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void DisplayBoard(char board[ROW][COL],int row,int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//返回‘x’--玩家赢
//返回 'o' --电脑赢
//返回‘Q’--平局
//返回 'C' --游戏继续
char IsWin(char board[ROW][COL], int row, int col);
