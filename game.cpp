#include "game.h"
#include "gameConfig.h"
#include <cstdlib> 
#include <ctime>



game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();
	// Draw initial state on the toolbar
	gameToolbar->drawInitialState(5, 0, 1);

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

void game::Movenextlevel(int level)
{
	/*bool allShapesMatched = true;
	for (auto& shape : BasicShapes) {
		if (!shape.isMatched()) {
			allShapesMatched = false;
			break;
		}
	}
	if (allShapesMatched) {
		level++;
		for (auto& shape : BasicShapes) {
			shape.setMatched(false);
		}
	}*/
}

void game::generateRandomShapes(int level)
{
	// Clear existing shapes
	for (shape* pShape : shapes) {
		delete pShape;
	}
	shapes.clear();

	// Set the random seed based on current time
	srand(static_cast<unsigned int>(time(nullptr)));

	// Determine the number of shapes based on the game level
	int numShapes = (level >= 3) ? (2 * level - 1) : (level == 2 ? 3 : 1);

	// Get the boundaries of the working area
	int maxWidth = config.windWidth;
	int maxHeight = config.gridHeight;

	// Iterate to create each shape
	for (int i = 0; i < numShapes; ++i) {
		// Generate random position within the working area
		int posX = rand() % maxWidth;
		int posY = rand() % maxHeight;

		// Randomize rotation angle and size
		float rotationAngle = randomFloat(0, 360);
		float sizeFactor = randomFloat(0.5, 2); // Adjust as needed for suitable range

		// Create the shape (example: Sign shape)
		shape* pShape = new Sign(this, { posX, posY });

		// Randomize rotation angle and size
		pShape->setRotationAngle(rotationAngle);
		pShape->setSize(sizeFactor);

		
		// Add the shape to the vector of shapes
		shapes.push_back(pShape);
	}
		// Draw the shape with random color initially
		pShape->setFillColor({ rand() % 256, rand() % 256, rand() % 256 });

		// Add the shape to the vector of shapes
		shapes.push_back(pShape);
}


void game::overlap(int level,shape* shape1, shape* shape2) {
	/*if (level < 3) {
		bool overlap = false;
		for (shape* existingShape : shapes) {
			if (pShape->isOverlapping(existingShape)) {
				overlap = true;
				break;
			}
		}
		if (overlap) {
			delete pShape;
			continue;
		}
	}
	if (level >= 3) {
		for (int i = 0; i < shapes.size(); ++i) {

			int indexToOverlap = rand() % shapes.size();
			while (indexToOverlap == i) {
				indexToOverlap = rand() % shapes.size();
			}
			shapes[i]->Overlap(shapes[indexToOverlap]);
		}
	}*/
}


float game::randomFloat(float min, float max)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	return min + random * (max - min);
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		break;
	case ITM_CAR:
		op = new operaddcar(this);
		break;
	case ITM_ICE:
		op = new operaddice(this);
		break;
	case ITM_TREE:
		op = new operaddtree(this);
		break;
	case ITM_HOME:
		op = new operaddhome(this);
		break;
	case ITM_ROCKET:
		op = new operaddrocket(this);
		break;
	case ITM_INCREASE_SIZE:
		op = new operaddinc(this);
		break;
	case ITM_DECREASE_SIZE:
		op = new operadddec(this);
		break;
	case ITM_ROTATE:
		op = new operaddrotate(this);
		break;
	case ITM_REFRESH:
		op = new operaddrefresh(this);
		break;
	case ITM_HINT:
		op = new operaddhint(this);
		break;
	case ITM_DELETE:
		op = new operadddelete(this);
		break;
	case ITM_SELECT_LEVEL:
		op = new operaddselectlevel(this);
		break;
	case ITM_SAVE:
		op = new operaddsave(this);
		break;
	case ITM_LOAD:
		op = new operaddload(this);
		break;
	case ITM_EXIT:
		op = new operaddexit(this);
		break;
	
	}
	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}



////////////////////////////////////////////////////////////////////////
void game::run() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem=ITM_CNT;
	do
	{
		//printMessage("Ready...");
		//1- Get user click
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem=gameToolbar->getItemClicked(x);

			//3-create the approp operation accordin to item clicked by the user
			operation* op = createRequiredOperation(clickedItem);
			if (op)
				op->Act();

			//4-Redraw the grid after each action
			shapesGrid->draw();

		}	

	} while (clickedItem!=ITM_EXIT);
}