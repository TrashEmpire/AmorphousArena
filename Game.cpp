#include"Game.h"
#include<iostream>
#include<SDL.h>

Game::Game()
{
	screenWidth = 640;
	screenHeight = 480;
	
	myWindow = NULL;
	mySurface = NULL;
	
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Something went wrong with SDL Initialization..." << std::endl;
	}
	else
	{
		myWindow = SDL_CreateWindow("Amorphous Arena!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if(myWindow == NULL)
		{
			std::cout << "SDL Could Not Create a Window." << std::endl;
		}
		else
		{
			myRenderer = SDL_CreateRenderer( myWindow, -1, SDL_RENDERER_ACCELERATED );
			//Don't think I need surfaces.
			//mySurface = SDL_GetWindowSurface( myWindow );
		}
	}
	
}

void Game::run()
{
	//Starting Point of Game.
	
	//Practice Code Here.
	/*SDL_Rect bruh; 
	bruh.x = 100;
	bruh.y = 100;
	bruh.w = 100;
	bruh.h = 100;
	
	SDL_SetRenderDrawColor( myRenderer, 0, 0, 0, 255);
	//SDL_FillRect(mySurface, NULL, SDL_MapRGB(mySurface->format, 0x00, 0x00, 0x00));
	SDL_RenderClear( myRenderer );
	
	SDL_SetRenderDrawColor( myRenderer, 255, 0, 0, 255);
	SDL_RenderFillRect( myRenderer, &bruh );
	
	SDL_RenderPresent( myRenderer );
	//SDL_UpdateWindowSurface ( myWindow );
	SDL_Delay(2000);
	*/
	
}

void Game::update()
{
	//Game Logic Here.
	
}

void Game::render()
{
	//Do Graphics Stuff Here.
}

void Game::getInput()
{
	//Poll for user input here.
}

Game::~Game()
{
	//Destructor.
	SDL_DestroyRenderer( myRenderer );
	SDL_DestroyWindow( myWindow );
	SDL_Quit();
}