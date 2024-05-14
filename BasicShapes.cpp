#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game * r_pGame, point ref, int r_hght, int r_wdth) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}

void Rect::resizeUp()
{
	hght *= 2;
	wdth *= 2;
}

void Rect::resizeDown()
{
	hght /= 2;
	wdth /= 2;
}
void Rect::rotateclockwise90()
{
	swap(wdth, hght);
}
////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	rad = r;

}

void circle::draw() const

{


	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}

void circle::resizeUp()

{
	rad *= 2;
}

void circle::resizeDown()
{
	rad /= 2;
}

void circle::rotateclockwise90()
{
}


////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here

triangle::triangle(game* r_pGame, point ref, int r_base, int r_side1, int r_side2) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	r_side1 = side1;
	r_side2 = side2;
	r_base = width;

}

void triangle::draw() const
{

	window* pW = pGame->getWind();    // Get interface window

	// Set pen and brush colors
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);

	// Define the three vertices of the triangle
	int x1 = RefPoint.x;
	int y1 = RefPoint.y - side1 / 2;   // Top vertex
	int x2 = RefPoint.x + width / 2;    // Right vertex
	int y2 = RefPoint.y + side2 / 2;   // Bottom right vertex
	int x3 = RefPoint.x - width / 2;    // Left vertex
	int y3 = RefPoint.y + side1/ 2;   // Bottom left vertex

	// Draw the triangle using the vertices
	pW->DrawTriangle(x1, y1, x2, y2, x3, y3, FILLED);
}

void triangle::resizeUp()
{
	side1 *= 2;
	side2 *= 2;
	width *= 2;
}

void triangle::resizeDown()
{
	side1 /= 2;
	side2 /= 2;
	width /= 2;
}
void triangle::rotateclockwise90()
{
	
	   	//int tempX = x - centerX;
	   	//int tempY = y - centerY;
	   
	   	//// Apply rotation
	   	//double angleRadians = angleDegrees * (PI / 180.0);
	   	//x = static_cast<int>(tempX * cos(angleRadians) - tempY * sin(angleRadians));
	   	//y = static_cast<int>(tempX * sin(angleRadians) + tempY * cos(angleRadians));
	   
	   	//// Translate point back to its original position
	   	//x += centerX;
	   	//y += centerY;
}

void triangle::rotatePointClockwise90() const
{
}
