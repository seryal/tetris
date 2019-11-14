#include "Field.h"
#include <iostream>

void Field::DeleteRow(int value)
{
	for (int i = 0; i < width; i++)
	{
		delete field[i][value];
		field[i][value] = nullptr;
	}
	for (int y = value; y > 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			if (field[x][y - 1] != nullptr)
			{
				field[x][y] = new GameObject(*field[x][y - 1]);
				field[x][y]->setYpos(y);

				delete field[x][y - 1];
				field[x][y - 1] = nullptr;
			}
		}
	}
}

Field::Field(SDL_Renderer * ren, int width, int height, int figureSize, int offsetX, int offsetY)
{
	renderer = ren;
	this->width = width;
	this->height = height;
	this->figureSize = figureSize;
	this->offsetX;
	this->offsetY;
	field.resize(width);
	for (int i = 0; i < width; i++)
	{
		field[i].resize(height);
	}

	for (int x = 0; x < width; x++)
		for (int y = 0; y < width; y++)
		{
			field[x][y] = nullptr;
		}

	// test - please delete me
	/*{
		int x = 4;
		int y = 7;
		field[x][y] = new GameObject(renderer);
		SDL_Color clr = { 255,0,0,255 };
		field[x][y]->setColor(clr);
		field[x][y]->setXpos(x);
		field[x][y]->setYpos(y);
		field[x][y]->setOffsetX(offsetX);
		field[x][y]->setOffsetY(offsetY);
		field[x][y]->setElementSize(figureSize);
	}*/
}

Field::~Field()
{
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			if (field[row][col] != nullptr)
				delete field[row][col];
}

void Field::Update()
{

}

void Field::Render()
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
		{
			if (field[x][y] != nullptr)
				field[x][y]->Render();
		}
}

void Field::AddFigureToField(Figure *figure)
{
	for (int i = 0; i < 4; i++)
	{
		if (field[figure->getGameObject(i).getXpos()][figure->getGameObject(i).getYpos()] == nullptr)
			field[figure->getGameObject(i).getXpos()][figure->getGameObject(i).getYpos()] = new GameObject(figure->getGameObject(i));
	}
}

int Field::DeleteFullRow()
{
	for (int y = 0; y < height; y++)
	{
		int count = 0;
		for (int x = 0; x < width; x++)
		{
			if (field[x][y] != nullptr)
				count++;
		}
		if (count == 10)
		{
			DeleteRow(y);
			std::cout << y << " : " << count << std::endl;
		}
	}
	return 0;
}

bool Field::isBusy(int x, int y)
{
	if (x >= width || y >= height)
		return true;

	if (field[x][y] != nullptr)
		return true;
	else
		return false;
}
