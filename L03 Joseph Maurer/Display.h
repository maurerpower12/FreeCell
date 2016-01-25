/************************************************************************
* Class: Display
*
* Updates:
*
* Purpose: This classes purpose is to manage the display of everything
*		for the program.
*
* Manager functions:
* 	Display ( )
* 		Sets the default color and size of the board.
*	~Display()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
* Methods:
*	
*	void InitialSetup();
*		Calls proper functions to start up the board display.
*	void XandY(int x, int y);
*		Resets the cursor to the proper position on the baord. 
*	void Header();
*		Displays the top part of the board.
*	void FreeandHomeDisplay(int left, int right, int top, int bottom, int reset);
*		Displays the home and free cell outlines.
*	void PlayAHeader();
*		Display the header for the play area.
*	void AsciiArt(int x, int y);
*		A little ascii art never hurt.
*	int GetColumn();
*		Gets the column value from the user and makes sure its in bounds.
*	int NumofCards();
*		Gets the number of cards value from the user and makes sure 
*		its in bounds.
*	int GetMoveTo();
*		Gets the column value to move to from the user and makes sure 
*		its in bounds.
*	void PutCardinFreeCell(Card free, int position);
*		Displays a cards in the free cell visually.
*	void PutCardinHomeCell(Card home);
*		Displays a cards in the home cell visually.
*	void ClearPlayA();
*		Writes spaces over the play area.
*	void winner();
*		Display for win case.
*************************************************************************/
#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <windows.h> // needed to display symbols color
#include <mmsystem.h>

#include "Card.h"
#include "HomeCellArea.h"
class Display
{
public:
	Display();
	void InitialSetup();
	void XandY(int x, int y);
	void Header();
	void FreeandHomeDisplay(int left, int right, int top, int bottom, int reset);
	void PlayAHeader();
	void AsciiArt(int x, int y);
	int GetColumn();
	int NumofCards();
	int GetMoveTo();
	void PutCardinFreeCell(Card free, int position);
	void PutCardinHomeCell(Card home);
	void ClearPlayA();
	void winner();
	~Display();
private:
	int m_column;
	int m_numofcards;
	int m_moveto;
};

#endif

