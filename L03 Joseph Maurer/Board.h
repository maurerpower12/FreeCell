/************************************************************************
* Class: Board
*
* Updates:
*
* Purpose: This classes purpose is to manage the board areas of the 
*		card game free cell. 
*
* Manager functions:
* 	Board ( )
* 		Calls the other constructors. 
*	Board (const Board & copy)
*		Copy Contructor that will instantiate another board and
*				copy over the data involved with the passed board.
*	operator = (const Board & copy)
*		Transferes the elements of one board into anthor via a deep
*				copy.
*	~Board()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
* Methods:
*	void PlayA();
*		Manages the play area and the contents while moving.
*	bool isValid(Card move, Card bottom);
*		Determines if it was a valid move.
*	void Populate();
*		Populates the play area.
*	PlayArea & getPlay();
*		Returns access to the play area.
*	FreeCellArea & getFree();
*		Returns access to the free area.
*	HomeCellArea & getHome();
*		Returns access to the home area.
*************************************************************************/
#ifndef BOARD_H
#define BOARD_H

#include "PlayArea.h"
#include "FreeCellArea.h"
#include "HomeCellArea.h"
#include "Display.h"

class Board
{
public:
	Board();
	Board(const Board & copy);
	Board & operator=(const Board & rhs);
	~Board();

	void PlayA();
	bool isValid(Card move, Card bottom);
	void Populate();
	PlayArea & getPlay();
	FreeCellArea & getFree();
	HomeCellArea & getHome();
private:
	Deck m_deck;
	PlayArea m_playarea;
	FreeCellArea m_freecell;
	HomeCellArea m_homecell;
	Display m_display;

};

#endif