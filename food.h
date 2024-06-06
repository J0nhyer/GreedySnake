#pragma once
#ifndef FOOD_H
#define FOOD_H

#include "snake.h"

class snake;
class food
{
public:
	food() :cnt(0), x(0), y(0), big_x(0), big_y(0), progress_bar(0), big_flag(false), flash_flag(false) {}
	void DrawFood(snake&, int);
	void DrawBigFood(snake&, int);
	int GetCnt();
	void FlashBigFood();
	bool GetBigFlag();
	int GetProgressBar();
private:
	int cnt;
	int x, y;
	int	big_x, big_y;
	int	progress_bar;
	bool big_flag;
	bool flash_flag;
	friend class snake;
};

#endif // FOOD_H



