#include "startinterface.h"
#include <Windows.h>;

void startinterface::PrintFirst()//С�߳���
{
	for (auto& point : startsnake)
	{
		point.Print();
		Sleep(speed);
	}
}

void startinterface::PrintSecond()//С���ƶ�����ʧ
{
    for (int i = 10; i != 40; ++i) //��ͷ��Ҫ��10�ƶ���40
    {
        /*������ͷ����һ��λ�ã�������ѹ��startsnake�У����Ƴ���������βȥ��*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake.emplace_back(point(i, j));
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();
        Sleep(speed);
    }
}

void startinterface::PrintThird()//��ĸSNAKE����
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
