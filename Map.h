#include<iostream>
#include<SDL.h>

class Map
{
	public:
		Map();//Constructor. Sets to default Map.
		int getMapValue(int x, int y);//Placed from top left corner to bottom right.
		void setMapValue(int x, int y, int set);//Set a value in the map.
		int myMap[24][12];
	
};