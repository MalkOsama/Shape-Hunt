#include "game.h"
#include "gameConfig.h"
#include <cstdlib> 
#include <ctime>
#include<chrono>
#include<thread>



game::game(): score(0), level(1), currentMatches(0)
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
	 generateRandomShapes(level);
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
	for (shape* pShape : shapes) {
		delete pShape;
	}
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


//void game::Movetonextlevel(int& level) {
//	bool allShapesMatched = true;
//
//	for ( shape* pShape : shapes) {
//		if (!shapes.isMatched()) {
//			allShapesMatched = false;
//			break;
//		}
//	}
//
//	if (allShapesMatched) {
//		++level;
//	}
//}

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

		pShape->setFillColor({ static_cast<unsigned char>(rand() % 256),
					   static_cast<unsigned char>(rand() % 256),
					   static_cast<unsigned char>(rand() % 256) });
		// Add the shape to the vector of shapes
		shapes.push_back(pShape);
		
	}

}

//
//void game::overlap(int level, shape* shape1, shape* shape2) {
//	if (level < 3) {
//		bool overlap = false;
//		for (shape* existingShape : shapes) {
//			if (shape1->isOverlapping(existingShape) || shape2->isOverlapping(existingShape)) {
//				overlap = true;
//				break;
//			}
//		}
//		if (overlap) {
//			delete shape1;
//			delete shape2;
//		}
//		else {
//			shapes.push_back(shape1);
//			shapes.push_back(shape2);
//		}
//	}
//	else {
//		for (size_t i = 0; i < shapes.size(); ++i) {
//			int indexToOverlap = rand() % shapes.size();
//			while (indexToOverlap == i) {
//				indexToOverlap = rand() % shapes.size();
//			}
//			shapes[i]->Overlap(shapes[indexToOverlap]);
//		}
//	}
//}


float game::randomFloat(float min, float max)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	return min + random * (max - min);
}


void game::handleArrowKeys(keytype ktype)
{
	switch (ktype)
	{
	case LEFT_ARROW:
		moveShape( -10, 0);
		break;
	case RIGHT_ARROW:
		moveShape( 10, 0);
		break;
	case UP_ARROW:
		moveShape( 0, -10);
		break;
	case DOWN_ARROW:
		moveShape( 0, 10);
		break;
	}
}

void game::handleSpaceBar()
{
	shape* activeShape = shapesGrid->getActiveShape();
	if (!activeShape) return;

	for (auto it = shapes.begin(); it != shapes.end(); ++it) {
		if (activeShape->match(*it)) {
			delete* it;
			shapes.erase(it);
			score += 2;
			currentMatches++;
			break;
		}
		else {
			score -= 1;
		}
	}

	printMessage("Score: " + std::to_string(score));
	checkLevelCompletion();
}

void game::checkLevelCompletion()
{
	if (currentMatches >= matchesNeeded) {
		moveToNextLevel();
	}
}

void game::moveToNextLevel()
{
	level++;
	generateRandomShapes(level);
	shapesGrid->draw();
	gameToolbar->drawInitialState(5, score, level);
}

void game::moveShape(int dx, int dy)
{
	shape* activeShape = shapesGrid->getActiveShape();
	if (!activeShape) return;

	// Move the active shape by dx, dy
	activeShape->moveBy(dx, dy);

	// Redraw the grid to update the shape's position
	shapesGrid->draw();
}


operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op = nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		printMessage("sign");
		op = new operAddSign(this);
		break;
	case ITM_CAR:
		printMessage("car");
		op = new operaddCar(this);
		break;
	case ITM_ICE:
		printMessage("ice");
		op = new operaddice(this);
		break;
	case ITM_TREE:
		printMessage("tree");
		op = new operaddTree(this);
		break;
	case ITM_HOME:
		printMessage("home");
		op = new operaddHouse(this);
		break;
	case ITM_CAT:
		printMessage("cat");
		op = new operaddCat(this);
		break;
	case ITM_INCREASE_SIZE:
		printMessage("increase size");
		op = new operaddresizeUp(this);
		break;
	case ITM_DECREASE_SIZE:
		printMessage("decrease size");
		op = new operadddec(this);
		break;
	case ITM_ROTATE:
		printMessage("rotate");
		op = new operaddrotate(this);
		break;
	case ITM_REFRESH:
		printMessage("refresh");
		op = new operaddrefresh(this);
		break;
	case ITM_HINT:
		printMessage("hint");
		op = new operaddhint(this);
		break;
	case ITM_DELETE:
		printMessage("delete");
		op = new operadddelete(this);
		break;
	case ITM_SELECT_LEVEL:
		printMessage("select level");
		op = new operaddselectlevel(this);
		break;
	case ITM_SAVE:
		printMessage("save");
		op = new operaddsave(this);
		break;
	case ITM_LOAD:
		printMessage("load");
		op = new operaddload(this);
		break;
	case ITM_EXIT:
		printMessage("exit");
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

toolbar* game::getToolbar() const
{
	return gameToolbar;
}

int game::getLevels()
{
	return level;
}

