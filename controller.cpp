#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "map.h"
#include "snake.h"
#include "food.h"
#include "point.h"
using namespace std;

void controller::Game()
{
	Start();
	while (1)
	{
		Select();
		DrawGame();
		int tmp = PlayGame();
		switch (tmp)
		{

		case 1://重新开始
		{
			SetColor(6);
			system("cls");
			continue;
		}

		case 2://退出游戏
			SetCursorPosition(39, 31);
			return;
		}
	}
}

void controller::Start()
{
	SetWindowSize(40, 32);
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cInfo{};
	GetConsoleCursorInfo(hOutput, &cInfo); //获取现有光标信息
	cInfo.bVisible = false; //false为隐藏窗口,true为显示窗口
	SetConsoleCursorInfo(hOutput, &cInfo);  //重新设置光标信息
	//int screenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
	//int screenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
	//// 计算窗口的新位置
	//int windowWidth = 40;
	//int windowHeight = 32;
	//int x = (screenWidth - windowWidth) / 2;
	//int y = (screenHeight - windowHeight) / 2;
	//// 移动窗口到新位置
	//SetWindowPos(HWND, HWND_TOP, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	SetColor(2);//设定文本为绿色
	startinterface* start = new startinterface;
	start->Action();
	delete start;

	SetColor(3);//设定文本为蓝色
	SetCursorPosition(26, 22);
	cout << "Press any key to start...";
	SetCursorPosition(26, 23);
	system("pause");

}

void controller::Select()
{
	//初始化界面选择
	SetColor(6);
	SetCursorPosition(26, 22);
	cout << "                         ";
	SetCursorPosition(26, 23);
	cout << "                         ";
	SetCursorPosition(12, 21);
	cout << "请选择游戏难度：";
	SetCursorPosition(12, 22);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(54, 22);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "简单模式";
	SetCursorPosition(54, 24);
	SetColor(6);
	cout << "普通模式";
	SetCursorPosition(54, 26);
	cout << "困难模式";
	SetCursorPosition(54, 28);
	cout << "炼狱模式";
	SetCursorPosition(0, 31);
	score = 0;
	
	int ch;
	key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{

		case 72://UP上方向键
		{
			if (key > 1)
			{
				switch (key)
				{
				case 2:
				{
					SetCursorPosition(54, 24);
					SetColor(6);
					cout << "普通模式";
					SetCursorPosition(54, 22);
					SetBackColor();
					cout << "简单模式";
					key--;
					break;
				}
				case 3:
				{
					SetCursorPosition(54, 26);
					SetColor(6);
					cout << "困难模式";
					SetCursorPosition(54, 24);
					SetBackColor();
					cout << "普通模式";
					key--;
					break;
				}
				case 4:
				{
					SetCursorPosition(54, 28);
					SetColor(6);
					cout << "炼狱模式";
					SetCursorPosition(54, 26);
					SetBackColor();
					cout << "困难模式";
					key--;
					break;
				}
				}
			}
			break;
		}

		case 80://DOWN下方向键
		{
			if (key < 4)
			{
				switch (key)
				{
				case 1:
				{
					SetCursorPosition(54, 22);
					SetColor(6);
					cout << "简单模式";
					SetCursorPosition(54, 24);
					SetBackColor();
					cout << "普通模式";
					key++;
					break;
				}
				case 2:
				{
					SetCursorPosition(54, 24);
					SetColor(6);
					cout << "普通模式";
					SetCursorPosition(54, 26);
					SetBackColor();
					cout << "困难模式";
					key++;
					break;
				}
				case 3:
				{
					SetCursorPosition(54, 26);
					SetColor(6);
					cout << "困难模式";
					SetCursorPosition(54, 28);
					SetBackColor();
					cout << "炼狱模式";
					key++;
					break;
				}
				}
			}
			break;
		}

		case 13://ENTER键
		{
			flag = true;
			break;
		}

		default:
			break;
		}

		if (flag)
		{
			SetColor(6);
			SetCursorPosition(0, 31);
			break;
		}
	}
	switch (key)
	{
	case 1:
		speed = 135;
		break;
	case 2:
		speed = 100;
		break;
	case 3:
		speed = 70;
		break;
	case 4:
		speed = 40;
		break;
	}
	SetCursorPosition(12, 21);
	cout << "请选择游戏地图：";
	SetCursorPosition(54, 22);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "空空如也";
	SetCursorPosition(54, 24);
	SetColor(6);
	cout << "四分五裂";
	SetCursorPosition(54, 26);
	cout << "回字长廊";
	SetCursorPosition(54, 28);
	cout << "        ";
	SetCursorPosition(0, 31);

	mapkind = 1;
	flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{

		case 72://UP上方向键
		{
			if (mapkind > 1)
			{
				switch (mapkind)
				{
				case 2:
				{
					SetCursorPosition(54, 24);
					SetColor(6);
					cout << "四分五裂";
					SetCursorPosition(54, 22);
					SetBackColor();
					cout << "空空如也";
					mapkind--;
					break;
				}
				case 3:
				{
					SetCursorPosition(54, 26);
					SetColor(6);
					cout << "回字长廊";
					SetCursorPosition(54, 24);
					SetBackColor();
					cout << "四分五裂";
					mapkind--;
					break;
				}
				}
			}
			break;
		}

		case 80://DOWN下方向键
		{
			if (mapkind < 3)
			{
				switch (mapkind)
				{
				case 1:
				{
					SetCursorPosition(54, 22);
					SetColor(6);
					cout << "空空如也";
					SetCursorPosition(54, 24);
					SetBackColor();
					cout << "四分五裂";
					mapkind++;
					break;
				}
				case 2:
				{
					SetCursorPosition(54, 24);
					SetColor(6);
					cout << "四分五裂";
					SetCursorPosition(54, 26);
					SetBackColor();
					cout << "回字长廊";
					mapkind++;
					break;
				}
				}
			}
			break;
		}

		case 13://ENTER键
		{
			flag = true;
			break;
		}

		default:
			break;
		}

		if (flag)
		{
			SetColor(6);
			SetCursorPosition(0, 31);
			break;
		}
	}
}

