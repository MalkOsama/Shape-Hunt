#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#define PII 3.14159265358979323846 

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

void Rect::resizeUp(double factor)
{
	hght *= 2;
	wdth *= 2;
}

void Rect::resizeDown(double factor)
{
	hght /= 2;
	wdth /= 2;
}
void Rect::rotateclockwise90()
{
	swap(wdth, hght);
}
bool Rect::match(shape* sh) const
{
	Rect* rec = dynamic_cast<Rect*> (sh);
	if (rec) {
		return RefPoint.x == rec->RefPoint.x && RefPoint.y == rec->RefPoint.y && hght == rec->hght && wdth == rec->wdth;
	}
	return false;
}
point Rect::getCenter() const
{
	return point();
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

void circle::resizeUp(double factor)

{
	rad *= 2;
}

void circle::resizeDown(double factor)
{
	rad /= 2;
}

void circle::rotateclockwise90()
{
}

bool circle::match(shape* sh) const
{
	circle* cir = dynamic_cast<circle*> (sh);
	if (cir) {
		return RefPoint.x == cir->RefPoint.x && RefPoint.y == cir->RefPoint.y && rad == cir->rad;
	}
	return false;
}

point circle::getCenter() const
{
	return point();
}


////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here

triangle::triangle(game* r_pGame, point ref, int r_base, double side1):shape(r_pGame, ref)
{
	pGame = r_pGame;
	base = r_base;
	sidelength = side1;
	//rotation_angle = ra;
}

void triangle::draw() const
{
	window* pW = pGame->getWind();
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point baseleft, baseright, vertex; // ref point is the middle point of the base 
	baseleft.x = RefPoint.x - base / 2;
	baseleft.y = RefPoint.y;
	baseright.x = RefPoint.x + base / 2;
	baseright.y = RefPoint.y;
	vertex.x = RefPoint.x;
	vertex.y = RefPoint.y - sidelength;
	pW->DrawTriangle(baseleft.x, baseleft.y, baseright.x, baseright.y, vertex.x, vertex.y, FILLED);


	//pW->DrawTriangle(LeftBottomPoint.x, LeftBottomPoint.y, UpperPoint.x, UpperPoint.y, RightBottomPoint.x, RightBottomPoint.y, FILLED);
}

void triangle::resizeUp(double factor)
{
	setbase(sidelength * factor);
}

void triangle::resizeDown(double factor)
{
	setbase(sidelength * factor);
}
void triangle::rotateclockwise90()
{
	
	rotation_angle += 90;
}

void triangle::setbase(double BASE)
{
	sidelength = BASE;
}

double triangle::getbase() const
{
	return sidelength;
}



bool triangle::match(shape* sh) const
{
	triangle* tri = dynamic_cast<triangle*> (sh);
	if (tri) {
		return RefPoint.x == tri->RefPoint.x && RefPoint.y == tri->RefPoint.y && sidelength == tri->sidelength;
	}
	return false;
}

point triangle::getCenter() const
{
	return point();
}
