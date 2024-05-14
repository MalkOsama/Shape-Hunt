#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref,float rotationAngle = 0, float size = 1.0)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}

void shape::setFillColor(const color& fillColor)
{
	this->fillColor = fillColor;
}

void shape::setRotationAngle(float angle)
{
	rotationAngle = angle;
}

void shape::setSize(float factor)
{
	size = factor;
}
