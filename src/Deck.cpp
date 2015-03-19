/*******************************************************************************
* Ruben Castaneda
* Homework 3: 4 Card Solitaire
* Deck.cpp
* 2/6/15
* Deck source file containing the functionality for each of the given functions
* Time Complexity: O(n)
* Storage Complexity: O(n)
*******************************************************************************/

#include "Deck.h"

#include <algorithm>
#include <time.h>

/*******************************************************************************
* Function: Deck
* Summary: Default Deck Constructor
* Time Complexity: O(n)
*******************************************************************************/
Deck::Deck() {
	this->topCard = 0;
	for (int i = 2; i <= 14; i++)
		for (int j = 0; j < 4; j++)
			cards[topCard++] = Card((suits)j, i);

	this->shuffle();
}

/*******************************************************************************
* Function: Shuffle
* Summary: Shuffles the Deck
* Time Complexity: O(1)
*******************************************************************************/
void Deck::shuffle() {
	_STD srand(time(0));
	_STD random_shuffle(this->cards, this->cards + 52);
}

/*******************************************************************************
* Function: isEmpty
* Return: Returns True if Deck is Empty else False
* Time Complexity: O(1)
*******************************************************************************/
bool Deck::isEmpty() {
	return this->topCard <= 0;
}

/*******************************************************************************
* Function: draw
* Return: Returns top Card on deck
* Time Complexity: O(1)
*******************************************************************************/
Card Deck::draw() {
	if (!this->isEmpty())
		return this->cards[--topCard];
}