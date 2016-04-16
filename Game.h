#include<iostream>
#include<SDL.h>

class Game
{
	public:
		Game();//Game Constructor. Creates Window with default stuff.
		Game(int width, int height);//Specify Window stuff.
		bool run();//Runs the game. Using the private methods of game class. 
		~Game();//Destructor. We are dealing with dynamic memory.
		
	private:
		void render();//Graphic Stuff Here.
		void initGraphics();//Creates Textures and Stuff.
		void drawButton(int x, int y, int w, int h);//Draws a button w/ specs.
		void update();//Game Logic Here.
		void getInput();//Checks for User Input. Changes Game Values.
		void getMouseInput(SDL_Event* event);//Mouse Input is huge so it gets its own method.
		bool testBounds(int testX, int testY, int x, int y, int x2, int y2);//test bounds. makes buttons easier.
		void resetState();//Sets all states to false.
		
		//State Variables.
		bool startMenuState;
		bool gameMenuState;
		bool gameState;
		bool aboutState;
		bool settingsState;
		
		//SDL Variables.
		SDL_Window* myWindow;
		SDL_Surface* mySurface;
		SDL_Renderer* myRenderer;
		SDL_Texture* testTexture;
		SDL_Event myEvent;
		
		//Setting Variables.
		bool quitGame;
		int screenWidth;
		int screenHeight;
};