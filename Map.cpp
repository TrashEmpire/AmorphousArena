#include"Map.h"
#include<iostream>
#include<SDL.h>

Map::Map()
{
	//Constructor.
	int theMap[24][12]=
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	
	for(int a = 0; a < 24; a++)
	{
		for(int b = 0;b < 12; b++)
		{
			myMap[a][b] = theMap[a][b];
		}
	}
}

int Map::getMapValue(int x, int y)
{
	return myMap[y][x];
}

void Map::setMapValue(int x, int y, int set)
{
	myMap[y][x] = set;
}