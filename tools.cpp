#define _CRT_SECURE_NO_WARNINGS
#include "tools.h"
#include <Windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines)
{
	system("title 贪吃蛇");
	char cmd[30];
	sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
	system(cmd);
}

void SetCursorPosition(const int x, const int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}
