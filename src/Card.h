/*******************************************************************************
* Ruben Castaneda
* Homework 3: 4 Card Solitaire
* Card.h
* 2/6/15
* Contains prototypes for Card class
* Time Complexity: O(n)
* Storage Complexity: O(n)
*******************************************************************************/

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string.h>

#define _STD ::std::

enum suits{ diamond, club, heart, spade };

class Card {
	int rank;
	suits suit;
public:
	Card();
	Card(suits, int);
	int getRank();
	suits getSuit();
	_STD string toString();
	_STD string getTopLabel();
	_STD string getBotLabel();
};

#endif
