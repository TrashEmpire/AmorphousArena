#include<iostream>
#include<SDL.h>
#include"Game.h"

int main(int argc, char** argv)
{
	Game game = Game();
	game.run();
	
	return 0;
}