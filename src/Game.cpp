#include <iostream>
#include "Game.h"
#include <string>



Game::Game()
{
	//ctor
	std::cout << "Game create" << std::endl;
}

void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title,
			xpos,
			ypos,
			width,
			height,
			fullScreen);

		if (window == nullptr)
		{
			SDL_Log("Could not create a window: %s", SDL_GetError());
			return;
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		}
		isRunning = true;
		world = new World(renderer);

	}
	else
	{
		isRunning = false;
	}

}

void Game::handleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			world->moveLeft();
			break;
		case SDLK_RIGHT:
			world->moveRight();
			break;
		case SDLK_UP:
			world->moveRotate(-1);
			break;
		case SDLK_SPACE:
			world->moveFastDown();
			break;

		}
		break;
	default:
		break;
	}
}

void Game::update()
{
	world->update();
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
	SDL_RenderClear(renderer);
	world->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	delete world;

}

bool Game::running()
{
	return isRunning;
}

Game::~Game()
{
	//dtor
	std::cout << "Game destroy" << std::endl;

}



void Game::RenderWorld()
{

}

int Game::Start()
{
	// maximum FPS
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	Uint32 currentFPS = 0;

	while (running()) {
		frameStart = SDL_GetTicks();
		//////
		handleEvent();
		update();
		render();
		//////
		frameTime = SDL_GetTicks() - frameStart;

		// max 60 - FPS
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime != 0)
		{
			currentFPS = 1000 / frameTime;
			std::string s = "FPS: " + std::to_string(currentFPS);
			SDL_SetWindowTitle(window, s.c_str());
		}
	}

	clean();
	return 0;
}
