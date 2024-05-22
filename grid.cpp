#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include<ctime>


grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}

void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();
	
	pWind->SetPen(config.gridDotsColor,1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

	//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
			if (shapeList[i])
				shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if(activeShape)
		activeShape->draw();
}

void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	shapes.push_back(newShape);
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail
	
	//Here we assume that the above checks are passed
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;
}

void grid::drawShapes() const
{
	for (shape* pShape : shapes) {
		pShape->draw();
	}
}

void grid::generateRandomShape()
{
	int level = pGame->getLevels();
	for (int i = 0; i < (2 * level - 1); i++) {
		srand(time(0));
		toolbarItem item = toolbarItem(rand() % 5);
		shape* newShape;
		point p = { rand() % (config.RefX - config.RefY) + config.windWidth , rand() % config.windHeight };
		int c = rand() % 6;
		switch (c)
		{
		case 0:
			newShape = new Sign(pGame, p);

			break;

		case 1:
			newShape = new class Car(pGame, p);

			break;

		case 2:
			newShape = new class House(pGame, p);
			break;

		case 3:
			newShape = new class Tree(pGame, p);
			break;

		case 4:
			newShape = new class Cat(pGame, p);
			break;

		case 5:
			newShape = new class Icecream(pGame, p);
		}
		

		if (rand() % 2 == 0)
			newShape->resizeDown(0.5);
		else
			newShape->resizeUp(2);



		for (int i = 0; i < rand() % 4; i++)
			newShape->rotateclockwise90();
		addShape(newShape);
		shapes.push_back(newShape);
	}
	drawShapes();
}

void grid::SaveShapes(ofstream& OutFile)
{
	if (shapeCount > 0)
		OutFile << shapeCount;
	for (int i = 0; i < shapeCount; i++)
	{
		shapeList[i]->save(OutFile);
	}
}
void grid::LoadShapes(ifstream& InFile)
{
	int shapecount;
	InFile >> shapecount;
	for (int i = 0; i < shapecount; i++)
	{
		int shapetype, x, y;
		unsigned char red, green, blue;
		InFile >> shapetype >> x >> y >> red >> green >> blue;
		point pt;
		pt.x = x;
		pt.y = y;
		color clr(red, green, blue);
		shape* sh = nullptr;

		switch (shapetype)
		{
		case SIGN:
			sh = new Sign(pGame, pt);
			break;
		case Car:
			sh = new class Car(pGame, pt);
			break;
		case House:
			sh = new class House(pGame, pt);
			break;
		case Tree:
			sh = new class Tree(pGame, pt);
			break;
		case Icecreaam:
			sh = new class Icecream(pGame, pt);
			break;
		case Cat:
			sh = new class Cat(pGame, pt);
			break;
		}
		sh->Load(InFile);
		addShape(sh);
	}
}
void grid::deleteshape()
{
	if (activeShape != nullptr)
	{
		delete activeShape;
		activeShape = nullptr;
		this->draw();
	}
}

shape* grid::getActiveShape()
{
	return grid::activeShape;
}



bool grid::match()
{
	int c = 0; int ii = 0;
	if (activeShape)
	{
		for (int i = 0; i < shapeCount; i++)
		{
			if (shapeList[i])
			{
				if (activeShape->match(shapeList[i]))
				{
					c++; ii = i;
				}
			}
		}
	}
	if (c == 0)
	{
		return false;
	}
	else
	{
		delete activeShape; activeShape = nullptr;
		delete shapeList[ii]; shapeList[ii] = nullptr;
		draw();
		return true;

	}
}

