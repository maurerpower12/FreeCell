/************************************************************************
* Class: FreeCellGame
*
* Updates:
*
* Purpose: This classes purpose is to manage the logic behind the game 
*		free cell. Calling the CTOR starts the game.
*
* Manager functions:
* 	FreeCellGame ( )
* 		Starts the game.
*	~FreeCellGame()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
* Methods:
*	void RunGame();
*		Manages the game flow. Calls all the other functions.
*	void clean(int position);
*		Cleans a small area on the board with a space.
*	void cheat(int pass);
*		Best cheat ever. Call by entering 99 as column value.
*
*************************************************************************/
#ifndef FREECELLGAME_H
#define FREECELLGAME_H

#include "Board.h"
#include "Display.h"

class FreeCellGame
{
public:
	FreeCellGame();
	void RunGame();
	void clean(int position);
	void cheat(int pass);
	~FreeCellGame();
private: 
	Board m_board;
	Display m_display;
};
#endif

