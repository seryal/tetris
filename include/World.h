#ifndef WORLD_H
#define WORLD_H
#include "SDL.h"
#include "GameObject.h"
#include "Figure.h"
#include "Field.h"

class World
{
protected:

private:
	SDL_Renderer *renderer;
	const int offsetX = 100;
	const int offsetY = 80;

	int speed = 1000;

	bool fastDown = false;
	void CheckFullRow();
	int oldPosition;

	void AddFigureToField(Figure *figure);
	void NextFigure();
	void GameOver();
	Figure *figure;
	Field *field;

public:

    World(SDL_Renderer *ren);
	virtual ~World();
	// field size;
	const int width = 10;
	const int height = 20;
	const int figureSize = 30;
	
	// move figure to Left;
    void moveLeft();
    // move figure to Right;
    void moveRight();
    // rotate figure
    void moveRotate(int position);
    // move figure to down
    void moveDown();
    // move figure to down fast
    void moveFastDown();
	// update world
	void update();
	// render world
	void render();

};

#endif // WORLD_H
