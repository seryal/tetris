#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include "World.h"

class Game
{
    protected:
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        World *world;
        void RenderWorld();
		bool isRunning = false;
	public:
        Game();
		void init(const char *title, int xpos, int ypos, int width, int height, bool fullScreen);
		void handleEvent();
		void update();
		void render();
		void clean();
		bool running();
        virtual ~Game();
        int Start();
};

#endif // GAME_H
