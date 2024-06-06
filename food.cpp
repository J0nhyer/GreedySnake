#include "food.h"
#include "tools.h"
#include <iostream>
using namespace std;

void food::DrawFood(snake& csnake, int mapkind)
{
	map* cmap = new map;
	while (1)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2)
			tmp_x += 2;
		if (tmp_y < 2)
			tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.Snake)
		{
			if (point.GetX() == tmp_x && point.GetY() == tmp_y)
			{
				flag = true;
				break;
			}
		}
		switch (mapkind)
		{
		case 1:
			for (auto& point : cmap->initmap)
			{
				if (point.GetX() == tmp_x && point.GetY() == tmp_y)
				{
					flag = true;
					delete cmap;
					break;
				}
			}
			break;
		case 2:
			for (auto& point : cmap->map1)
			{
				if (point.GetX() == tmp_x && point.GetY() == tmp_y)
				{
					flag = true;
					delete cmap;
					break;
				}
			}
			break;
		case 3:
			for (auto& point : cmap->map2)
			{
				if (point.GetX() == tmp_x && point.GetY() == tmp_y)
				{
					flag = true;
					delete cmap;
					break;
				}
			}
			break;
		}
		if (flag)
		{
			continue;
		}
		x = tmp_x;
		y = tmp_y;
		SetCursorPosition(x * 2, y);
		SetColor(13);
		cout << "¡ï";
		++cnt;
		cnt %= 5;
		if (!cnt)
		{
			DrawBigFood(csnake, mapkind);
		}
		break;
	}
}

void food::DrawBigFood(snake& csnake, int mapkind)
{
	SetCursorPosition(6, 0);
	SetColor(11);
	cout << "------------------------------------------";
	progress_bar = 42;
	while (1)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2)
			tmp_x += 2;
		if (tmp_y < 2)
			tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.Snake)
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (point.GetX() == x && point.GetY() == y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			continue;
		}
		big_x = tmp_x;
		big_y = tmp_y;
		SetCursorPosition(2 * big_x, big_y);
		SetColor(18);
		cout << "¡ö";
		big_flag = true;
		flash_flag = true;
		break;
	}
}

int food::GetCnt()
{
	return cnt;
}

void food::FlashBigFood()
{
	SetCursorPosition(2 * big_x, big_y);
	SetColor(18);
	if (flash_flag)
	{
		cout << "  ";
		flash_flag = false;
	}
	else
	{
		cout << "¡ö";
		flash_flag = true;
	}
	SetCursorPosition(48, 0);
	SetColor(11);
	for (int i = 42; i >= progress_bar; i--)
		cout << "\b \b";
	progress_bar--;
	if (!progress_bar)
	{
		big_flag = false;
		SetCursorPosition(2 * big_x, big_y);
		cout << "  ";
	}
}

bool food::GetBigFlag()
{
	return big_flag;
}

int food::GetProgressBar()
{
	return progress_bar;
}
