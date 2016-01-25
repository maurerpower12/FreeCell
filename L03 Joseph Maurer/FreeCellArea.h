/************************************************************************
* Class: FreeCellArea
*
* Updates:
*
* Purpose: This classes purpose is to manage the free cell area of the free
*		cell board. It holds the appropriate getters to help the Board
*		class in playing the game.
*
* Manager functions:
* 	FreeCellArea ( )
* 		The default length is four.
*	FreeCellArea (const FreeCellArea & copy)
*		Copy Contructor that will instantiate another area and
*				copy over the data involved with the passed area.
*	operator = (const FreeCellArea & copy)
*		Transferes the elements of one area into anthor via a deep
*				copy.
*	~FreeCellArea()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
* Methods:
*	int getOpenSpace();
*		returns the number of open spaces in the area.
*	bool isFull();
*		returns true if the area is full.
*	void MovetoFreeCell(Card * free_card);
*		Move a card into that free cell area.
*	Array<Card *> & getFree();
*		Gets the free cell array.
*	void RemovefromFreeCell(int index);
*		Deletes an card from the free cell.
*	int CalcMax();
*		Calculates the max number of cards you can move.
*************************************************************************/
#ifndef FREECELLAREA_H
#define FREECELLAREA_H

#include "Array.h"
#include "Card.h"

const int MAX_AREA = 4;

class FreeCellArea
{
public:
	FreeCellArea();
	FreeCellArea(const FreeCellArea & copy);
	FreeCellArea operator=(const FreeCellArea & rhs);
	~FreeCellArea();

	int getOpenSpace();
	bool isFull();
	void MovetoFreeCell(Card * free_card);
	Array<Card *> & getFree();
	void RemovefromFreeCell(int index);
	int CalcMax();

private:
	Array<Card *> m_free_cells;
	int m_current_spot;
};
#endif