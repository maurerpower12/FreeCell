#include "Display.h"
#include <windows.h> // needed to display Ranks color
#include <iomanip>  // needed to align stuff
using std::setw;
HANDLE clean = GetStdHandle(STD_OUTPUT_HANDLE);

/**********************************************************************
* Purpose: This function is a constructor that sets color and size.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
Display::Display()
{
	// Resize the window
	HWND console = GetConsoleWindow();
	RECT r;
	//gets the console's dimensions
	GetWindowRect(console, &r);
	//moves window to full screen-ish
	MoveWindow(console, 0, 0, 1000, 600, TRUE);

	SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}

/**********************************************************************
* Purpose: This function sets up baord for the first time.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
void Display::InitialSetup()
{
	system("CLS"); // call here to make background white
	Header();
	PlayAHeader();
}

/**********************************************************************
* Purpose: This function sets the cursor to a certain position.
*
* Entry: This function takes an x and y coordinate.
*
* Exit: This function does not have a return.
*
************************************************************************/
void Display::XandY(int x, int y)
{
	COORD ord;
	ord.X = x;
	ord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);
}
/**********************************************************************
* Purpose: This function a DTOR.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
Display::~Display()
{}
/**********************************************************************
* Purpose: This function displays top line of board.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
void Display::Header()
{
	cout << "\tFree Cells";
	// Vertical lines in playing board
	FreeandHomeDisplay(0,3,2,0, 0);

	XandY(55, 0);
	cout << "\t\tHome Cells";
	FreeandHomeDisplay(55, 3, 2, 0, 55);

	XandY(32, 0);
	AsciiArt(33, 2);

}

/**********************************************************************
* Purpose: This function displays the home and free cell areas of the 
*			board.
*
* Entry: This function takes the starting coordinates. 
*
* Exit: This function does not have a return.
*
************************************************************************/
void Display::FreeandHomeDisplay(int left, int right, int top,
	int bottom, int reset)
{
	for (int j(0); j < 5; j++)
	{
		if (j <= 3) // dislpays # before line
		{
			XandY((left + 3), 1);
			cout << (j + 1);
		}// prints out the lines
		for (int i(3); i <= 5; i++)
		{
			if (i > 0)
			{
				XandY((left), i - 1);
				cout << char(179);
			}
		}
		left = left + 6;
	}

	left = reset;

	for (int j(0); j < 2; j++)
	{
		XandY(left, top);

		for (int i(0); i <= 24; i++)
			cout << char(196); // ─
		top = top + 3;
	}
}

