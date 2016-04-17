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
		//Graphics.
		void render();//Graphic Stuff Here.
		void initGraphics();//Creates Textures and Stuff.
		void drawMenu();//Draw the Start Menu.
		void drawAbout();//Draw the about Menu.
		void drawGameMenu();//Draw the Game Menu.
		void drawGame();//Draw the Game.
		void drawMap();//Draws a map to the screen. *DOES NOT PRESENT*
		
		//Game Logic.
		void update();//Game Logic Here.
		
		//Game Input.
		void getInput();//Checks for User Input. Changes Game Values.
		void getKeyInput(SDL_Keycode key);//Get Keyboard Input.
		void getMouseInput(SDL_Event* event);//Mouse Input is huge so it gets its own method.
		bool testBounds(int testX, int testY, int x, int y, int x2, int y2);//test bounds. makes buttons easier.
		void resetState();//Sets all states to false.
		
		//Logic Variables.
		int viewPosition;
		
		//State Variables.
		bool startMenuState;
		bool gameMenuState;
		bool gameState;
		bool aboutState;
		
		//SDL Variables.
		SDL_Window* myWindow;
		SDL_Surface* mySurface;
		SDL_Renderer* myRenderer;
		SDL_Event myEvent;
		
		//Textures.
		SDL_Texture* wallTile;
		SDL_Texture* floorTile;
		SDL_Texture* redTile;
		SDL_Texture* gameMenuText;
		SDL_Texture* returnButton;
		SDL_Texture* aboutText;
		SDL_Texture* amorArena;
		SDL_Texture* playGame;
		SDL_Texture* about;
		SDL_Texture* quit;
		
		//Setting Variables.
		bool quitGame;
		int screenWidth;
		int screenHeight;
};