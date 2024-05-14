#include "toolbar.h"
#include "game.h"
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_SIGN] = "images\\ToolbarItems\\toolbar_Sign.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";
	toolbarItemImages[ITM_INCREASE_SIZE] = "images\\toolbarItems\\increase_size.jpg";
	toolbarItemImages[ITM_DECREASE_SIZE] = "images\\toolbarItems\\decrease_size.jpg";
	toolbarItemImages[ITM_ROTATE] = "images\\ToolbarItems\\rotate.jpg";
	toolbarItemImages[ITM_REFRESH] = "images\\ToolbarItems\\refresh.jpg";
	toolbarItemImages[ITM_HINT] = "images\\ToolbarItems\\hint.jpg";
	toolbarItemImages[ITM_DELETE] = "images\\ToolbarItems\\delete.jpeg";
	toolbarItemImages[ITM_SELECT_LEVEL] = "images\\ToolbarItems\\select level.jpeg";
	toolbarItemImages[ITM_SAVE] = "images\\ToolbarItems\\save.jpeg";
	toolbarItemImages[ITM_LOAD] = "images\\ToolbarItems\\loading - icon - simple - flat - style - progress - bar - for - upload - download - round - process - wait - computer - load - charge - time - buffering - concept - illustration - isolated - on - white - background - eps - 10 - vector.jpg";
	

	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);
}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

void toolbar::drawInitialState(int lives, int score, int level)
{
	// Draw lives indicator on toolbar
	window* pWind = pGame->getWind();
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, 10, "Lives: " + to_string(lives));



	// Draw score indicator on toolbar
	window* pWind = pGame->getWind();
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(200, 10, "Score: " + to_string(score));



	// Draw level indicator on toolbar
	window* pWind = pGame->getWind();
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(400, 10, "Level: " + to_string(level));
}

