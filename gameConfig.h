#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	int	windWidth=1200, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 70,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
			fillColor = RED,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = windWidth *  (2.0 / 3);
	int RefY = windHeight * (0.5);

	
	
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;
	struct  {
		int bodyWidth = 120, bodyHeight = 50;  
		int wheelRadius = 20;                  
		int roofBase = 100, roofHeight = 40;    
	}carShape;

	struct  {
		int baseWidth = 200, baseHeight = 100;  
		int doorWidth = 40, doorHeight = 80;    
		int roofBase = 240, roofHeight = 120;   
	}houseShape;

	struct treeShape {
		int trunkWidth = 20, trunkHeight = 100; 
		int leavesBase = 100, leavesHeight = 120; 
	}treeShape;

	struct icecreamShape {
		int scoopRadius = 30;                   
		int coneBase = 60, coneHeight = 120;   
	}icecreamShape;

	struct catShape {
		int headRadius = 40;                    
		int earBase = 40, earHeight = 60;       
		int eyeRadius = 8;                      
		int eyeDistance = 40;                   
		int bodyLength = 100, bodyWidth = 80;  
		int tailLength = 60, tailWidth = 20;    
	}catShape;

}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here
	ITM_SIGN,		//Sign shape item
	ITM_CAR,
	ITM_ICE,
	ITM_TREE,
	ITM_HOME,
	ITM_CAT,
	ITM_INCREASE_SIZE,
	ITM_DECREASE_SIZE,
	ITM_ROTATE,
	ITM_REFRESH,
	ITM_HINT,
	ITM_DELETE,
	ITM_SELECT_LEVEL,
	ITM_SAVE,
	ITM_LOAD,
	ITM_EXIT,		//Exit item
	//TODO: Add more items names here

	ITM_CNT		//no. of toolbar items ==> This should be the last line in this enum

};



