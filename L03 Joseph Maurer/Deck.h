/************************************************************************
* Class: Deck
* Updates:
*	1. Now updated to include the copy ctor and op=
*
* Overview:
*		This class makes a deck of playing and has the ability to
*		shuffle those cards and deal one of them. Used in conjunction
*		the the Card class(:
*
* Constructors:
*	Deck()
*		Makes the deck of cards in order and by suit.
*
* Mutators:
*	None.
*
* Methods:
*	void Shuffle()
*		This method randomly shuffles the deck.
*	Card Deal(int m_currentCard)
*		Deals one card but does not display it.
*	static int Getdealtcount()
*		Returns the count of the dealt cards
*	static void Resetdealtcount()
*		Resets the amount of dealt cards to 0
*	~Deck()
*		Gives the memory that was allocated during the program
*		back to the operating system.
*************************************************************************/
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Random.h"

#include <iostream>
using std::cout;

class Deck
{
public:
	// Instantiates the deck of cards
	Deck();
	// Copy CTOR
	Deck(const Deck & copy);
	// Op=
	Deck & operator=(const Deck & rhs);
	// Destructor, deallocates memory 
	~Deck();
	// Function to shuffle the deck of cards
	void Shuffle();
	// Deals a card off the top of the deck
	Card  *Deal(int m_currentCard);
	// Returns the count of the dealt cards
	static int Getdealtcount();
	// Resets the amount of dealt cards to 0
	static void Resetdealtcount();
private:
	//Static variable for the count								
	static int dealtcount;
	//Used in shuffle 
	Random rand;
	// Var of deck of cards
	Card * m_deck[52];
	//Current card to be dealt
	int m_currentCard;
};
#endif 