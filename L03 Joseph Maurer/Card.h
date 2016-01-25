/************************************************************************
* Class: Card
* Update: 
*	1. Updated Display card function to have an easier display method with
*		less bugs. 
*
* Overview:
*	This class has the ability to manipulate Cards made in conjunction
*	with a deck class. This class deals with the setting, manipulation
*	and displaying of the cards.
*
* Constructors:
*	Card(Rank rank, Suit suit);
*		Can be set to anything that the programmer chooses.
*
* Mutators:
*	Rank GetRank()
*		This mutator returns the Rank of the card.
*	Suit GetSuit()
*		This mutator returns the Suit of the card.
*
* Methods:
*	void DisplayCard()
*		This mutator displays the card.
*	void SetRank(Rank rank)
*		This mutator sets the rank of the card to a Rank.
*	void SetSuit(Suit suit)
*		This mutator sets the suit of the card to a Suit.
*
*************************************************************************/
#ifndef CARD_H
#define CARD_H

#include "Rank.h"

#include <iostream>
using std::cout;
using std::endl;
#include <ostream>
using std::ostream;


class Card
{
public:
	// Constructs the card. Gives it a rank and suit
	Card(Rank rank = ACE, Suit suit = SPADE);
	// Displays the card and suit
	void DisplayCard();
	// Sets the Rank of a card
	void SetsRank(Rank rank);
	// Sets the Suit of a card
	void SetsSuit(Suit suit);
	// Returns the Rank
	Rank GetRank();
	// Returns the Suit
	Suit GetSuit();
	~Card();
private:
	Rank m_rank; // Card Rank
	Suit m_suit; // Card Suit
};
#endif