void controller::DrawGame()
{
	system("cls");

	//绘制地图和侧边栏边框
	SetColor(3);
	map* init_map = new map;
	init_map->PrintInitMap(mapkind);
	delete init_map;

	//绘制侧边栏内容
	SetColor(7);
	SetCursorPosition(63, 2);
	cout << "Greedy Snake";
	SetCursorPosition(66, 3);
	cout << "贪吃蛇";
	SetCursorPosition(62, 5);
	cout << "难度：";
	SetCursorPosition(68, 5);
	switch (key)
	{
		
	case 1:
		cout << "简单模式";
		break;
	case 2:
		cout << "普通模式";
		break;
	case 3:
		cout << "困难模式";
		break;
	case 4:
		cout << "炼狱模式";
		break;
	default:
		break;
	}
	SetCursorPosition(62, 7);
	cout << "得分：";
	SetCursorPosition(68, 7);
	cout << "      0";
	SetCursorPosition(63, 13);
	cout << " 方向键移动";
	SetCursorPosition(63, 15);
	cout << " ESC键 暂停";

}

int controller::PlayGame()
{
	//初始化蛇和食物
	snake* csnake = new snake;
	food* cfood = new food;
	SetColor(6);
	csnake->InitSnake();
	srand((unsigned)time(NULL));
	cfood->DrawFood(*csnake, mapkind);

	//游戏循环
	while (!csnake->HitEdge(mapkind) && !csnake->HitItself())
	{
		if (!csnake->ChangeDirection())//是否调用菜单，并且检测是否改变方向
		{
			int tmp = Menu();
			switch (tmp)
			{
			case 1:
				SetCursorPosition(62, 21);
				cout << "      ";
				SetCursorPosition(65, 23);
				cout << "        ";
				SetCursorPosition(65, 25);
				cout << "        ";
				SetCursorPosition(65, 27);
				cout << "        ";
				break;
			case 2:
				delete csnake;
				delete cfood;
				return 1;
			case 3:
				delete csnake;
				delete cfood;
				return 2;
			}
		}
		if (csnake->GetFood(*cfood))
		{
			csnake->ExtendMove();
			UpdateScore(1);
			RewriteScore();
			cfood->DrawFood(*csnake, mapkind);
		}
		else
		{
			csnake->NormalMove();
		}
		if (csnake->GetBigFood(*cfood))
		{
			csnake->ExtendMove();
			UpdateScore(cfood->GetProgressBar() / (8 - key));
			RewriteScore();
		}
		if (cfood->GetBigFlag())
		{
			cfood->FlashBigFood();
		}
		Sleep(speed);
	}
	delete csnake;
	delete cfood;
	return GameOver();
}

