#include "HomeCellArea.h"

/**********************************************************************
* Purpose: This function is a constructor that builds the inital home
*			cell area.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
HomeCellArea::HomeCellArea() : m_home_cell(Array<Stack<Card>>(4, 0))
{
	for (int i(0); i < 4; i++)
		m_home_cell[i].setLength(13);
}

/**********************************************************************
* Purpose: This function is a copy constructor that builds a new object.
*
* Entry: This function takes a copy object by reference.
*
* Exit: This function does not have a return.
*
************************************************************************/
HomeCellArea::HomeCellArea(const HomeCellArea & copy)
{
	*this = copy;
}
/**********************************************************************
* Purpose: This function takes area data and copies it over.
*
* Entry: This function takes a copy object by reference.
*
* Exit: This function returns an copied object.
*
************************************************************************/
HomeCellArea HomeCellArea::operator=(const HomeCellArea & rhs)
{
	if (this != &rhs)
	{
		m_home_cell = rhs.m_home_cell;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function deallocates memory to operating system.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
HomeCellArea::~HomeCellArea()
{}

/**********************************************************************
* Purpose: This function gets the top card value.
*
* Entry: This function takes a column value.
*
* Exit: This function returns a card.
*
************************************************************************/
Card HomeCellArea::GetTop(int column)
{
	return m_home_cell[column].Peek();
}

/**********************************************************************
* Purpose: This function gets if the column is empty.
*
* Entry: This function takes a column value.
*
* Exit: This function a true or false.
*
************************************************************************/
bool HomeCellArea::GetEmpty(int column)
{
	return m_home_cell[column].isEmpty();
}

/**********************************************************************
* Purpose: This function sets the home cell area.
*
* Entry: This function takes a card and integer for a cheat.
*
* Exit: This function does not have a return.
*
************************************************************************/
bool HomeCellArea::SetHomeCell(Card home, int pass)
{
	bool found(true);
	Suit temp = home.GetSuit();
	Rank temp2 = home.GetRank();
	if (temp2 != ACE && pass != 99)
	{
		if (temp == SPADE && temp2 ==
			(m_home_cell[0].Peek().GetRank() + 1) ) 
			m_home_cell[0].Push(home);

		else if (temp == DIAMOND && temp2 ==
			(m_home_cell[1].Peek().GetRank() + 1) )
			m_home_cell[1].Push(home);

		else if (temp == HEART && temp2 ==
			(m_home_cell[2].Peek().GetRank() + 1) )
			m_home_cell[2].Push(home);

		else if (temp == CLUB && temp2 ==
			(m_home_cell[3].Peek().GetRank() + 1) )
			m_home_cell[3].Push(home);

		else
			found = false;
	}
	else
	{
		if (temp == SPADE)
			m_home_cell[0].Push(home);

		else if (temp == DIAMOND )
			m_home_cell[1].Push(home);

		else if (temp == HEART )
			m_home_cell[2].Push(home);

		else if (temp == CLUB)
			m_home_cell[3].Push(home);
		else
			found = false;
	}
	return found;
}
/**********************************************************************
* Purpose: This function checks for a win case.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a true if all kings.
*
************************************************************************/
bool HomeCellArea::winner()
{
	bool win(false);
	for (int i(0); i < 4; i++)
	{
		try
		{
			if (m_home_cell[i].Peek().GetRank() == KING)
				win = true;
			else
				win = false;
		}
		catch (Exception E1)
		{
			win = false;
		}

	}
	return win;
}