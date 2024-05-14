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
public:
	Sign(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp() override;
	void resizeDown() override;
	void rotateclockwise90() override;
};
class Car : public shape{
	circle * wheel1;
	circle* wheel2;
	Rect* body;
	triangle* roof;

public:
	Car(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp() override;
	void resizeDown() override;
	void rotateclockwise90() override;

};
class House : public shape {
	Rect* base;
	Rect* door;
	triangle* roof;

public:
	House(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp() override;
	void resizeDown() override;
	void rotateclockwise90() override;
};

class Tree : public shape {
	Rect* trunk;
	triangle* leaves1;
	triangle* leaves2;

public:
	Tree(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp() override;
	void resizeDown() override;
	void rotateclockwise90() override;
};

class Icecream : public shape {
	circle* scoop;
	triangle* cone;

public:
	Icecream(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp() override;
	void resizeDown() override;
	void rotateclockwise90() override;
};

class Cat : public shape {
	circle* head;
	triangle* ears;
	circle* eyes[2];
	Rect* body;
	Rect* tail;

public:
	Cat(game* r_pGame, point ref);
	virtual void draw() const;
	void resizeUp() override;
	void resizeDown() override;
	void rotateclockwise90() override;
};