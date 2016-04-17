#include<iostream>
#include<SDL.h>
#include"Game.h"
#include"Map.h"

int main(int argc, char** argv)
{
	Game game = Game();
	Map map = Map();
	std::cout << map.getMapValue(4, 1) << std::endl;
	while(game.run() == true)
	{
		
	}
	return 0;
}