#pragma once
#include "SDL.h"

class GameObject {
protected:
private:
	int xpos = 0;
	int ypos = 0;
	int offsetX = 0;
	int offsetY = 0;
	int elementSize = 0;

	SDL_Color color;
	SDL_Renderer *renderer;
public:
	GameObject(SDL_Renderer* ren);
	~GameObject();
	void Update();
	void Render();

	// getter setter
	void setXpos(int x);
	int getXpos();
	void setYpos(int y);
	int getYpos();
	void setElementSize(int size)
	{
		elementSize = size;
	};
	int getElementSize(int size)
	{
		return elementSize;
	};
	void setOffsetX(int value)
	{
		offsetX = value;
	};
	int getOffsetX()
	{
		return offsetX;
	};
	void setOffsetY(int value)
	{
		offsetY = value;
	};
	int getOffsetY()
	{
		return offsetY;
	};

	SDL_Color getColor();
	void setColor(SDL_Color clr);

};