#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <fstream>
#include <vector>
#include<iostream>
using namespace std;
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}

void operation::resizeUp()
{
}

//void operation::resizeUp()
//{
//	grid* pGrid = pGame->getGrid();
//	shape* activeShape = pGrid->getActiveShape();
//
//	if (activeShape) {
//		activeShape->resizeUp();
//	}
//}
//
//void operation::resizeDown()
//{
//	grid* pGrid = pGame->getGrid();
//	shape* activeShape = pGrid->getActiveShape();
//
//	if (activeShape) {
//		activeShape->resizeDown();
//	}
//}

//void operation::rotate90clockwise()
//{
//	grid* pGrid = pGame->getGrid();
//	shape* activeShape = pGrid->getActiveShape();
//
//	if (activeShape) {
//		activeShape->rotateClockwise90();
//	}
//}


//operadddelete::operadddelete(point r_uprleft, int r_width, int r_height, game* r_pGame) : operation(r_uprleft, r_width, r_height, r_pGame)
//{
//}
//void operadddelete::onClick()
//{
//	pGame->printMessage("Click on the bricks you want to delete ==> Right-Click to stop <==");
//
//	int x, y;
//	clicktype t;
//	t = pGame->getMouseClick(x, y);
//
//	while (t == LEFT_CLICK) {
//		point clicked;
//		clicked.x = x;
//		clicked.y = y;
//
//		grid* pGrid = pGame->getGrid();
//		pGrid->deleteBrick(clicked);
//
//		// Redraw the grid
//		pGame->getGrid()->draw();
//		t = pGame->getMouseClick(x, y);
//	}
//	pGame->printMessage("");
//}



/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame) :operation(r_pGame)
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
operaddCar::operaddCar(game* r_pGame) :operation(r_pGame)
{
}
void operaddCar::Act()
{
	window* pw = pGame->getWind();
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;
	point carshapeRef = { xGrid, yGrid };
	shape* psh = new class Car(pGame, carshapeRef);
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operaddice::operaddice(game* r_pGame) :operation(r_pGame)
{
}
void operaddice::Act()
{
	window* pw = pGame->getWind();
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;
	point iceshapeRef = { xGrid, yGrid };
	shape* psh = new Icecream(pGame, iceshapeRef);
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}
operaddTree::operaddTree(game* r_pGame) :operation(r_pGame)
{
}
void operaddTree::Act()
{
	window* pw = pGame->getWind();
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;
	point TreeshapeRef = { xGrid, yGrid };
	shape* psh = new class Tree(pGame, TreeshapeRef);
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}
operaddHouse::operaddHouse(game* r_pGame) :operation(r_pGame)
{
}
void operaddHouse::Act()
{
	window* pw = pGame->getWind();
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;
	point HouseshapeRef = { xGrid, yGrid };
	shape* psh = new class House(pGame, HouseshapeRef);
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}
operaddCat::operaddCat(game* r_pGame) :operation(r_pGame)
{
}
void operaddCat::Act()
{
	window* pw = pGame->getWind();
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;
	point CatshapeRef = { xGrid, yGrid };
	shape* psh = new class Cat(pGame, CatshapeRef);
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}
operaddresizeUp::operaddresizeUp(game* r_pGame) :operation(r_pGame)
{

}
//void operaddresizeUp::Act()
//{
//
//}
void operaddresizeUp::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveShape();
	psh->resizeUp(2);
	pGrid->setActiveShape(psh);
}
operadddec::operadddec(game* r_pGame) :operation(r_pGame)
{
}
void operadddec::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveShape();
	psh->resizeDown(0.5);
	pGrid->setActiveShape(psh);
}
operaddrotate::operaddrotate(game* r_pGame) :operation(r_pGame)
{
}
void operaddrotate::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();

	if (activeShape) {
		activeShape->rotateclockwise90();
	}
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
	pGame->getGrid()->deleteshape();
	/*window* pw = pGame->getWind();
	shape* activeShape = pGame->getGrid()->getActiveShape();
	if (activeShape == nullptr) {
		pGame->printMessage("No active shape to delete.");
		return;
		delete activeShape;
		pGame->getGrid()->setActiveShape(nullptr);

		pGame->printMessage("Deleted the active shape.");
	}*/
}
operaddselectlevel::operaddselectlevel(game* r_pGame) :operation(r_pGame)
{
}
void operaddselectlevel::Act()
{

}
operaddsave::operaddsave(game* r_pGame) :operation(r_pGame)
{
}
void operaddsave::Act()
{
	int CurrentScore = pGame->getToolbar()->getScore();
	int CurrentLevel = pGame->getToolbar()->getLevel();
	int RemainingLives = pGame->getToolbar()->getRemainingLives();
	ofstream outfile;
	outfile.open("test.txt");
	outfile << CurrentScore << "\n" << CurrentLevel << "\n" << RemainingLives << "\n";
	pGame->getGrid()->getActiveShape()->save(outfile);
	pGame->getGrid()->SaveShapes(outfile);
	outfile.close();
	/*int CurrentScore = pGame->getToolbar()->getScore();
	int CurrentLevel = pGame->getToolbar()->getLevel();
	int RemainingLives = pGame->getToolbar()->getRemainingLives();
	ofstream outfile;
	outfile.open("test.txt");
	outfile << CurrentScore << "\n" << CurrentLevel << "\n" << RemainingLives << "\n";
	pGame->getGrid()->SaveShapes(outfile);
	outfile.close();*/
	//window* pw = pGame->getWind();
	//std::ofstream OutFile("game_save.txt");
	//if (!OutFile) {
	//	// Handle file open error
	//	return;
	//}

	//grid* pGrid = pGame->getGrid();
	///*const std::vector<shape*>& shapes = pGrid->getActiveShape();*/

	///*for (const shape* shape : shape) {
	//	shape->save(OutFile);
	//}*/

	//OutFile.close();
}


operaddload::operaddload(game* r_pGame) :operation(r_pGame)
{
}
void operaddload::Act()
{
	ifstream infile;
	infile.open("test.txt");
	if (infile) {
		int CurrentLevel, RemainingLives, CurrentScore;
		infile >> CurrentScore >> CurrentLevel >> RemainingLives;
		pGame->getToolbar()->setScore(CurrentScore);
		pGame->getToolbar()->setLevel(CurrentLevel);
		pGame->getToolbar()->setRemainingLives(RemainingLives);
		pGame->getGrid()->LoadShapes(infile);
		infile.close();
	}
	else
		pGame->printMessage("There is no such file in the directory");


}
operaddexit::operaddexit(game* r_pGame) :operation(r_pGame)
{
}
void operaddexit::Act()
{
	window* pw = pGame->getWind();

}

operaddmatch::operaddmatch(game* r_pGame):operation(r_pGame)
{
}

void operaddmatch::Act()
{
	
	// //Get the grid from the game
	//grid* pGrid = pGame->getGrid();

	//// Get the active shape from the grid
	//shape* activeShape = pGrid->getActiveShape();

	//if (!activeShape) return;

	//// Get all the shapes in the grid
	//vector<shape*> gridShapes = pGrid->getActiveShape();

	//for (auto it = gridShapes.begin(); it != gridShapes.end(); ++it) {
	//	if (activeShape->match(*it)) {
	//		delete* it;
	//		gridShapes.erase(it);
	//		pGrid-> setActiveShape(shape* activeShape); // Update the shapes vector in the grid
	//		pGame->incScore(); // Increase the score by 2
	//		break;
	//	}
	//	else {
	//		pGame->decScore(); // Decrease the score by 1
	//	}
	//}
}
