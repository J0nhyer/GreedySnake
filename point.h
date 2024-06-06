#pragma once
#ifndef POINT_H
#define POINT_H

class point
{
public:
	point(){}
	point(const int x, const int y) :x(x), y(y){}
	void Print();
	void PrintCurcular();
	void Clear();
	int GetX();
	int GetY();
	void ChangePosition(const int x, const int y);
	bool operator== (point& Point)
	{
		return (Point.x == this->x && Point.y == this->y);
	}
private:
	int x, y;
};

#endif // POINT_H


