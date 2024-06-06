#include "map.h"
#include <Windows.h>

void map::PrintInitMap(int mapkind)
{
	switch (mapkind)
	{
	case 1:
		for (auto& point : initmap)
		{
			point.Print();
			Sleep(10);
		}
		break;
	case 2:
		for (auto& point : map1)
		{
			point.Print();
			Sleep(10);
		}
		break;
	case 3:
		for (auto& point : map2)
		{
			point.Print();
			Sleep(10);
		}
		break;
	}
}
