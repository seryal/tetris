#include "GameObject.h"



GameObject::GameObject(SDL_Renderer * ren)
{
	renderer = ren;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
}

void GameObject::Render()
{
	SDL_Rect figureRect;

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a / 1.5);
	figureRect = { xpos * elementSize + offsetX , ypos * elementSize + offsetY, elementSize, elementSize };
	SDL_RenderFillRect(renderer, &figureRect);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	figureRect = { xpos * elementSize + offsetX + 1, ypos * elementSize + offsetY + 1, elementSize - 2, elementSize - 2 };
	SDL_RenderFillRect(renderer, &figureRect);

}

void GameObject::setXpos(int x)
{
	xpos = x;
}

int GameObject::getXpos()
{
	return xpos;
}

void GameObject::setYpos(int y)
{
	ypos = y;
}

int GameObject::getYpos()
{
	return ypos;
}


SDL_Color GameObject::getColor()
{
	return color;
}

void GameObject::setColor(SDL_Color clr)
{
	color = clr;
}
