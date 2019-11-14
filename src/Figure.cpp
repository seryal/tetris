#include "Figure.h"
#include <stdlib.h>

Figure::Figure(SDL_Renderer * ren)
{
	renderer = ren;
	nextFigureNumber = rand() % 7;
	nextFigureRotate = rand() % 4;
}

Figure::~Figure()
{
	for (int i = 0; i < 4; i++)
	{
		if (obj[i] != nullptr)
			delete obj[i];
		if (nextObj[i] != nullptr)
			delete nextObj[i];
	}
}

void Figure::Update()
{
	for (int i = 0; i < 4; i++)
	{

		obj[i]->Update();
		nextObj[i]->Update();
	}
}

void Figure::Render()
{
	for (int i = 0; i < 4; i++)
	{
		obj[i]->Render();
		nextObj[i]->Render();
	}
}

void Figure::InitFigure()
{
	for (int i = 0; i < 4; i++)
	{
//			delete obj[i];

		if (obj[i] == nullptr)
			obj[i] = new GameObject(renderer);

		if (nextObj[i] == nullptr)
			nextObj[i] = new GameObject(renderer);


		obj[i]->setElementSize(elementSize);
		// calc X and Y
		int newX = ((figures[figureNumber][figureRotate][i] - 1) % 4);
		int newY = ((figures[figureNumber][figureRotate][i] - 1) / 4);
		obj[i]->setXpos(newX + posX);
		obj[i]->setYpos(newY + posY);
		obj[i]->setOffsetX(offsetX);
		obj[i]->setOffsetY(offsetY);
		obj[i]->setColor(figuresColor[figureNumber]);

		nextObj[i]->setElementSize(elementSize);
		newX = ((figures[nextFigureNumber][nextFigureRotate][i] - 1) % 4);
		newY = ((figures[nextFigureNumber][nextFigureRotate][i] - 1) / 4);

		nextObj[i]->setXpos(newX + 11);
		nextObj[i]->setYpos(newY);
		nextObj[i]->setOffsetX(offsetX);
		nextObj[i]->setOffsetY(offsetY);
		nextObj[i]->setColor(figuresColor[nextFigureNumber]);
	}
}

void Figure::Rotate(int position)
{
	figureRotate += position;
	if (figureRotate > 3)
		figureRotate = 0;
	if (figureRotate < 0)
		figureRotate = 3;

	InitFigure();
}

void Figure::moveLeft()
{
	posX--;
	for (int i = 0; i < 4; i++)
	{
		int newX = ((figures[figureNumber][figureRotate][i] - 1) % 4) + posX;
		int newY = ((figures[figureNumber][figureRotate][i] - 1) / 4) + posY;
		obj[i]->setXpos(newX);
		obj[i]->setYpos(newY);
	}
}

void Figure::moveRight()
{
	posX++;
	for (int i = 0; i < 4; i++)
	{
		int newX = ((figures[figureNumber][figureRotate][i] - 1) % 4) + posX;
		int newY = ((figures[figureNumber][figureRotate][i] - 1) / 4) + posY;
		obj[i]->setXpos(newX);
		obj[i]->setYpos(newY);
	}
}

void Figure::moveDown()
{
	posY++;
	for (int i = 0; i < 4; i++)
	{
		int newX = ((figures[figureNumber][figureRotate][i] - 1) % 4) + posX;
		int newY = ((figures[figureNumber][figureRotate][i] - 1) / 4) + posY;
		obj[i]->setXpos(newX);
		obj[i]->setYpos(newY);
	}
}

void Figure::moveUp()
{
	posY--;
	for (int i = 0; i < 4; i++)
	{
		int newX = ((figures[figureNumber][figureRotate][i] - 1) % 4) + posX;
		int newY = ((figures[figureNumber][figureRotate][i] - 1) / 4) + posY;
		obj[i]->setXpos(newX);
		obj[i]->setYpos(newY);
	}
}

void Figure::nexFigure(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;

	figureNumber = nextFigureNumber;
	figureRotate = nextFigureRotate;

	nextFigureNumber = rand() % 7;
	nextFigureRotate = rand() % 4;
	InitFigure();
}


void Figure::setElementSize(int size)
{
	elementSize = size;
}

int Figure::getElementSize()
{
	return elementSize;
}

void Figure::setX(int x)
{
	posX = x;
}

int Figure::getX()
{
	return posX;
}

void Figure::setY(int y)
{
	posY = y;
}

int Figure::getY()
{
	return posY;
}

void Figure::setOffsetX(int x)
{
	offsetX = x;
}

int Figure::getOffsetX()
{
	return offsetX;
}

void Figure::setOffsetY(int y)
{
	offsetY = y;
}

int Figure::getOffsetY()
{
	return offsetY;
}

GameObject Figure::getGameObject(int index)
{
	return *obj[index];
}
