#pragma once
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	int x, y;
};

enum ShapeType
{
	//Basic shapes
	RCT,	//rectangle
	CRC,	//circle
	TRI,	//triangle

	//Composite shapes
	SIGN,	//a street sign
	Car,
	House,
	Tree,
	Icecreaam,
	Cat,


	//TODO: Add more types
};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
    game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	float rotationAngle; 
	float size;
	bool matched;
public:
    shape(game* r_pGame, point ref,float rotationAngle = 0, float size = 1.0);
    virtual void draw() const=0;//for a shape to draw itself on the screen
	void setRefPoint(point p);
								  
							  
	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	

	//virtual void rotate() = 0;	//Rotate the shape
	virtual void resizeUp(double factor)=0;
	virtual void resizeDown(double factor)=0;
	virtual bool match(shape* sh) const = 0;
	virtual void moveBy(int dx, int dy);
	virtual point getCenter() const = 0;
	//virtual void move() = 0;		//Move the shape
	virtual void rotateclockwise90() =0;
	virtual void setFillColor(const color& fillColor);
	 void save(ofstream &OutFile) ;	//Save the shape parameters to the file
	 void Load(ifstream &Infile);	//Load the shape parameters to the file
	// Method to set the rotation angle of the shape
	void setRotationAngle(float angle);
	void setSize(float factor);


	/*bool isMatched() const;
	void setMatched(bool matched);
	bool isOverlapping(const shape* other) const;
	void Overlap(shape* other);*/

};





