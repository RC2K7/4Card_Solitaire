/*******************************************************************************
* Ruben Castaneda
* Homework 3: 4 Card Solitaire
* Game.h
* 2/6/15
* Contains prototypes for game class
* Time Complexity: O(n^2)
* Storage Complexity: O(n)
*******************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Deck.h"

#include <vector>

#define _STD ::std::

class Game {
private:
	Deck theDeck;
	_STD vector<_STD vector<Card> > gameBoard;
	bool running;
	bool won;

	void removeCard(int);
	void moveCard(int);
	void printTextGame();
	void printGraphicalGame();
	void checkGameOver();
	void gameOver();
public:
	Game();
	void printGame(bool);
	bool isRunning();
	void drawCards();
	void selectColumn(int);
	void printGameOver();
};

_STD string centerText(int width, _STD string str);
bool compareCards(Card, Card);

#endif
