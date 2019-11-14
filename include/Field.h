#pragma once
#include "SDL.h"
#include "GameObject.h"
#include "Figure.h"
#include <vector>

class Field {
private:
	SDL_Renderer *renderer;
	int width = 0;
	int height = 0;
	int figureSize = 0;
	int offsetX = 0;
	int offsetY = 0;
	void DeleteRow(int value);
	std::vector<std::vector<GameObject*>> field;
public:
	Field(SDL_Renderer *ren, int width, int height, int figureSize, int offsetX, int offsetY);
	virtual ~Field();
	void Update();
	void Render();
	void AddFigureToField(Figure *figure);
	int DeleteFullRow();
	bool isBusy(int x, int y);
};