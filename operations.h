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
	virtual void Act() =0;
	 void resizeUp() ;	
	 void resizeDown();
	// void rotate90clockwise();
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operAddSign:public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};
class operaddcar : public operation
{
public:
	operaddcar(game* r_pGame);
	virtual void Act();
};
class operaddice : public operation
{
public:
	operaddice(game* r_pGame);
	virtual void Act();
};
class operaddtree : public operation
{
public:
	operaddtree(game* r_pGame);
	virtual void Act();
};
class operaddhome : public operation
{
public:
	operaddhome(game* r_pGame);
	virtual void Act();
};
class operaddrocket : public operation
{
public:
	operaddrocket(game* r_pGame);
	virtual void Act();
};
class operaddinc : public operation
{
public:
	operaddinc(game* r_pGame);
	virtual void Act();
};
class operadddec : public operation
{
public:
	operadddec(game* r_pGame);
	virtual void Act();
};
class operaddrotate : public operation
{
public:
	operaddrotate(game* r_pGame);
	virtual void Act();
};
class operaddrefresh : public operation
{
public:
	operaddrefresh(game* r_pGame);
	virtual void Act();
};
class operaddhint : public operation
{
public:
	operaddhint(game* r_pGame);
	virtual void Act();
};
class operadddelete : public operation
{
public:
	operadddelete(game* r_pGame);
	virtual void Act();
};
class operaddselectlevel : public operation
{
public:
	operaddselectlevel(game* r_pGame);
	virtual void Act();
};
class operaddsave : public operation
{
public:
	operaddsave(game* r_pGame);
	virtual void Act();
};
class operaddload : public operation
{
public:
	operaddload(game* r_pGame);
	virtual void Act();
};
class operaddexit : public operation
{
public:
	operaddexit(game* r_pGame);
	virtual void Act();
};

