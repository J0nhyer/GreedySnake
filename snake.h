#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"
#include "map.h"

using namespace std;

class food;
class map;
class snake
{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };
	snake()
	{
		Snake.emplace_back(point(14, 8));
		Snake.emplace_back(point(15, 8));
		Snake.emplace_back(point(16, 8));
		direction = Direction::DOWN;
	}
	void InitSnake();
	void ExtendMove();
	void NormalMove();
	bool HitEdge(int);
	bool HitItself();
	bool ChangeDirection();
	bool GetFood(food&);
	bool GetBigFood(food&);
private:
	deque<point> Snake;
	Direction direction;
	friend class food;
	friend class map;
};

#endif // SNAKE_H


