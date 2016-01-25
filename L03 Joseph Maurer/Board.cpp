#include "Board.h"

/**********************************************************************
* Purpose: This function is a constructor that builds the areas.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
Board::Board() : m_deck(Deck()), m_freecell(FreeCellArea()),
         m_homecell(HomeCellArea()), m_playarea(PlayArea())
{
	Populate();
}
/**********************************************************************
* Purpose: This function is a copy constructor.
*
* Entry: This function a copy by reference.
*
* Exit: This function does not have a return.
*
************************************************************************/
Board::Board(const Board & copy)
{
	m_deck = copy.m_deck;
	m_freecell = copy.m_freecell;
	m_homecell = copy.m_homecell;
	m_playarea = copy.m_playarea;
}

/**********************************************************************
* Purpose: This function returns a new object copy.
*
* Entry: This function takes a new copy.
*
* Exit: This function returns a copy.
*
************************************************************************/
Board & Board::operator=(const Board & rhs)
{
	if (this != &rhs)
	{
		m_deck = rhs.m_deck;
		m_freecell = rhs.m_freecell;
		m_homecell = rhs.m_homecell;
		m_playarea = rhs.m_playarea;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function is a DTOR.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
Board::~Board()
{}

/**********************************************************************
* Purpose: This function sets up the play area and displays the update.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
void Board::PlayA()
{
	PlayArea temparea;
	temparea = m_playarea;

	PlayArea temp;
	bool end(true);

	// Put baord in correct order for display.
	for (int i(0); i < 8; i++)
	{
		while (end == true)
		{
			try // loop untill out of bounds
			{
				temp.getStack()[i].Push(temparea.getStack()[i].Pop());
			}
			catch (Exception E1)
			{
				end = false;
			}
		}
		end = true; // reset
	}


	// Display the Board
	int a(0);
	bool valid(true);
	for (int i(0); i < 8; i++)
	{

		while (valid == true)
		{
			if (i == 0)     // column 1
				m_display.XandY(3, 8 + a);
			else if (i == 1) // column 2
				m_display.XandY(11, 8 + a);
			else if (i == 2) // column 3
				m_display.XandY(21, 8 + a);
			else if (i == 3) // column 4
				m_display.XandY(31, 8 + a);
			else if (i == 4) // column 5
				m_display.XandY(41, 8 + a);
			else if (i == 5) // column 6
				m_display.XandY(51, 8 + a);
			else if (i == 6) // column 7
				m_display.XandY(61, 8 + a);
			else             // column 8
				m_display.XandY(71, 8 + a);

			try
			{
				temp.getStack()[i].Pop()->DisplayCard();
				cout << "      \n";
			}
			catch (Exception E1)
			{
				valid = false;
			}
			a++;
		}
		a = 0;
		valid = true;
	}
}

/**********************************************************************
* Purpose: This function initially sets the board.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
void Board::Populate()
{
	Card * c1;
	for (int a(0); a < 52; a++)
	{
		c1 = m_deck.Deal(a);// deal card
		m_playarea.getStack()[a % 8].Push(c1);
	}
}

/**********************************************************************
* Purpose: This function allows access to a play area.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a play area.
*
************************************************************************/
PlayArea & Board::getPlay()
{
	return m_playarea;
}
/**********************************************************************
* Purpose: This function allows access to a play area.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a play area.
*
************************************************************************/
FreeCellArea & Board::getFree()
{
	return m_freecell;
}
/**********************************************************************
* Purpose: This function allows access to a play area.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a play area.
*
************************************************************************/
HomeCellArea & Board::getHome()
{
	return m_homecell;
}
/**********************************************************************
* Purpose: This function returns bool for if a move is valid
*
* Entry: This function takes a top and bottom card.
*
* Exit: This function returns a bool.
*
************************************************************************/
bool Board::isValid(Card move, Card bottom)
{
	bool valid(false);
	Rank move_rank = move.GetRank();
	Suit move_suit = move.GetSuit();

	Rank bottom_rank = bottom.GetRank();
	Suit bottom_suit = bottom.GetSuit();

	// Red onto a black card case
	if (move_suit == HEART || move_suit == DIAMOND)
	{
		if (bottom_suit == CLUB || bottom_suit == SPADE)
		{
			if (move_rank == (bottom_rank - 1))
				valid = true;
		}
	}

	// Black onto a red card case
	if (move_suit == CLUB || move_suit == SPADE)
	{
		if (bottom_suit == HEART || bottom_suit == DIAMOND)
		{
			if (move_rank == (bottom_rank - 1))
				valid = true;
		}
	}

	return valid;
}


