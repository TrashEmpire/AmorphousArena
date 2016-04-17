#include"Game.h"
#include"Map.h"
#include<iostream>
#include<SDL.h>

Game::Game()
{
	screenWidth = 640;
	screenHeight = 480;
	
	myWindow = NULL;
	mySurface = NULL;
	
	//Init SDL Stuff.
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		//In Case that causes Errors.
		std::cout << "Something went wrong with SDL Initialization..." << std::endl;
	}
	else
	{
		//Initialize the Window.
		myWindow = SDL_CreateWindow("Amorphous Arena!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if(myWindow == NULL)
		{
			//If that causes errors.
			std::cout << "SDL Could Not Create a Window." << std::endl;
		}
		else
		{
			//Initialize the renderer.
			myRenderer = SDL_CreateRenderer( myWindow, -1, SDL_RENDERER_ACCELERATED );
			if(myRenderer == NULL)
			{
				std::cout << "SDL Could Not Create a Renderer..." << std::endl;
			}
			//Don't think I need surfaces.
			//mySurface = SDL_GetWindowSurface( myWindow );
		}
	}
	
	resetState();
	startMenuState = true;
	quitGame = false;
	
	initGraphics();
	//End of Constructor Here.
}

Game::Game(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
	
	myWindow = NULL;
	myRenderer = NULL;
	
	//Init SDL.
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		//If that causes errors.
		std::cout << "Something went wrong with SDL Initialization..." << std::endl;
	}
	else
	{
		//Initialize the window.
		myWindow = SDL_CreateWindow("Amorphous Arena!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if( myWindow == NULL )
		{
			//if that causes errors.
			std::cout << "SDL could not create a window..." << std::endl;
		}
		else
		{
			//Init the renderer.
			myRenderer = SDL_CreateRenderer( myWindow, -1, SDL_RENDERER_ACCELERATED );
			if(myRenderer == NULL)
			{
				//if that causes errors.
				std::cout << "SDL Could not create a renderer..." << std::endl;
			}
		}
	}
	
	resetState();
	startMenuState = true;
	quitGame = false;
	
	initGraphics();
	//End of Constructor Here.
}

void Game::resetState()
{
	//resets States.
	startMenuState = false;
	gameMenuState = false;
	gameState = false;
	aboutState = false;
}

