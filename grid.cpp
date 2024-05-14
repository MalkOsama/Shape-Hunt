#include "grid.h"
#include "game.h"
#include "gameConfig.h"


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


shape* grid::getActiveShape()
{
	return grid::activeShape;
}

//void grid::deleteShape(point clickedPoint)
//{
//	point corner;
//
//	// Calculate the grid cell index from the clicked point
//	int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.ShapeHght;
//	int gridCellColIndex = clickedPoint.x / config.ShapeWdth;
//
//	// Check if the indices are within the valid range
//	if (gridCellRowIndex >= 0 && gridCellRowIndex < rows &&
//		gridCellColIndex >= 0 && gridCellColIndex < cols)
//	{
//		if (ShapeMatrix[gridCellRowIndex][gridCellColIndex])
//		{
//			corner = ShapeMatrix[gridCellRowIndex][gridCellColIndex]->getuprlft();
//			window* pWind = pGame->getWind();
//			// draw lines showing the grid
//			pWind->SetPen(config.gridLinesColor, 1);
//			pWind->SetBrush(config.bkGrndColor);
//			pWind->DrawRectangle(corner.x, corner.y, corner.x + config.Wdth, corner.y + config.Hght, FILLED);
//
//			delete ShapeMatrix[gridCellRowIndex][gridCellColIndex];
//			ShapeMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;
//
//		}
//	}



