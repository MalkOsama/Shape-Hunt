#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"
#include <vector> 



//Main class that coordinates the game operation
class game
{

	/// Add more members if needed

	toolbar* gameToolbar;
	
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	vector<shape*> shapes; // Vector to store generated shapes
	int matchesNeeded;
	int currentMatches;
	int score;
	int level=5;
	int lives;
	bool isCalled;


public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();	
	//void Movetonextlevel(int& level);	//creates the shapes grid
	void generateRandomShapes(int level);
	/*void overlap(int level, shape* shape1, shape* shape2);*/
	float randomFloat(float min, float max);
	void handleArrowKeys(keytype ktype);
	void handleSpaceBar();
	void checkLevelCompletion();
	void moveToNextLevel();
	void moveShape(int dx, int dy);

	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid
	toolbar* getToolbar() const;
	int getLevels();
	void drawHome(window*& w, color c, int rx, int ry, int size);
	void setLevel(int newLevel);
	void setLives(int newLives);
	void setScore();
	void incScore();
	void decScore();
	void DisplayTimer();
	void check();

	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);



	void run();	//start the game

};

