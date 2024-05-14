#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}

void operation::resizeUp()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();

	if (activeShape) {
		activeShape->resizeUp();
	}
}

void operation::resizeDown()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();

	if (activeShape) {
		activeShape->resizeDown();
	}
}


//void operation::rotate90clockwise()
//{
//	grid* pGrid = pGame->getGrid();
//	shape* activeShape = pGrid->getActiveShape();
//
//	if (activeShape) {
//		activeShape->rotateClockwise90();
//	}
//}



/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game * r_pGame) :operation(r_pGame)
	{
	}

void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operaddcar::operaddcar(game* r_pGame) :operation(r_pGame)
{
}
void operaddcar::Act()
{
}
operaddice::operaddice(game* r_pGame) :operation(r_pGame)
{
}
void operaddice::Act()
{
}
operaddtree::operaddtree(game* r_pGame) :operation(r_pGame)
{
}
void operaddtree::Act()
{
}
operaddhome::operaddhome(game* r_pGame) :operation(r_pGame)
{
}
void operaddhome::Act()
{
}
operaddrocket::operaddrocket(game* r_pGame) :operation(r_pGame)
{
}
void operaddrocket::Act()
{
}
operaddinc::operaddinc(game* r_pGame) :operation(r_pGame)
{
}
void operaddinc::Act()
{
}
operadddec::operadddec(game* r_pGame) :operation(r_pGame)
{
}
void operadddec::Act()
{
}
operaddrotate::operaddrotate(game* r_pGame) :operation(r_pGame)
{
}
void operaddrotate::Act()
{
}
operaddrefresh::operaddrefresh(game* r_pGame) :operation(r_pGame)
{
}
void operaddrefresh::Act()
{
}
operaddhint::operaddhint(game* r_pGame) :operation(r_pGame)
{
}
void operaddhint::Act()
{
}
operadddelete::operadddelete(game* r_pGame) :operation(r_pGame)
{
}
void operadddelete::Act()
{
}
operaddselectlevel::operaddselectlevel(game* r_pGame) :operation(r_pGame)
{
}
void operaddselectlevel::Act()
{
	//int level;
	//bool validInput = false;

	//do {
	//	const int MIN_LEVEL = 1;
	//	const int MAX_LEVEL = 10;
	//	if (level >= MIN_LEVEL && level <= MAX_LEVEL) {
	//		validInput = true;
	//} while (!validInput);
}

operaddsave::operaddsave(game* r_pGame) :operation(r_pGame)
{
}
void operaddsave::Act()
{
}
operaddload::operaddload(game* r_pGame) :operation(r_pGame)
{
}
void operaddload::Act()
{
}
operaddexit::operaddexit(game* r_pGame) :operation(r_pGame)
{
}
void operaddexit::Act()
{
}
