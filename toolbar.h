#pragma once
#include "gameConfig.h"
////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class game;
class toolbar
{

private:
	int height, width;
	int Level = 5;
	int Score = 0;
	int Lives = 5;
	string toolbarItemImages[ITM_CNT]; //array to hold paths to images of diffrent items in the toolbar
	game* pGame;

public:
	toolbar(game* r_pGame);
	toolbarItem getItemClicked(int x);	//handles clicks on toolbar icons, returns the "enum" of the clicekd item
	void drawInitialState(int lives, int score, int level);
	void setLevel(int);
	void setScore(int);
	void setRemainingLives(int);
	int getLevel() const;
	int getScore() const;
	int getRemainingLives() const;
};


