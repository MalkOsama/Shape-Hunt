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
	void resizeUp(double factor) override;
	void resizeDown(double factor) override;
	void rotateclockwise90() override;
	bool match(shape* sh) const override;
	virtual point getCenter() const override;

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
	void resizeUp(double factor) override;
	void resizeDown(double factor) override;
	void rotateclockwise90() override;
	bool match(shape* sh) const override;
	virtual point getCenter() const override;
	
};


////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//Reference point of the circle is its center
class triangle :public shape
{
	int base;
	int sidelength;
	double rotation_angle;
public:
	triangle(game* r_pGame, point ref, int r_base, double side1);
	virtual void draw() const;
	virtual void rotateclockwise90();
	//virtual void resize(double factor);
	void setbase(double BASE);
	double getbase()const;
	bool match(shape* sh) const override;
	void resizeUp(double factor) override;
	void resizeDown(double factor) override;
	point getCenter() const;
	//virtual void Save(ofstream& OutFile) override;
	//virtual void Load(ifstream& Infile) override;


};
