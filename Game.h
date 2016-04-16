#include<iostream>
#include<SDL.h>

class Game
{
	public:
		Game();//Game Constructor. Creates Window with default stuff.
		Game(int width, int height);//Specify Window stuff.
		void run();//Runs the game. Using the private methods of game class. 
		~Game();//Destructor. We are dealing with dynamic memory.
		
	private:
		void render();//Graphic Stuff Here.
		void update();//Game Logic Here.
		void getInput();//Checks for User Input. Changes Game Values.
		
		SDL_Window* myWindow;
		SDL_Surface* mySurface;
		SDL_Renderer* myRenderer;
		
		int screenWidth;
		int screenHeight;
};