/**********************************************************************
* Purpose: This function display numbers of the play area.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
void Display::PlayAHeader()
{
	SetConsoleTextAttribute(clean, 1 | BACKGROUND_INTENSITY
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	XandY(4, 7);
	for (int i(0); i < 8; i++)
	{
		cout << (i + 1);
		if (i < 7)
		{
			cout << "         ";
		}
	}
	SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	cout << '\n';
}

/**********************************************************************
* Purpose: Displays some ascii art.
*
* Entry: This function takes some starting coordinates.
*
* Exit: This function does not have a return.
*
************************************************************************/
void Display::AsciiArt(int x, int y)
{
	SetConsoleTextAttribute(clean, 8 | BACKGROUND_INTENSITY
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	cout << char(218) << "-----\n";
	for (int i(0); i < 4; i++)
	{
		XandY((x - 1), i+1);
		cout << '|';
	}
	XandY(x, y);
	cout << "----";
	XandY((x + 2), y + 2);
	cout << "ree";

	XandY(x + 7, 0);
	cout << char(218) << "-----\n";
	for (int j(0); j < 4;j++)
	{
		XandY((x + 7), j + 1);
		cout << '|';
	}
	XandY(x+7, 5);
	cout << char(192) << "-----\n";
	XandY((x + 9), y + 2);
	cout << "ell";
	XandY((55), 55);
	SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}

/**********************************************************************
* Purpose: This function gets column value from the user.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the entered value if valid.
*
************************************************************************/
int Display::GetColumn()
{
	bool valid(false);
	int column;
	while (valid == false)
	{

		XandY(0, 25);
		for (int i(0); i < 50; i++)
			cout << "            ";
		XandY(0, 25);
		cout << "Column: ";
		cout << "\n\nEnter -2 to move from Free Cells\n";
		XandY(30, 0);
		cout << ' ';
		XandY(8, 25);
		for (int i(0); i < 10; i++)
		cout << "            ";
		XandY(8, 25);
		cin >> column;
		if (column > 8 || column == 0 || column == -1 || column < -2 )
		{
			SetConsoleTextAttribute(clean, 12 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(60, 25);
			cout << "Invalid Range.";
			if (column == 99)
				valid = true;
		}
		else if (column == -2) // Case for move to free cell
		{
			SetConsoleTextAttribute(clean, 11 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

			int answer(0);
			XandY(20, 25);
			for (int i(0); i < 7; i++)
				cout << "                                               ";
			XandY(20, 25);
			cout << "Would you like to try to move from a free cell? yes=1 no=0 ";
			cin >> answer;
			XandY(20, 25);
			for (int i(0); i < 7; i++)
				cout << "                                               ";
			SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			if (answer == 1)
				valid = true;
		}
		else
		{
			valid = true;
			SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(0, 25);
			cout << "                                               ";
			cout << "                                               ";
		}
	}
	m_column = column;
	return column;
}


/**********************************************************************
* Purpose: This function gets number of cards to move value from the
*		user.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the entered value if valid.
*
************************************************************************/
int Display::NumofCards()
{
	bool valid(false);
	int numcards;
	while (valid == false)
	{

		XandY(0, 25);
		cout << "# of cards to move: ";
		XandY(30, 0);
		cout << ' ';
		XandY(19, 25);
		cout << "            ";
		XandY(19, 25);
		cin >> numcards;
		if (numcards > 8 || numcards <= 0)
		{
			SetConsoleTextAttribute(clean, 12 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(60, 25);
			cout << "Invalid Range.";
		}
		else
		{
			valid = true;
			SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(0, 25);
			cout << "                                               ";
			cout << "                                               ";
		}
	}
	m_numofcards = numcards;
	return numcards;
}


/**********************************************************************
* Purpose: This function gets column value to move to from the user.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the entered value if valid.
*
************************************************************************/
int Display::GetMoveTo()
{
	bool valid(false);
	int column;
	while (valid == false)
	{

		XandY(0, 25);
		cout << "Move to Column:     ";
		cout << "\n\nEnter -1 to move to Home Cells   \n";
		cout << "Enter -2 to move to Free Cells   \n";
		XandY(30, 0);
		cout << ' ';
		XandY(17, 25);
		cout << "            ";
		XandY(17, 25);
		cin >> column;
		if (column > 8 || column == 0 || column <= -3)
		{
			SetConsoleTextAttribute(clean, 12 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(40, 25);
			cout << "                                               ";
			cout << "                                               ";
			XandY(60, 25);
			cout << "Invalid Range.";
		}
		else if (m_column == column)
		{
			SetConsoleTextAttribute(clean, 12 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(44, 25);
			cout << "Can't move to same column. Try again";
		}
		else if (column == -1) // Case for move to home cell
		{
			SetConsoleTextAttribute(clean, 10 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(20, 25);
			int answer(0);
			for (int i(0); i < 7; i++)
				cout << "                                               ";
			XandY(20, 25);
			cout << "Would you like to try to move to a home cell? yes=1 no=0 ";
			cin >> answer;
			XandY(20, 25);
			for (int i(0); i < 7; i++)
			cout << "                                               ";
			SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			if (answer == 1)
				valid = true;
		}
		else if (column == -2) // Case for move to free cell
		{
			SetConsoleTextAttribute(clean, 11 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			
			int answer(0);
			XandY(20, 25);
			for (int i(0); i < 7; i++)
				cout << "                                               ";
			XandY(20, 25);
			cout << "Would you like to try to move to a free cell? yes=1 no=0 ";
			cin >> answer;
			XandY(20, 25);
			for (int i(0); i < 7; i++)
			cout << "                                               ";
			SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			if (answer == 1)
				valid = true;
		}
		if (column == -1 && m_column == -2)
		{
			SetConsoleTextAttribute(clean, 12 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(44, 25);
			cout << "Can't move to same column. Try again";

		}
		else
		{
			valid = true;
			SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(0, 25);
			for (int i(0); i < 7; i++)
			cout << "                                               ";
		}
	}
	m_moveto = column;
	return column;
}

/**********************************************************************
* Purpose: This function displays a card in a free cell.
*
* Entry: This function takes a card and a positon(1-4).
*
* Exit: This function returns nothing.
*
************************************************************************/
void Display::PutCardinFreeCell(Card free, int position)
{
	if (position == 1)
		XandY(position, 3);
	else if (position == 2)
		XandY((position + 5), 3);
	else if (position == 3)
		XandY((position + 10), 3);
	else 
		XandY((position + 15), 3);

	free.DisplayCard();
}


/**********************************************************************
* Purpose: This function puts a card in a home cell. 
*
* Entry: This function takes a card to display.
*
* Exit: This function returns nothing.
*
************************************************************************/

void Display::PutCardinHomeCell(Card home)
{

	int position(55);
	Suit temp = home.GetSuit();

	for (int i(0); i < 4; i++)
	{

		if (temp == SPADE)
			XandY((position + 1), 3);
		else if (temp == DIAMOND)
			XandY((position + 7), 3);
		else if (temp == HEART)
			XandY(position + 13, 3);
		else if (temp == CLUB)
			XandY(position + 19, 3);
		home.DisplayCard();
	}
}

/**********************************************************************
* Purpose: This function clears the play area.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a clean play area.
*
************************************************************************/
void Display::ClearPlayA()
{
	for (int i(0); i < 8; i++)
	{
			XandY(3, 8);

			for (int j(0); j < 15; j++)
			{
				for (int a(0); a < 60; a++)
				cout << ' ';
			}
	}
}


/**********************************************************************
* Purpose: This function displays the winner screen
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns nothing.
*
************************************************************************/
void Display::winner()
{
	system("CLS");
	XandY(32, 0);
	AsciiArt(33, 2);
	XandY(30, 15);
	cout << "You won the game!!!!\n";
	XandY(0, 0);
	cout << ' ';
	XandY(30, 20);
	system("pause");
	
}

