#pragma once

class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
	void resizeUp();
	void resizeDown();
	//void rotate90clockwise();
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operAddSign :public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act()override;
};
class operaddCar : public operation
{
public:
	operaddCar(game* r_pGame);
	virtual void Act()override;
};
class operaddice : public operation
{
public:
	operaddice(game* r_pGame);
	virtual void Act()override;
};
class operaddTree : public operation
{
public:
	operaddTree(game* r_pGame);
	virtual void Act()override;
};
class operaddHouse : public operation
{
public:
	operaddHouse(game* r_pGame);
	virtual void Act()override;
};
class operaddCat : public operation
{
public:
	operaddCat(game* r_pGame);
	virtual void Act()override;
};
class operaddresizeUp : public operation
{
public:
	operaddresizeUp(game* r_pGame);
	virtual void Act()override;
};
class operadddec : public operation
{
public:
	operadddec(game* r_pGame);
	virtual void Act()override;
};
class operaddrotate : public operation
{
public:
	operaddrotate(game* r_pGame);
	virtual void Act()override;
};
class operaddrefresh : public operation
{
public:
	operaddrefresh(game* r_pGame);
	virtual void Act()override;
};
class operaddhint : public operation
{
public:
	operaddhint(game* r_pGame);
	virtual void Act()override;
};
class operadddelete : public operation
{
public:
	operadddelete(game* r_pGame);
	virtual void Act()override;
};
class operaddselectlevel : public operation
{
public:
	operaddselectlevel(game* r_pGame);
	virtual void Act()override;
};
class operaddsave : public operation
{
public:
	operaddsave(game* r_pGame);
	virtual void Act()override;
};
class operaddload : public operation
{
public:
	operaddload(game* r_pGame);
	virtual void Act()override;
};
class operaddexit : public operation
{
public:
	operaddexit(game* r_pGame);
	virtual void Act()override;
};
class operaddmatch : public operation
{
public:
	operaddmatch(game* r_pGame);
	virtual void Act()override;
};
