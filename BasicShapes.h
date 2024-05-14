// Header file for Basic shapes in the game
#pragma once
#include "shape.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
//Rectanle class
/*							wdth
					---------------------
					|					|
			hght    |		 x			|     x is the reference point of the rectangle
					|					|
					--------------------
*/


class Rect :public shape
{
	int hght, wdth;	//height and width of the recangle
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	virtual void draw() const;
	void resizeUp() override;
	void resizeDown() override;
	void rotateclockwise90() override;

};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle :public shape
{
	//Add data memebrs for class circle

	int rad;
public:
	circle(game* r_pGame, point ref, int r);	//add more parameters for the constructor if needed
	virtual void draw() const;
	void resizeUp() override;
	void resizeDown() override;
	void rotateclockwise90() override;
	
};


////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//Reference point of the circle is its center
class triangle :public shape
{
	//Add data memebrs for class circle
	int width, side1,side2;
public:
	triangle(game* r_pGame, point ref, int r_base, int r_side1,int r_side2);	//add more parameters for the constructor if needed
	virtual void draw() const;
	void resizeUp() override;
	void resizeDown() override;
	void rotateclockwise90() override;
	void rotatePointClockwise90()  const;
};