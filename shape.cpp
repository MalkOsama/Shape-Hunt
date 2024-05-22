#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref,float rotationAngle, float size)
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

void shape::moveBy(int dx, int dy)
{
	RefPoint.x += dx;
	RefPoint.y += dy;
}


void shape::setFillColor(const color& fillColor)
{
	this->fillColor = fillColor;
}

void shape::save(ofstream& OutFile)
{
}

void shape::Load(ifstream& Infile)
{
}

void shape::setRotationAngle(float angle)
{
	rotationAngle = angle;
}

void shape::setSize(float factor)
{
	size = factor;
}
//
//bool shape::isMatched() const {
//	return matched;
//}
//
//void shape::setMatched(bool matched) {
//	this->matched = matched;
//}
//
//bool shape::isOverlapping(const shape* other) const {
//}
//
//void shape::Overlap(shape* other) {
//}