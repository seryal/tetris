#include <iostream>
#include "World.h"
#include "SDL.h"


void World::CheckFullRow()
{
	field->DeleteFullRow();
}

void World::AddFigureToField(Figure * figure)
{
	field->AddFigureToField(figure);
	std::cout << "Add figure to field" << std::endl;
}

void World::NextFigure()
{
	fastDown = false;
	// Add figure to field;
	AddFigureToField(figure);
	CheckFullRow();
	figure->nexFigure(width / 2 - 2, 0);
	for (int i = 0; i < 4; i++)
	{
		if (field->isBusy(figure->getGameObject(i).getXpos(), figure->getGameObject(i).getYpos()))
		{
			GameOver();
			break;
		}
	}
}

void World::GameOver()
{
	std::cout << "Game Over" << std::endl;

}

World::World(SDL_Renderer * ren)
{
	std::cout << "World create" << std::endl;
	renderer = ren;

	field = new Field(renderer, width, height, figureSize, offsetX, offsetY);

	figure = new Figure(renderer);
	figure->setElementSize(figureSize);
	figure->setOffsetX(offsetX);
	figure->setOffsetY(offsetY);
	figure->nexFigure(width / 2 - 2, 0);
}

World::~World()
{
	//dtor
	delete figure;
	std::cout << "World destroy" << std::endl;
}

void World::moveLeft()
{
	figure->moveLeft();
	for (int i = 0; i < 4; i++)
	{
		if (figure->getGameObject(i).getXpos() < 0)
		{
			figure->moveRight();
			break;
		}
		if (field->isBusy(figure->getGameObject(i).getXpos(), figure->getGameObject(i).getYpos()))
		{
			figure->moveRight();
			break;
		}
	}
}

void World::moveRight()
{
	figure->moveRight();
	for (int i = 0; i < 4; i++)
	{
		if (figure->getGameObject(i).getXpos() >= width)
		{
			figure->moveLeft();
			break;
		}
		if (field->isBusy(figure->getGameObject(i).getXpos(), figure->getGameObject(i).getYpos()))
		{
			figure->moveLeft();
			break;
		}
	}
}

void World::moveRotate(int position)
{
	figure->Rotate(position);
	for (int i = 0; i < 4; i++)
	{
		if (figure->getGameObject(i).getXpos() >= width || figure->getGameObject(i).getXpos() < 0)
		{
			figure->Rotate(position * -1);
			break;
		}
		if (field->isBusy(figure->getGameObject(i).getXpos(), figure->getGameObject(i).getYpos()))
		{
			figure->Rotate(position * -1);
			break;
		}
	}
}

void World::moveDown()
{
	figure->moveDown();
	for (int i = 0; i < 4; i++)
	{
		if (field->isBusy(figure->getGameObject(i).getXpos(), figure->getGameObject(i).getYpos()))
		{
			fastDown = false;
			figure->moveUp();
			NextFigure();
			break;
		}
	}
}

void World::moveFastDown()
{
	fastDown = true;
}

// update world
void World::update()
{
	int _speed = speed;
	if (fastDown)
		_speed = 5;
	int sp = static_cast<int>(SDL_GetTicks() / _speed);

	if (oldPosition != sp)
		moveDown();
	if (fastDown)
		oldPosition = sp;
	else
		oldPosition = static_cast<int>(SDL_GetTicks() / speed);
	// std::cout << sp << std::endl;
	field->Update();
	figure->Update();
}


// render World
void World::render()
{
	// draw field
	SDL_Rect fieldRect;
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	fieldRect = { offsetX - 5, offsetY - 5, figureSize*width + 10, figureSize*height + 10 };
	SDL_RenderFillRect(renderer, &fieldRect);
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	fieldRect = { offsetX, offsetY, figureSize*width, figureSize*height };
	SDL_RenderFillRect(renderer, &fieldRect);

	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
		{

			fieldRect = { x*figureSize + offsetX, y*figureSize + offsetY, figureSize, figureSize };
			SDL_RenderDrawRect(renderer, &fieldRect);
		}

	field->Render();
	figure->Render();
	// draw figures
}
