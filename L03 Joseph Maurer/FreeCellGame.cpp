#include "FreeCellGame.h"


/**********************************************************************
* Purpose: This function is a constructor that builds the inital game.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
FreeCellGame::FreeCellGame()
{
	m_display.InitialSetup();
	m_board.PlayA();
	RunGame();
}

/**********************************************************************
* Purpose: This function runs the show... literally.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
void FreeCellGame::RunGame()
{

	while (m_board.getHome().winner() == false)
	{
		int column(0);
		int numcards(0);
		int moveto(0);

		column = m_display.GetColumn();
		if (column != -2)
			numcards = m_display.NumofCards();
		moveto = m_display.GetMoveTo();

		if (numcards > m_board.getFree().CalcMax())
			cout << "Error. Moving too many cards                  \n";
		else
		{
			if (column == 99)
			{
				cheat(column);
				m_board.getHome().winner();
			}
			if (moveto == -2) // case for move to free cell
			{
				if (m_board.getFree().isFull() != true)
				{
					Card * temp;
					temp = m_board.getPlay().
						getStack()[column - 1].Pop();
					m_board.getFree().MovetoFreeCell(temp);
					// move card to the free cell and display
					m_display.PutCardinFreeCell
						(*temp, m_board.getFree().getOpenSpace());
					// clear and re write the baord
					m_display.ClearPlayA();
					m_board.PlayA();
				}
				else
					cout << "Invalid: No more space in the free cells                   \n";
			}

			else if (moveto == -1) // Case for move to home cell
			{
				Card * temp;
				temp = m_board.getPlay().
					getStack()[column - 1].Peek();
				if (m_board.getHome().SetHomeCell(*temp, 0) == true)
				{
					Card * temp2;
					temp2 = m_board.getPlay().
						getStack()[column - 1].Pop();
					m_display.PutCardinHomeCell(*temp2);
					m_display.ClearPlayA();
					m_board.PlayA();
				}
				else
					cout << "Invalid: Move to Home Cells was invalid                         \n";
			}
			//case for moving from a free cell to board
			else if (column == -2)
			{
				if (m_board.getFree().getOpenSpace() != 0)
				{

					bool valid(true);
					while (valid)
					{
						int move(0);
						cout << "\n\nWhat card would you like to take out? ";
						cin >> move;
						if (move > 4 || move <= 0)
						{
							cout << "Error. Invalid                                        ";
							valid = true;
						}
						else
						{
							valid = false;
							if (m_board.isValid(*m_board.getFree().getFree()[move - 1],
								*m_board.getPlay().getStack()[moveto - 1].Peek()))
							{
								m_board.getPlay().getStack()[moveto - 1].
									Push(m_board.getFree().getFree()[move - 1]);
								m_board.getFree().RemovefromFreeCell(move - 1);
								m_display.ClearPlayA();
								clean(move);
								m_board.PlayA();
							}
							else
								cout << "Invalid Move.                                                    ";
						}
					}

				}
				else
					cout << "Invalid: Nothing in Free Cell area to move                       ";
			}

			else if (column != 99) // case for actual move
			{
				if (numcards > 1) // case to check moving multiple cards
				{
					LLStack<Card *> s1;
					for (int i(0); i < numcards; i++)
					{
						s1.Push(m_board.getPlay().
							getStack()[column - 1].Pop());

						if (m_board.isValid(*s1.Peek(),
							*m_board.getPlay().
							getStack()[moveto - 1].Peek()))
						{
							for (int i(0); i < numcards; i++)
							{
								m_board.getPlay().
									getStack()[moveto - 1].Push
									(s1.Pop());
							}
							m_display.ClearPlayA();
							m_board.PlayA();
						}
					}

				}

				else if (m_board.isValid(*m_board.getPlay().
					getStack()[column - 1].Peek(),
					*m_board.getPlay().getStack()[moveto - 1].Peek()))
				{
					// Push the card onto the stack
					m_board.getPlay().getStack()[moveto - 1].Push
						(m_board.getPlay().
						getStack()[column - 1].Pop());

					m_display.ClearPlayA();
					m_board.PlayA();
				}
				else
					cout << "Invalid Move. Opposite color, and a greater value of 1 more is required";
			}

		}

	}
	if (m_board.getHome().winner() == true)
		m_display.winner();
}

/**********************************************************************
* Purpose: This function is a constructor that builds the inital Node.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
void FreeCellGame::clean(int position)
{
	if (position == 1)
		m_display.XandY(position, 3);
	else if (position == 2)
		m_display.XandY((position + 5), 3);
	else if (position == 3)
		m_display.XandY((position + 10), 3);
	else
		m_display.XandY((position + 15), 3);
	cout << "    ";
}

/**********************************************************************
* Purpose: This function allows for a cheat in the game.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
void FreeCellGame::cheat(int pass)
{
	Card c1(KING, DIAMOND);
	m_board.getHome().SetHomeCell(c1, pass);
	Card c2(KING, HEART);
	m_board.getHome().SetHomeCell(c2, pass);
	Card c3(KING, CLUB);
	m_board.getHome().SetHomeCell(c3, pass);
	Card c4(KING, SPADE);
	m_board.getHome().SetHomeCell(c4, pass);
}
/**********************************************************************
* Purpose: This function is a DTOR.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
FreeCellGame::~FreeCellGame()
{}
