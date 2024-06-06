#include "point.h"
#include "tools.h"
#include <iostream>
using namespace std;

void point::Print()
{
	SetCursorPosition(x * 2, y);
	cout << "¡ö";
}

void point::PrintCurcular()
{
	SetCursorPosition(x * 2, y);
	cout << "¡ñ";
}

void point::Clear()
{
	SetCursorPosition(x * 2, y);
	cout << " ";
	SetCursorPosition(x * 2 + 1, y);
	cout << " ";
}

int point::GetX()
{
	return x;
}

int point::GetY()
{
	return y;
}

void point::ChangePosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
}
