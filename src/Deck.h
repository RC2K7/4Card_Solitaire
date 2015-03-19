/*******************************************************************************
* Ruben Castaneda
* Homework 3: 4 Card Solitaire
* Deck.h
* 2/6/15
* Deck header file declaring prototypes of Deck class functions
* Time Complexity: O(n)
* Storage Complexity: O(n)
*******************************************************************************/

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
	Card cards[52];
	int topCard;
public:
	Deck();
	bool isEmpty();
	void shuffle();
	
	Card draw();
};

#endif
