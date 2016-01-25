#include "Deck.h"
#include "Card.h"
#include "Rank.h"
const int NUM_CARDS = 52; // Total number of cards in the deck
int Deck::dealtcount = 0; // set number of cards dealt 
/**************************************************************
*	  Purpose: Creates the deck of cards
*
*         Entry: none.
*
*          Exit:  A deck of cards in order by suit and number
*
****************************************************************/
Deck::Deck() : m_currentCard(0)
{
	for (int a(0); a <= 3; a++)//suit
	{
		for (int b(1); b <= 13; b++) // rank
		{
			// dynamically allocate new card with new rank and suit
			m_deck[m_currentCard] = new Card(static_cast<Rank>(b), static_cast<Suit>(a));
			//increment number of cards
			m_currentCard++;
		}
	}
	Shuffle();
}
/**************************************************************
*	  Purpose: Randomly shuffles the cards
*
*         Entry: none.
*
*          Exit:  The deck of cards in a random order every time
*
****************************************************************/
void Deck::Shuffle()
{
	Card * temp = nullptr;// temp to find manipulate cards
	int number = 0;	//random number ditributed 

	for (int x(0); x < NUM_CARDS; x++)
	{
		number = rand.GetRandom(NUM_CARDS); // Get random integer
		temp = m_deck[x];		// move value over to temp
		m_deck[x] = m_deck[number]; // reassign previously moved
		m_deck[number] = temp; // push into new location
	}
}
/**************************************************************
*	  Purpose: Pulls a card off the top of the deck and
*			points the deck at the next card.
*
*         Entry: The deck of cards
*
*          Exit:  A random card and the current card.
*
****************************************************************/
Card * Deck::Deal(int m_currentCard)
{
	//Increment the number of cards dealt
	Deck::dealtcount++;
	//temp card to catch the card needed to be dealt
	Card * Dealin = m_deck[m_currentCard];
	//return the pointer to the card being dealt
	return Dealin;

}
/**************************************************************
*	  Purpose: Returns the number of times a card has been dealt.
*
*         Entry: none.
*
*          Exit:  The number of dealt cards.
*
****************************************************************/
int Deck::Getdealtcount()
{
	return dealtcount;
}
/**************************************************************
*	  Purpose: Resets the dealt count to zero.
*
*         Entry: none.
*
*          Exit:  A reset static variable, dealtcount.
*
****************************************************************/
void Deck::Resetdealtcount()
{
	dealtcount = 0;
}
/**************************************************************
*	  Purpose: Deletes all of the cards.
*
*     Entry: none.
*
*      Exit:  A deleted deck of cards.
*
****************************************************************/
Deck::~Deck()
{
	while (m_currentCard >= 1)
	{
		m_currentCard--; // decrement the count
		delete m_deck[m_currentCard]; // delete the card
		m_deck[m_currentCard] = nullptr; // reset to null 
	}
}

/**************************************************************
*	  Purpose: Calls the op =. Instantiates a Deck object to
*		contents of another object.
*
*     Entry: A deck object by reference.
*
*      Exit:  A new deck object.
*
****************************************************************/
Deck::Deck(const Deck & copy)
{
	*this = copy;
}
/**************************************************************
*	  Purpose: Reassign values from one deck into another.
*
*     Entry: A deck object by reference.
*
*      Exit:  A new deck object.
*
****************************************************************/
Deck & Deck::operator=(const Deck & rhs)
{
	if (this != &rhs)
	{
		// Purge
		for (int i(0); i < (NUM_CARDS); i++)
		{
			if (m_deck[i] != nullptr)
				delete m_deck[i];
			m_deck[i] = nullptr;
		}
		m_currentCard = rhs.m_currentCard;
		int index(0); // current card pointer
		for (int a(0); a <= 3; a++)//suit
		{
			for (int b(1); b <= 13; b++) // rank
			{
				// dynamically allocate new card with new rank and suit
				m_deck[index++] = new Card
					(static_cast<Rank>(rhs.m_deck[index]->GetRank()),
					static_cast<Suit>(rhs.m_deck[index]->GetSuit()));
				//increment number of cards
			}
		}
		dealtcount = rhs.dealtcount;
	}
	return *this;
}

