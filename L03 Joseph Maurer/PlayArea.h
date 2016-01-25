/************************************************************************
* Class: PlayArea
*
* Updates:
*
* Purpose: This classes purpose is to manage the play area of the free
*		cell board. It holds the appropriate getters to help the Board
*		class in playing the game. 
*
* Manager functions:
* 	PlayArea ( )
* 		The default length is eight.
*	PlayArea (const PlayArea & copy)
*		Copy Contructor that will instantiate another stack and
*				copy over the data involved with the passed stack.
*	operator = (const PlayArea & copy)
*		Transferes the elements of one stack into anthor via a deep
*				copy.
*	~PlayArea()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
* Methods:
*	Array<LLStack<Card *>> & getStack()
*		Method allows access to the m_stack variable. This variable is
*		an array of llstack of card pointers.
*
*************************************************************************/

#ifndef PLAYAREA_H
#define PLAYAREA_H

#include "LLStack.h"
#include "Array.h"
#include "Card.h"
#include "Deck.h"

class PlayArea
{
public:
	PlayArea();
	PlayArea(const PlayArea & copy);
	PlayArea & operator=(const PlayArea & rhs);
	~PlayArea();

	Array<LLStack<Card *>> & getStack();
	
private:
	Array<LLStack<Card * >> m_stack;
};
#endif
