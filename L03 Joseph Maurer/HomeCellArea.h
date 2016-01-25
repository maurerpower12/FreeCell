/************************************************************************
* Class: HomeCellArea
*
* Updates:
*
* Purpose: This classes purpose is to manage the home cell area of the free
*		cell board. It holds the appropriate getters to help the Board
*		class in playing the game.
*
* Manager functions:
* 	HomeCellArea ( )
* 		The default length is four and a length of 13.
*	HomeCellArea (const HomeCellArea & copy)
*		Copy Contructor that will instantiate another area and
*				copy over the data involved with the passed area.
*	operator = (const HomeCellArea & copy)
*		Transferes the elements of one area into anthor via a deep
*				copy.
*	~HomeCellArea()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
* Methods:
*	Card GetTop(int column);
*		returns the card on the bottom of the stack.
*	bool GetEmpty(int column);
*		Returns true or false based on if the stack is empty.
*	bool SetHomeCell(Card home, int pass);
*		Sets the stack when passed a card.
*  	bool winner();
*		Determines win condition.
*
*************************************************************************/

#ifndef HOMECELLAREA_H
#define HOMECELLAREA_H


#include "Stack.h"
#include "Card.h"
#include "Array.h"

class HomeCellArea
{
public:
	HomeCellArea();
	HomeCellArea(const HomeCellArea & copy);
	HomeCellArea operator=(const HomeCellArea & rhs);
	~HomeCellArea();

	Card GetTop(int column);
	bool GetEmpty(int column);
	bool SetHomeCell(Card home, int pass);
	bool winner();
private:
	Array<Stack<Card>> m_home_cell;

};
#endif