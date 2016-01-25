#include "FreeCellArea.h"

/**********************************************************************
* Purpose: This function is a constructor that builds the inital 
*		free cell area.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
FreeCellArea::FreeCellArea() : m_free_cells(Array<Card *>(4, 0)), m_current_spot(0)
{
	for (int i(0); i < MAX_AREA; i++)
		m_free_cells[i] = nullptr;
}

/**********************************************************************
* Purpose: This function is a copy constructor that builds a free cell
*		object.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
FreeCellArea::FreeCellArea(const FreeCellArea & copy)
{
	for (int i(0); i < MAX_AREA; i++)
		m_free_cells[i] = copy.m_free_cells[i];
	m_current_spot = copy.m_current_spot;
}

/**********************************************************************
* Purpose: This function is a assignment from one object to another.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a object with new data.
*
************************************************************************/
FreeCellArea FreeCellArea::operator=(const FreeCellArea & rhs)
{
	if (this != &rhs)
	{
		m_free_cells = rhs.m_free_cells;

		m_current_spot = rhs.m_current_spot;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function resets teh m_free_cell object.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
FreeCellArea::~FreeCellArea()
{
	for (int i(0); i < MAX_AREA; i++)
		m_free_cells[i] = nullptr;
}

/**********************************************************************
* Purpose: This function returns the current amount of open spaces.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns an integer amount.
*
************************************************************************/
int FreeCellArea::getOpenSpace()
{
	return m_current_spot;
}

/**********************************************************************
* Purpose: This function checks to see if area is full.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns if full.
*
************************************************************************/
bool FreeCellArea::isFull()
{
	bool free_cell(false);
	if (m_current_spot == 4)
		free_cell = true;
	return free_cell;
}

/**********************************************************************
* Purpose: This function moves a card to a free cell.
*
* Entry: This function takes a card pointer.
*
* Exit: This function returns an update free cell area.
*
************************************************************************/
void FreeCellArea::MovetoFreeCell(Card * free_card)
{
	if (m_current_spot == 4)
		throw Exception("Invalid: No more space in the free cells\n");
	else
	{
		m_free_cells[m_current_spot] = free_card;
		m_current_spot++;

	}
}

/**********************************************************************
* Purpose: This function allows access to the free cell method.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
Array<Card *> & FreeCellArea::getFree()
{
	return m_free_cells;
}

/**********************************************************************
* Purpose: This function resets a free cell object.
*
* Entry: This function takes a index value.
*
* Exit: This function does not have a return.
*
************************************************************************/
void FreeCellArea::RemovefromFreeCell(int index)
{
	m_free_cells[index] = nullptr;
	m_current_spot--;
}
/**********************************************************************
* Purpose: This function calculates the max cards you can move at once.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns an integer value.
*
************************************************************************/
int FreeCellArea::CalcMax()
{
	int cmax(0);
	cmax = getOpenSpace();
	if (cmax == 0)
		cmax = 5;
	else if (cmax == 1)
		cmax = 4;
	else if(cmax == 2)
		cmax = 3;
	else if(cmax == 1)
		cmax = 2;
	else
		cmax = 1;
	return cmax;
}