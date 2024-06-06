#include "startinterface.h"
#include <Windows.h>;

void startinterface::PrintFirst()//小蛇出现
{
	for (auto& point : startsnake)
	{
		point.Print();
		Sleep(speed);
	}
}

void startinterface::PrintSecond()//小蛇移动至消失
{
    for (int i = 10; i != 40; ++i) //蛇头需要从10移动到40
    {
        /*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake.emplace_back(point(i, j));
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();
        Sleep(speed);
    }
}

void startinterface::PrintThird()//字母SNAKE出现
{
    while (!startsnake.empty() || textsnake.back().GetX() < 33)
    {
        if (!startsnake.empty())
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();
        PrintText();
        Sleep(speed);
    }
}

void startinterface::PrintText()
{
    for (auto& point : textsnake)
    {
        if (point.GetX() >= 0)
        {
            point.Print();
        }
    }
}

void startinterface::ClearText()
{
    for (auto& point : textsnake)
    {
        if (point.GetX() >= 0)
        {
            point.Clear();
        }
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void startinterface::Action()
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}