void game::drawHome(window*& w, color c, int rx, int ry, int size)
{
	w->SetPen(BLACK, 2);

	w->SetBrush(c);
	w->DrawRectangle(rx, ry, rx + 1.5 * size, ry + size);

	w->SetBrush(HUGE);
	w->DrawTriangle(rx, ry, 1.5 * size + rx, ry, rx + 1.5 * size / 2, ry - size);

	w->SetBrush(STEELBLUE);
	w->DrawRectangle(rx + (size * .95), ry + (size * 0.15), rx + (1.5 * size * .9), ry + (size * .5));

	w->SetBrush(BROWN);
	w->DrawRectangle(rx + (size * .2), ry + (size * 0.42), rx + (size * .5), ry + (size));

	w->DrawLine(rx + (size * .42), ry + (size * .75), rx + (size * .43), ry + (size * .76));
}

void game::setLevel(int newLevel)
{
	isCalled = true;

	this->level = newLevel;

	int X = config.toolbarItemWidth * ITM_CNT;
	int Y = config.toolBarHeight;

	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(X, 0, 1350, Y);


	int TextX = ITM_CNT * config.toolbarItemWidth;


	int LevelY = config.toolBarHeight / 3;
	int ScoreY = 0;
	int LivesY = config.toolBarHeight * 2 / 3;


	pWind->SetPen(BLACK, 10);
	pWind->SetFont(15, BOLD, BY_NAME, "Arial");

	pWind->DrawString(TextX, LevelY, "Level: " + to_string(newLevel));
	pWind->DrawString(TextX, ScoreY, "Score: " + to_string(score));
	pWind->DrawString(TextX, LivesY, "Lives: " + to_string(lives));

	DisplayTimer();
	isCalled = false;
}

void game::setLives(int newLives)
{
	this->level = newLives;

	int X = config.toolbarItemWidth * ITM_CNT;
	int Y = config.toolBarHeight;

	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(X, 0, 1350, Y);


	int TextX = ITM_CNT * config.toolbarItemWidth;

	int LevelY = config.toolBarHeight / 3;
	int ScoreY = 0;
	int LivesY = config.toolBarHeight * 2 / 3;


	pWind->SetPen(BLACK, 10);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");


	pWind->DrawString(TextX, LevelY, "Level: " + to_string(level));
	pWind->DrawString(TextX, ScoreY, "Score: " + to_string(score));
	pWind->DrawString(TextX, LivesY, "Lives: " + to_string(newLives));
}

void game::setScore()
{
	int X = config.toolbarItemWidth * ITM_CNT;
	int Y = config.toolBarHeight;

	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(X, 0, 1350, Y);


	int TextX = ITM_CNT * config.toolbarItemWidth;


	int LevelY = config.toolBarHeight / 3;
	int ScoreY = 0;
	int LivesY = config.toolBarHeight * 2 / 3;


	pWind->SetPen(BLACK, 10);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");


	pWind->DrawString(TextX, LevelY, "Level: " + to_string(level));
	pWind->DrawString(TextX, ScoreY, "Score: " + to_string(score));
	pWind->DrawString(TextX, LivesY, "Lives: " + to_string(lives));
}

void game::incScore()
{
	score += 1;
	setScore();
}

void game::decScore()
{
	score -= 1;
	setScore();
}

void game::DisplayTimer()
{
	// Start a new thread for the timer
	thread timerThread([this]() {
		window* pWind = getWind();
		string timeString;
		int level = getLevels();
		int seconds = 20 * level;
		int minutes = seconds / 60;
		seconds %= 60;

		while (minutes >= 0 && seconds >= 0 && !isCalled) {

			if (isCalled)break;

			pWind->SetPen(config.statusBarColor);
			pWind->SetBrush(config.statusBarColor);
			pWind->DrawRectangle(1125, 550, 1200, 600, FILLED);

			pWind->SetPen(WHITE);
			pWind->SetFont(23, BOLD, MODERN);

			if (minutes < 10)
				timeString += "0" + to_string(minutes) + ":";
			else
				timeString += to_string(minutes) + ":";

			if (seconds < 10)
				timeString += "0" + to_string(seconds);
			else
				timeString += to_string(seconds);

			pWind->DrawString(1125, 560, timeString);

			this_thread::sleep_for(chrono::milliseconds(999)); // Wait for 0.999 second

			if (seconds == 0 && minutes == 0) {

				break;
			}

			if (seconds == 0) {
				minutes--;
				seconds = 59;
			}
			else
				seconds--;

			pWind->SetPen(config.statusBarColor);
			pWind->SetBrush(config.statusBarColor);
			timeString = "";
			pWind->DrawRectangle(1125, 550, 1200, 600, FILLED);
			this_thread::sleep_for(chrono::milliseconds(1)); // refresh the timer in a span of 0.001 second

		}
		});

	// Detach the thread to let it run independently
	timerThread.detach();
}

void game::check()
{
	keytype input;
	char c;
	input = pWind->GetKeyPress(c);
	if (input == ARROW)
	{
		switch (c)
		{
		case LEFT_ARROW:
			moveShape(-10, 0);
			break;
		case RIGHT_ARROW:
			moveShape(10, 0);
			break;
		case UP_ARROW:
			moveShape(0, -10);
			break;
		case DOWN_ARROW:
			moveShape(0, 10);
			break;
		}
	}
	if (input == ESCAPE)
	{
		if (shapesGrid->match())
		{
			score = +2;
		}
		else
		{
			score--;
		}
	}
}



////////////////////////////////////////////////////////////////////////
void game::run() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	shapesGrid->generateRandomShape();
	shapesGrid->draw();
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem=ITM_CNT;
	do
	{
		//printMessage("Ready...");
		//1- Get user click
		pWind->GetMouseClick(x, y);	//Get the coordinates of the user click
	
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
		check();

	} while (clickedItem!=ITM_EXIT);
}