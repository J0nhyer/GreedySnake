#pragma once
#ifndef STARTINTERFACE_H
#define STARTINTERFACE_H

#include <deque>
#include <vector>
#include "point.h"
using namespace std;

class startinterface
{
public:
	startinterface() :speed(50)
	{
		startsnake.emplace_back(point(0, 14));//ÒÆ¶¯Ð¡Éß
		startsnake.emplace_back(point(1, 14));
		startsnake.emplace_back(point(2, 15));
		startsnake.emplace_back(point(3, 16));
		startsnake.emplace_back(point(4, 17));
		startsnake.emplace_back(point(5, 18));
		startsnake.emplace_back(point(6, 17));
		startsnake.emplace_back(point(7, 16));
		startsnake.emplace_back(point(8, 15));
		startsnake.emplace_back(point(9, 14));

        textsnake.emplace_back(point(-26, 14));//S
        textsnake.emplace_back(point(-25, 14));
        textsnake.emplace_back(point(-27, 15));
        textsnake.emplace_back(point(-26, 16));
        textsnake.emplace_back(point(-25, 17));
        textsnake.emplace_back(point(-27, 18));
        textsnake.emplace_back(point(-26, 18));

        textsnake.emplace_back(point(-23, 14));//N
        textsnake.emplace_back(point(-23, 15));
        textsnake.emplace_back(point(-23, 16));
        textsnake.emplace_back(point(-23, 17));
        textsnake.emplace_back(point(-23, 18));
        textsnake.emplace_back(point(-22, 15));
        textsnake.emplace_back(point(-21, 16));
        textsnake.emplace_back(point(-20, 17));
        textsnake.emplace_back(point(-19, 14));
        textsnake.emplace_back(point(-19, 15));
        textsnake.emplace_back(point(-19, 16));
        textsnake.emplace_back(point(-19, 17));
        textsnake.emplace_back(point(-19, 18));

        textsnake.emplace_back(point(-17, 18));//A
        textsnake.emplace_back(point(-16, 17));
        textsnake.emplace_back(point(-15, 16));
        textsnake.emplace_back(point(-14, 15));
        textsnake.emplace_back(point(-14, 16));
        textsnake.emplace_back(point(-13, 14));
        textsnake.emplace_back(point(-13, 16));
        textsnake.emplace_back(point(-12, 15));
        textsnake.emplace_back(point(-12, 16));
        textsnake.emplace_back(point(-11, 16));
        textsnake.emplace_back(point(-10, 17));
        textsnake.emplace_back(point(-9, 18));

        textsnake.emplace_back(point(-7, 14));//K
        textsnake.emplace_back(point(-7, 15));
        textsnake.emplace_back(point(-7, 16));
        textsnake.emplace_back(point(-7, 17));
        textsnake.emplace_back(point(-7, 18));
        textsnake.emplace_back(point(-6, 16));
        textsnake.emplace_back(point(-5, 15));
        textsnake.emplace_back(point(-5, 17));
        textsnake.emplace_back(point(-4, 14));
        textsnake.emplace_back(point(-4, 18));

        textsnake.emplace_back(point(-2, 14));//E
        textsnake.emplace_back(point(-2, 15));
        textsnake.emplace_back(point(-2, 16));
        textsnake.emplace_back(point(-2, 17));
        textsnake.emplace_back(point(-2, 18));
        textsnake.emplace_back(point(-1, 14));
        textsnake.emplace_back(point(-1, 16));
        textsnake.emplace_back(point(-1, 18));
        textsnake.emplace_back(point(0, 14));
        textsnake.emplace_back(point(0, 16));
        textsnake.emplace_back(point(0, 18));
	}

	void PrintFirst();
	void PrintSecond();
	void PrintThird();
	void PrintText();
	void ClearText();
	void Action();
private:
	deque<point> startsnake;
	vector<point> textsnake;
    int speed;
};

#endif // STARTINTERFACE_H