int controller::Menu()
{
	SetCursorPosition(62 ,21);
	SetColor(11);
	cout << "菜单：";
	SetCursorPosition(65, 23);
	SetBackColor();
	cout << "继续游戏";
	SetCursorPosition(65, 25);
	SetColor(11);
	cout << "重新开始";
	SetCursorPosition(65, 27);
	SetColor(11);
	cout << "退出游戏";
	int ch = 1;
	int tmp_key = 1;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(65, 23);
					SetBackColor();
					cout << "继续游戏";
					SetCursorPosition(65, 25);
					SetColor(11);
					cout << "重新开始";
					SetCursorPosition(0, 31);
					tmp_key--;
					break;
				case 3:
					SetCursorPosition(65, 25);
					SetBackColor();
					cout << "重新开始";
					SetCursorPosition(65, 27);
					SetColor(11);
					cout << "退出游戏";
					SetCursorPosition(0, 31);
					tmp_key--;
					break;
				}
			}
			break;
		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(65, 25);
					SetBackColor();
					cout << "重新开始";
					SetCursorPosition(65, 23);
					SetColor(11);
					cout << "继续游戏";
					SetCursorPosition(0, 31);
					tmp_key++;
					break;
				case 2:
					SetCursorPosition(65, 27);
					SetBackColor();
					cout << "退出游戏";
					SetCursorPosition(65, 25);
					SetColor(11);
					cout << "重新开始";
					SetCursorPosition(0, 31);
					tmp_key++;
					break;
				}
			}
			break;
		case 13:
			return tmp_key;
		}

	}
	return 0;
}

void controller::UpdateScore(int tmp)
{
	score += key * 10 * tmp;
}

void controller::RewriteScore()
{
	SetCursorPosition(68, 7);
	SetColor(7);
	int tmp = score;
	int num = 0;
	while (tmp/=10)
		num++;
	num = 6 - num;
	while (num--)
		cout << " ";
	cout << score;
}

int controller::GameOver()
{
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	cout << " ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	SetCursorPosition(9, 9);
	cout << " ┃               Game Over !!!              ┃";
	Sleep(30);
	SetCursorPosition(9, 10);
	cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 11);
	cout << " ┃              很遗憾！你挂了              ┃";
	Sleep(30);
	SetCursorPosition(9, 12);
	cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 13);
	cout << " ┃            你的分数为：                  ┃";
	SetCursorPosition(40, 13);
	cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 15);
	cout << " ┃    是否再来一局？                        ┃";
	Sleep(30);
	SetCursorPosition(9, 16);
	cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 17);
	cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 18);
	cout << " ┃    嗯，好的        不了，还是学习有意思  ┃";
	Sleep(30);
	SetCursorPosition(9, 19);
	cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 20);
	cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(10, 21);
	cout << " ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	SetCursorPosition(15, 18);
	SetBackColor();
	cout << "嗯，好的 ";
	int ch;
	int tmp_key = 1;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75://LEFT
			if (tmp_key == 2)
			{
				SetCursorPosition(15, 18);
				SetBackColor();
				cout << "嗯，好的 ";
				SetCursorPosition(31, 18);
				SetColor(11);
				cout << "不了，还是学习有意思 ";
				tmp_key--;
			}
			break;
		case 77://RIGHT
			if (tmp_key == 1)
			{
				SetCursorPosition(15, 18);
				SetColor(11);
				cout << "嗯，好的 ";
				SetCursorPosition(31, 18);
				SetBackColor();
				cout << "不了，还是学习有意思 ";
				tmp_key++;
			}
			break;
		case 13://Enter
			return tmp_key;
		}
	}
}

