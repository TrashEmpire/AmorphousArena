#include<iostream>
#include<SDL.h>
#include"Game.h"

int main(int argc, char** argv)
{
	Game game = Game();
	
	while(game.run() == true)
	{
		
	}
	return 0;
}