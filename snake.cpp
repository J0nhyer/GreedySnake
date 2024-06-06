#include "snake.h"
#include "tools.h"
#include "map.h"
#include "controller.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

void snake::InitSnake()
{
	for (auto& point : Snake)
	{
		point.PrintCurcular();
		Sleep(50);
	}
}

void snake::ExtendMove()
{
	switch (direction)
	{
	case Direction::DOWN:
		Snake.emplace_back(point(Snake.back().GetX(), Snake.back().GetY() + 1));
		break;
	case Direction::UP:
		Snake.emplace_back(point(Snake.back().GetX(), Snake.back().GetY() - 1));
		break;
	case Direction::LEFT:
		Snake.emplace_back(point(Snake.back().GetX() - 1, Snake.back().GetY()));
		break;
	case Direction::RIGHT:
		Snake.emplace_back(point(Snake.back().GetX() + 1, Snake.back().GetY()));
		break;
	default:
		break;
	}
	SetColor(6);
	Snake.back().PrintCurcular();
}

void snake::NormalMove()
{
	ExtendMove();
	Snake.front().Clear();
	Snake.pop_front();
}

bool snake::HitEdge(int mapkind)
{
	map* Map = new map;
	switch (mapkind)
	{
	case 1:
		for (auto& point : Map->initmap)
		{
			if (Snake.back().GetX() == point.GetX() && Snake.back().GetY() == point.GetY())
			{
				delete Map;
				return true;
			}
		}
	case 2:
		for (auto& point : Map->map1)
		{
			if (Snake.back().GetX() == point.GetX() && Snake.back().GetY() == point.GetY())
			{
				delete Map;
				return true;
			}
		}
	case 3:
		for (auto& point : Map->map2)
		{
			if (Snake.back().GetX() == point.GetX() && Snake.back().GetY() == point.GetY())
			{
				delete Map;
				return true;
			}
		}
	}
	delete Map;
	return false;
}

bool snake::HitItself()
{
	deque<point>::size_type cnt = 1;
	for (auto& point : Snake)
	{
		if (!(point == Snake.back()))
		{
			cnt++;
		}
	}
	if (cnt == Snake.size())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool snake::ChangeDirection()
{
	if (_kbhit())
	{
		char ch;
		ch = _getch();
		switch (ch)
		{
		case -32:
		{
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (direction != Direction::DOWN)
					direction = Direction::UP;
				break;
			case 75:
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77:
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			case 80:
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			}
			return true;
		}
		case 27://ESC
			return false;
		default:
			return true;
		}
	}
	return true;
}

bool snake::GetFood(food& cfood)
{
	//SetCursorPosition(1, 0);
	//cout << cfood.x << " " << Snake.back().GetX();
	if ((cfood.x == Snake.back().GetX()) && (cfood.y == Snake.back().GetY()))
	{
		return true;
	}
	return false;
}

bool snake::GetBigFood(food& cfood)
{
	if ((cfood.big_x == Snake.back().GetX()) && (cfood.big_y == Snake.back().GetY()))
	{
		cfood.big_flag = false;
		//cfood.flash_flag = false;
		SetCursorPosition(1, 0);
		cout << "                                          ";
		return true;
	}
	return false;
}
