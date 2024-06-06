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

		case 1://���¿�ʼ
		{
			SetColor(6);
			system("cls");
			continue;
		}

		case 2://�˳���Ϸ
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
	GetConsoleCursorInfo(hOutput, &cInfo); //��ȡ���й����Ϣ
	cInfo.bVisible = false; //falseΪ���ش���,trueΪ��ʾ����
	SetConsoleCursorInfo(hOutput, &cInfo);  //�������ù����Ϣ
	//int screenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
	//int screenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
	//// ���㴰�ڵ���λ��
	//int windowWidth = 40;
	//int windowHeight = 32;
	//int x = (screenWidth - windowWidth) / 2;
	//int y = (screenHeight - windowHeight) / 2;
	//// �ƶ����ڵ���λ��
	//SetWindowPos(HWND, HWND_TOP, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	SetColor(2);//�趨�ı�Ϊ��ɫ
	startinterface* start = new startinterface;
	start->Action();
	delete start;

	SetColor(3);//�趨�ı�Ϊ��ɫ
	SetCursorPosition(26, 22);
	cout << "Press any key to start...";
	SetCursorPosition(26, 23);
	system("pause");

}

void controller::Select()
{
	//��ʼ������ѡ��
	SetColor(6);
	SetCursorPosition(26, 22);
	cout << "                         ";
	SetCursorPosition(26, 23);
	cout << "                         ";
	SetCursorPosition(12, 21);
	cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(12, 22);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(54, 22);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "��ģʽ";
	SetCursorPosition(54, 24);
	SetColor(6);
	cout << "��ͨģʽ";
	SetCursorPosition(54, 26);
	cout << "����ģʽ";
	SetCursorPosition(54, 28);
	cout << "����ģʽ";
	SetCursorPosition(0, 31);
	score = 0;
	
	int ch;
	key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{

		case 72://UP�Ϸ����
		{
			if (key > 1)
			{
				switch (key)
				{
				case 2:
				{
					SetCursorPosition(54, 24);
					SetColor(6);
					cout << "��ͨģʽ";
					SetCursorPosition(54, 22);
					SetBackColor();
					cout << "��ģʽ";
					key--;
					break;
				}
				case 3:
				{
					SetCursorPosition(54, 26);
					SetColor(6);
					cout << "����ģʽ";
					SetCursorPosition(54, 24);
					SetBackColor();
					cout << "��ͨģʽ";
					key--;
					break;
				}
				case 4:
				{
					SetCursorPosition(54, 28);
					SetColor(6);
					cout << "����ģʽ";
					SetCursorPosition(54, 26);
					SetBackColor();
					cout << "����ģʽ";
					key--;
					break;
				}
				}
			}
			break;
		}

		case 80://DOWN�·����
		{
			if (key < 4)
			{
				switch (key)
				{
				case 1:
				{
					SetCursorPosition(54, 22);
					SetColor(6);
					cout << "��ģʽ";
					SetCursorPosition(54, 24);
					SetBackColor();
					cout << "��ͨģʽ";
					key++;
					break;
				}
				case 2:
				{
					SetCursorPosition(54, 24);
					SetColor(6);
					cout << "��ͨģʽ";
					SetCursorPosition(54, 26);
					SetBackColor();
					cout << "����ģʽ";
					key++;
					break;
				}
				case 3:
				{
					SetCursorPosition(54, 26);
					SetColor(6);
					cout << "����ģʽ";
					SetCursorPosition(54, 28);
					SetBackColor();
					cout << "����ģʽ";
					key++;
					break;
				}
				}
			}
			break;
		}

		case 13://ENTER��
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
	cout << "��ѡ����Ϸ��ͼ��";
	SetCursorPosition(54, 22);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "�տ���Ҳ";
	SetCursorPosition(54, 24);
	SetColor(6);
	cout << "�ķ�����";
	SetCursorPosition(54, 26);
	cout << "���ֳ���";
	SetCursorPosition(54, 28);
	cout << "        ";
	SetCursorPosition(0, 31);

	mapkind = 1;
	flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{

		case 72://UP�Ϸ����
		{
			if (mapkind > 1)
			{
				switch (mapkind)
				{
				case 2:
				{
					SetCursorPosition(54, 24);
					SetColor(6);
					cout << "�ķ�����";
					SetCursorPosition(54, 22);
					SetBackColor();
					cout << "�տ���Ҳ";
					mapkind--;
					break;
				}
				case 3:
				{
					SetCursorPosition(54, 26);
					SetColor(6);
					cout << "���ֳ���";
					SetCursorPosition(54, 24);
					SetBackColor();
					cout << "�ķ�����";
					mapkind--;
					break;
				}
				}
			}
			break;
		}

		case 80://DOWN�·����
		{
			if (mapkind < 3)
			{
				switch (mapkind)
				{
				case 1:
				{
					SetCursorPosition(54, 22);
					SetColor(6);
					cout << "�տ���Ҳ";
					SetCursorPosition(54, 24);
					SetBackColor();
					cout << "�ķ�����";
					mapkind++;
					break;
				}
				case 2:
				{
					SetCursorPosition(54, 24);
					SetColor(6);
					cout << "�ķ�����";
					SetCursorPosition(54, 26);
					SetBackColor();
					cout << "���ֳ���";
					mapkind++;
					break;
				}
				}
			}
			break;
		}

		case 13://ENTER��
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

	//���Ƶ�ͼ�Ͳ�����߿�
	SetColor(3);
	map* init_map = new map;
	init_map->PrintInitMap(mapkind);
	delete init_map;

	//���Ʋ��������
	SetColor(7);
	SetCursorPosition(63, 2);
	cout << "Greedy Snake";
	SetCursorPosition(66, 3);
	cout << "̰����";
	SetCursorPosition(62, 5);
	cout << "�Ѷȣ�";
	SetCursorPosition(68, 5);
	switch (key)
	{
		
	case 1:
		cout << "��ģʽ";
		break;
	case 2:
		cout << "��ͨģʽ";
		break;
	case 3:
		cout << "����ģʽ";
		break;
	case 4:
		cout << "����ģʽ";
		break;
	default:
		break;
	}
	SetCursorPosition(62, 7);
	cout << "�÷֣�";
	SetCursorPosition(68, 7);
	cout << "      0";
	SetCursorPosition(63, 13);
	cout << " ������ƶ�";
	SetCursorPosition(63, 15);
	cout << " ESC�� ��ͣ";

}

int controller::PlayGame()
{
	//��ʼ���ߺ�ʳ��
	snake* csnake = new snake;
	food* cfood = new food;
	SetColor(6);
	csnake->InitSnake();
	srand((unsigned)time(NULL));
	cfood->DrawFood(*csnake, mapkind);

	//��Ϸѭ��
	while (!csnake->HitEdge(mapkind) && !csnake->HitItself())
	{
		if (!csnake->ChangeDirection())//�Ƿ���ò˵������Ҽ���Ƿ�ı䷽��
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
	cout << "�˵���";
	SetCursorPosition(65, 23);
	SetBackColor();
	cout << "������Ϸ";
	SetCursorPosition(65, 25);
	SetColor(11);
	cout << "���¿�ʼ";
	SetCursorPosition(65, 27);
	SetColor(11);
	cout << "�˳���Ϸ";
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
					cout << "������Ϸ";
					SetCursorPosition(65, 25);
					SetColor(11);
					cout << "���¿�ʼ";
					SetCursorPosition(0, 31);
					tmp_key--;
					break;
				case 3:
					SetCursorPosition(65, 25);
					SetBackColor();
					cout << "���¿�ʼ";
					SetCursorPosition(65, 27);
					SetColor(11);
					cout << "�˳���Ϸ";
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
					cout << "���¿�ʼ";
					SetCursorPosition(65, 23);
					SetColor(11);
					cout << "������Ϸ";
					SetCursorPosition(0, 31);
					tmp_key++;
					break;
				case 2:
					SetCursorPosition(65, 27);
					SetBackColor();
					cout << "�˳���Ϸ";
					SetCursorPosition(65, 25);
					SetColor(11);
					cout << "���¿�ʼ";
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
	cout << " ������������������������������������������������������������������������������������";
	Sleep(30);
	SetCursorPosition(9, 9);
	cout << " ��               Game Over !!!              ��";
	Sleep(30);
	SetCursorPosition(9, 10);
	cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 11);
	cout << " ��              ���ź��������              ��";
	Sleep(30);
	SetCursorPosition(9, 12);
	cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 13);
	cout << " ��            ��ķ���Ϊ��                  ��";
	SetCursorPosition(40, 13);
	cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 15);
	cout << " ��    �Ƿ�����һ�֣�                        ��";
	Sleep(30);
	SetCursorPosition(9, 16);
	cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 17);
	cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 18);
	cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��";
	Sleep(30);
	SetCursorPosition(9, 19);
	cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 20);
	cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(10, 21);
	cout << " ������������������������������������������������������������������������������������";
	SetCursorPosition(15, 18);
	SetBackColor();
	cout << "�ţ��õ� ";
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
				cout << "�ţ��õ� ";
				SetCursorPosition(31, 18);
				SetColor(11);
				cout << "���ˣ�����ѧϰ����˼ ";
				tmp_key--;
			}
			break;
		case 77://RIGHT
			if (tmp_key == 1)
			{
				SetCursorPosition(15, 18);
				SetColor(11);
				cout << "�ţ��õ� ";
				SetCursorPosition(31, 18);
				SetBackColor();
				cout << "���ˣ�����ѧϰ����˼ ";
				tmp_key++;
			}
			break;
		case 13://Enter
			return tmp_key;
		}
	}
}