bool Game::run()
{
	//Starting Point of Game.
	if(quitGame == false)
	{
		update();
		render();
		getInput();
	}
	else if(quitGame == true)
	{
		return false;
	}
	return true;
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

void Game::initGraphics()
{
	//Load Textures.
	SDL_Surface* surf = NULL;
	
	//Title Texture.
	surf = SDL_LoadBMP("assets\\amorArena.bmp");
	amorArena = SDL_CreateTextureFromSurface( myRenderer, surf);
	SDL_FreeSurface(surf);
	
	//Play Game Button Texture.
	surf = SDL_LoadBMP("assets\\playGame.bmp");
	playGame = SDL_CreateTextureFromSurface( myRenderer, surf);
	SDL_FreeSurface( surf );
	
	//About Button Texture.
	surf = SDL_LoadBMP("assets\\about.bmp");
	about = SDL_CreateTextureFromSurface( myRenderer, surf );
	SDL_FreeSurface( surf );
	
	//Quit Button Texture.
	surf = SDL_LoadBMP("assets\\Quit.bmp");
	quit = SDL_CreateTextureFromSurface( myRenderer, surf );
	SDL_FreeSurface( surf );
	
	//Return Button Texture.
	surf = SDL_LoadBMP("assets\\return.bmp");
	returnButton = SDL_CreateTextureFromSurface( myRenderer, surf );
	SDL_FreeSurface( surf );
	
	//About Screen Texture.
	surf = SDL_LoadBMP("assets\\aboutScreen.bmp");
	aboutText = SDL_CreateTextureFromSurface( myRenderer, surf );
	SDL_FreeSurface( surf );
	
	//Game Menu Text Texture.
	surf = SDL_LoadBMP("assets\\gameMenu.bmp");
	gameMenuText = SDL_CreateTextureFromSurface( myRenderer, surf);
	SDL_FreeSurface( surf );
	
	//Wall Tile Texture.
	surf = SDL_LoadBMP("assets\\wallTile.bmp");
	wallTile = SDL_CreateTextureFromSurface( myRenderer, surf );
	SDL_FreeSurface( surf );
	
	//Floor Tile Texture.
	surf = SDL_LoadBMP("assets\\floorTile.bmp");
	floorTile = SDL_CreateTextureFromSurface( myRenderer, surf );
	SDL_FreeSurface( surf );
	
	//Red Tile Texture.
	surf = SDL_LoadBMP("assets\\redTile.bmp");
	redTile = SDL_CreateTextureFromSurface( myRenderer, surf );
	SDL_FreeSurface( surf );
}

void Game::render()
{
	//Do Graphics Stuff Here.
	
	//Depends on the state...
	if(startMenuState == true)
	{
		//Draw the Start Menu Here.
		drawMenu();
	}
	else if(aboutState == true)
	{
		//Draw the about menu.
		drawAbout();
	}
	else if(gameMenuState == true)
	{
		//Draw the game menu.
		drawGameMenu();
	}
	else if(gameState == true)
	{
		//Draw the game.
		drawGame();
	}
}

void Game::drawMenu()
{
	SDL_SetRenderDrawColor( myRenderer, 0, 0, 0, 255);
	SDL_RenderClear( myRenderer );
	
	SDL_Rect rect;
	
	//Amorphous Arena Title.
	rect.x=120;rect.y=50;rect.w=400;rect.h=100;
	SDL_RenderCopy( myRenderer, amorArena, NULL, &rect );
	
	//Play Game Button.
	rect.x=270;rect.y=200;rect.w=100;rect.h=50;
	SDL_RenderCopy( myRenderer, playGame, NULL, &rect );
	
	//About Button.
	rect.x=270;rect.y=275;rect.w=100;rect.h=50;
	SDL_RenderCopy( myRenderer, about, NULL, &rect);
	
	//Quit Button.
	rect.x=270;rect.y=350;rect.w=100;rect.h=50;
	SDL_RenderCopy( myRenderer, quit, NULL, &rect );
	
	SDL_RenderPresent( myRenderer );
}

void Game::drawAbout()
{
	SDL_SetRenderDrawColor( myRenderer, 0, 0, 0, 255);
	SDL_RenderClear( myRenderer );
	
	SDL_Rect rect;
	rect.x=50;rect.y=25;rect.w=500;rect.h=400;
	SDL_RenderCopy( myRenderer, aboutText, NULL, &rect );
	
	rect.x=270;rect.y=400;rect.w=100;rect.h=50;
	SDL_RenderCopy( myRenderer, returnButton, NULL, &rect);
	
	SDL_RenderPresent( myRenderer );
}

void Game::drawGameMenu()
{
	SDL_SetRenderDrawColor( myRenderer, 0, 0, 0, 255);
	SDL_RenderClear( myRenderer );
	
	SDL_Rect rect;
	rect.x=50;rect.y=25;rect.w=500;rect.h=400;
	SDL_RenderCopy( myRenderer, gameMenuText, NULL, &rect );
	
	rect.x=195;rect.y=400;rect.w=100;rect.h=50;
	SDL_RenderCopy( myRenderer, returnButton, NULL, &rect );
	
	rect.x=345;rect.y=400;rect.w=100;rect.h=50;
	SDL_RenderCopy( myRenderer, playGame, NULL, &rect );
	
	SDL_RenderPresent( myRenderer );
}

void Game::drawGame()
{
	SDL_SetRenderDrawColor( myRenderer, 0, 0, 0, 255);
	SDL_RenderClear( myRenderer );
	
	drawMap();
	
	SDL_RenderPresent( myRenderer );
}

void Game::drawMap()
{
	Map map = Map();
	
	int currentMapPosition = viewPosition;
	
	for(int a = currentMapPosition; a < currentMapPosition + 6; a++)
	{
		for(int b = 0; b < 12; b++)
		{
			int tileValue = map.getMapValue(b, a);
			int x = b;
			int y = a - currentMapPosition;
			//Create Position on screen.
			SDL_Rect rect;
			rect.x = x * 53;
			rect.y = (y * 53) + 53;
			rect.w=53;rect.h=53;
			
			//Decide with tile to use.
			switch(tileValue)
			{
				case 0:
					SDL_RenderCopy( myRenderer, floorTile, NULL, &rect);
					break;
				case 1:
					SDL_RenderCopy( myRenderer, wallTile, NULL, &rect);
					break;
				case 2:
					SDL_RenderCopy( myRenderer, redTile, NULL, &rect);
					break;
				default:
					std::cout << "Unknown Tile Value..." << std::endl;
					break;
			}
			
		}
	}
}

void Game::getInput()
{
	//Poll for user input here.
	if(SDL_PollEvent(&myEvent))
	{
		//If you quit the game.
		if(myEvent.type == SDL_QUIT)
		{
			quitGame = true;
		}
		
		//If you click the mouse.
		if(myEvent.type == SDL_MOUSEBUTTONDOWN)
		{
			//Did you click the mouse?
			getMouseInput(&myEvent);
		}
		
		//If you hit a key.
		if(myEvent.type == SDL_KEYDOWN)
		{
			//Did you press a key?
			getKeyInput(myEvent.key.keysym.sym);
		}
	}
}

void Game::getKeyInput(SDL_Keycode key)
{
	if(key == SDLK_ESCAPE)
	{
		quitGame = true;
	}
	
	if(key == SDLK_BACKSPACE)
	{
		if(gameState != true)
		{
			resetState();
			startMenuState = true;
		}
	}
	
}

void Game::getMouseInput(SDL_Event* event)
{
	//Someone clicked the mouse.
	int mouseX = event->button.x;
	int mouseY = event->button.y;
	
	//Depends on the state...
	if(startMenuState == true)
	{
		//We are in the start menu.
		//Button Code Here.
		if(testBounds(mouseX, mouseY, 270, 200, 370, 250) == true)
		{
			//You Pressed Play Game.
			resetState();
			gameMenuState = true;
		}
		
		if(testBounds(mouseX, mouseY, 270, 275, 370, 325) == true)
		{
			//You Pressed the about button.
			resetState();
			aboutState = true;
		}
		
		if(testBounds(mouseX, mouseY, 270, 350, 370, 400) == true)
		{
			//You Pressed the Quit Button.
			quitGame = true;
		}
	}
	else if(aboutState == true)
	{
		//In About Menu.
		if(testBounds(mouseX, mouseY, 270, 400, 370, 450) == true)
		{
			//You Clicked Return.
			resetState();
			startMenuState = true;
		}
	}
	else if(gameMenuState == true)
	{
		//In Game Menu.
		if(testBounds(mouseX, mouseY, 195, 400, 295, 450) == true)
		{
			//You Clicked Return.
			resetState();
			startMenuState = true;
		}
		
		if(testBounds(mouseX, mouseY, 345, 400, 445, 450) == true)
		{
			//You Clicked Play Game.
			resetState();
			gameState = true;
			viewPosition = 18;//max is 24
		}
		
	}
	else if(gameState == true)
	{
		//In Game.
		if(testBounds(mouseX, mouseY, 0, 0, 480, 53) == true)
		{
			//you pressed the top 53 pixels.
			if(viewPosition > 0)
			{
				viewPosition = viewPosition - 1;
			}
			
		}
		
		if(testBounds(mouseX, mouseY, 0, 427, 640, 480) == true)
		{
			if(viewPosition < 18)
			{
				viewPosition = viewPosition + 1;
			}
		}
	}
	
	//End of Mouse Input.
}

bool Game::testBounds(int testX, int testY, int x, int y, int x2, int y2)
{
	if(testX >= x && testX <= x2 
	&& testY >= y && testY <= y2 )
	{
		return true;
	}
	
	return false;
}

Game::~Game()
{
	//Destructor.
	SDL_DestroyTexture( redTile );
	SDL_DestroyTexture( floorTile );
	SDL_DestroyTexture( wallTile );
	SDL_DestroyTexture( gameMenuText );
	SDL_DestroyTexture( returnButton );
	SDL_DestroyTexture( aboutText );
	SDL_DestroyTexture( amorArena );
	SDL_DestroyTexture( playGame );
	SDL_DestroyTexture( about );
	SDL_DestroyTexture( quit );
	SDL_DestroyRenderer( myRenderer );
	SDL_DestroyWindow( myWindow );
	SDL_Quit();
}