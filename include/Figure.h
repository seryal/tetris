#pragma once
#include "SDL.h"
#include "GameObject.h"



class Figure {
private:
	int figures[7][4][4] = { {{ 6,7,10,11 },{ 6,7,10,11 },{ 6,7,10,11 },{ 6,7,10,11 }},     // O
							 {{ 5,6,7,8 },{ 3,7,11,15 },{ 5,6,7,8 },{ 3,7,11,15 }},			// I
							 {{ 7,8,10,11 },{ 3,7,8,12 },{ 7,8,10,11 },{ 3,7,8,12 }},		// S
							 {{ 6,7,11,12 },{ 4,7,8,11 },{ 6,7,11,12 },{ 4,7,8,11 }},		// Z
							 {{ 6,7,8,10 },{ 3,7,11,12 },{ 4,6,7,8 },{ 2,3,7,11 }},			// L
							 {{ 6,7,8,12 },{ 3,4,7,11 },{ 2,6,7,8 },{ 3,7,10,11 }},			// J
							 {{ 6,7,8,11 },{ 3,7,8,11 },{ 3,6,7,8 },{ 3,6,7,11 }} };		// T
	SDL_Color figuresColor[7] = { {255,255,255,255},
									{255,255,0,255},
									{255,0,255,255},
									{255,0,0,255},
									{0,255,255,255},
									{0,255,0,255},
									{0,0,255,255} };
	int figureNumber = 0;
	int figureRotate = 0;
	int nextFigureNumber = 0;
	int nextFigureRotate = 0;
	// coordinates for draw next Figure;
	int nextFigureAbsX = 0;
	int nextFigureAbsY = 0;

	int elementSize = 0;
	int posX = 0;
	int posY = 0;
	int offsetX = 0;
	int offsetY = 0;
	GameObject *obj[4] = { nullptr, nullptr, nullptr, nullptr };

	GameObject *nextObj[4] = { nullptr, nullptr, nullptr, nullptr };

	SDL_Renderer *renderer;

public:
	Figure(SDL_Renderer *ren);
	virtual ~Figure();
	void Update();
	void Render();
	void InitFigure();
	void Rotate(int position);
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();
	void nexFigure(int posX, int posY);

	// getter setter
	void setElementSize(int size);
	int getElementSize();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void setOffsetX(int x);
	int getOffsetX();
	void setOffsetY(int y);
	int getOffsetY();

	void setNextFigureAbsX(int value) { nextFigureAbsX = value; };
	void setNextFigureAbsY(int value) { nextFigureAbsY = value; };

	int gettNextFigureAbsX() { return nextFigureAbsX; };
	int gettNextFigureAbsY() { return nextFigureAbsY; };

	GameObject getGameObject(int index);
};