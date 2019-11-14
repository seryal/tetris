#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>
#include "Game.h"

Game *game;
int main(int argc, char * argv[])
{
	game = new Game();
	game->init("TITLE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 800, false);
	game->Start();
	delete game;
	return 1;
}
