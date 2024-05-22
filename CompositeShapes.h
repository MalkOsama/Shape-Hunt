#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{
	Rect* base;
	Rect* top;
	int rotation_angle_sign;
public:
	Sign(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp(double factor) override;
	void resizeDown(double factor) override;
	void rotateclockwise90() override;
	bool match(shape* sh) const override;
   point getCenter() const override;
   void Load(ifstream& Infile);
};
class Car : public shape{
	circle * wheel1;
	circle* wheel2;
	Rect* body;
	triangle* roof;
	int current_rotation_anggg=0;

public:
	Car(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp(double factor) override;
	void resizeDown(double factor) override;
	void rotateclockwise90() override;
	bool match(shape* sh) const override;
	point getCenter() const override;
	void Load(ifstream& Infile);

};
class House : public shape {
	Rect* base;
	Rect* door;
	triangle* roof;
	int current_rotation_angg;

public:
	House(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp(double factor) override;
	void resizeDown(double factor) override;
	void rotateclockwise90() override;
	bool match(shape* sh) const override;
	point getCenter() const override;
	void Load(ifstream& Infile);
};

class Tree : public shape {
	Rect* trunk;
	triangle* leaves1;
	triangle* leaves2;
	int current_rotation_angle;
	

public:
	Tree(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp(double factor) override;
	void resizeDown(double factor) override;
	void rotateclockwise90() override;
	bool match(shape* sh) const override;
    point getCenter() const override;
	void Load(ifstream& Infile);

};

class Icecream : public shape {
	circle* scoop;
	triangle* cone;
	int current_rotation_ang;

public:
	Icecream(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp(double factor) override;
	void resizeDown(double factor) override;
	void rotateclockwise90() override;
	bool match(shape* sh) const override;
	point getCenter() const override;
	void Load(ifstream& Infile);
};

class Cat : public shape {
	circle* head;
	triangle* ears;
	circle* eyes[2];
	Rect* body;
	Rect* tail;
	int current_rotation_angle=0;

public:
	Cat(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp(double factor) override;
	void resizeDown(double factor) override;
	void rotateclockwise90() override;
	bool match(shape* sh) const override;
	point getCenter() const override;
	void Load(ifstream& Infile);
};