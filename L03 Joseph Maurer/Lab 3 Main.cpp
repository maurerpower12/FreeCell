/***********************************************************
* Author:			Joseph Maurer
* Lab Number:		CST 211 Lab 03
* Filename:			Lab 3 Main.cpp
* Date Created:		05/1/15
* Modifications:
*
* Overview:
*	This program's purpose is play the card game FreeCell.
*	The implementation uses various of methods including
*	
*
*
* Input:
*	The input should consist of an column value(1-8).
*	Enter 99 for the column value to test the win.
*	
*
* Output:
*	The output of this program will be a board in which
*	the user needs to input values to place cards in
*	valid squares. For output examples, please look in the
*	project file.
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::endl;


#include "FreeCellGame.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	FreeCellGame free;
	return 0;
}