#include "Card.h"  	
#include <windows.h> // needed to display Ranks color
#include <iomanip>  // needed to align stuff
using std::setw;

const char * rank_txt[] = { // Set the output text of the cards
	"Blank",
	"A",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"10",
	"J",
	"Q",
	"K",
};
int rank_ascii[] = {
	6,		// ♠ black
	3,      // ♥ red
	5,      // ♣ black
	4,      // ♦ red
};

/**************************************************************
*	  Purpose: Sets rank and suit to initaial values.
*
*         Entry: none.
*
*          Exit:  For the suit and rank it sets
*				them equal to Ace and Spades.
*
****************************************************************/
Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit)
{}
/**************************************************************
*	  Purpose: To display a card to the user
*
*         Entry: The rank and suit of a card.
*
*          Exit:  A displayed card to the user.
*
****************************************************************/
void Card::DisplayCard()
{
	//// Handle to set output font/background color
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// Case to display BLACK suit
	if (rank_ascii[m_suit] == 6 || rank_ascii[m_suit] == 5)
	{
		cout << setw(2) << rank_txt[m_rank];
		cout << setw(2) << char(rank_ascii[m_suit]);
	}

	//Case to display RED suit
	else
	{
		SetConsoleTextAttribute(handle,
			12 | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); // 12 is font color red

		cout << setw(2) << rank_txt[m_rank]; // type cast to a char to display ascii things 
		cout << setw(2) << char(rank_ascii[m_suit]);

		SetConsoleTextAttribute(handle,
			BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		// Keep the black text for everything else
	}

}

/**************************************************************
*	  Purpose: Sets Rank of the card.
*
*         Entry: The Rank you want the card to be.
*
*          Exit:  A card with a changed rank.
*
****************************************************************/
void Card::SetsRank(Rank rank)
{
	this->m_rank = rank;
}
/**************************************************************
*	  Purpose: Sets the Suit to a value
*
*         Entry: The suit its to be changed to.
*
*          Exit:  A card with a changed suit.
*
****************************************************************/
void Card::SetsSuit(Suit suit)
{
	this->m_suit = suit;
}
/**************************************************************
*	  Purpose: Gets the rank of a card and returns it
*
*         Entry: A card.
*
*          Exit: The value of the rank.
*
****************************************************************/
Rank Card::GetRank()
{
	return m_rank;
}
/**************************************************************
*	  Purpose: Gets the suit of the card
*
*         Entry: A card.
*
*          Exit:  The value of the suit.
*
****************************************************************/
Suit Card::GetSuit()
{
	return m_suit;
}
/**************************************************************
*	  Purpose: Deletes a card.
*
*         Entry: A card.
*
*          Exit:  Reassigned resources.
*
****************************************************************/
Card::~Card()
{}
