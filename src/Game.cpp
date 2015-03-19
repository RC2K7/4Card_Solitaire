/*******************************************************************************
* Ruben Castaneda
* Homework 3: 4 Card Solitaire
* Game.cpp
* 2/6/15
* Main game class which houses all functions for running the solitaire game.
*	Including the deck and game board along with functions for playing the game,
*	checking if there is any possible moves, and checking and calling game over.
* Time Complexity: O(n^2)
* Storage Complexity: O(n)
*******************************************************************************/

#include "Game.h"

#include <iostream>
#include <iomanip>
#include <string>

//using std::cout;
//using std::cin;
//using std::setw;

// String that gets printed out if the player loses
const _STD string Lose[7] = {"   ___                 ___              ",
						"  / __|__ _ _ __  ___ / _ \\__ _____ _ _ ",
						" | (_ / _` | '  \\/ -_) (_) \\ V / -_) '_|",
						" _\\___\\__,_|_|_|_\\___|\\___/ \\_/\\___|_|  ",
						" \\ \\ / /__ _  _  | |   ___ __| |_       ",
						"  \\ V / _ \\ || | | |__/ _ (_-<  _|      ",
						"   |_|\\___/\\_,_| |____\\___/__/\\__|      "};

// String that gets printed out of the player wins
const _STD string Win[7] =  {"   ___                 ___              ",
						"  / __|__ _ _ __  ___ / _ \\__ _____ _ _ ",
						" | (_ / _` | '  \\/ -_) (_) \\ V / -_) '_|",
						" _\\___\\__,_|_|_|_\\___|\\___/ \\_/\\___|_|  ",
						" _/\\_ \\ \\ / /__ _  _  \\ \\    / /__ _ _   _/\\_",
						" >  <  \\ V / _ \\ || |  \\ \\/\\/ / _ \\ ' \\  >  <",
						"  \\/    |_|\\___/\\_,_|   \\_/\\_/\\___/_||_|  \\/ "};

/*******************************************************************************
* Function: Game
* Summary: Default Game Constructor, creates the deck and game board
* Time Complexity: O(1)
*******************************************************************************/
Game::Game() {
	this->theDeck = Deck();
	this->gameBoard = _STD vector<_STD vector<Card> >(4);
	this->running = true;
	this->won = false;
}

/*******************************************************************************
* Function: printGame
* Params:
*	graphics: If True print game board in Graphical representation
		else if False print game board in Text representation
* Summary: General print class for printing game board calls either
*	printGraphicalGame or printTextGame to display Cards on game board
* Time Complexity: O(1)
*******************************************************************************/
void Game::printGame(bool graphics = false) {

	_STD cout << "+-----------------------------------------------------------------------------------+\n";
	_STD cout << "|" << centerText(20, "Column 1") << "|" <<
		centerText(20, "Column 2") << "|" <<
		centerText(20, "Column 3") << "|" <<
		centerText(20, "Column 4") << "|" << "\n";
	_STD cout << "+-----------------------------------------------------------------------------------+\n";

	if (graphics)
		this->printGraphicalGame();
	else
		this->printTextGame();
}

/*******************************************************************************
* Function: printTextGane
* Summary: Prints the game board to cout using text based card
*	representation
* Time Complexity: O(n)
*******************************************************************************/
void Game::printTextGame() {
	for (unsigned int i = 0;
		i < this->gameBoard[0].size() ||
		i < this->gameBoard[1].size() ||
		i < this->gameBoard[2].size() ||
		i < this->gameBoard[3].size();
	i++) {
		// Print out text representation of cards to cout
		_STD cout << "|";

		for (int j = 0; j < 4; j++)
			_STD cout << centerText(20, (i < this->gameBoard[j].size() ? this->gameBoard[j][i].toString() : "")) << "|";

		_STD cout << "\n";
	}

	_STD cout << "+-----------------------------------------------------------------------------------+\n\n";
}

/*******************************************************************************
* Function: printGraphicalGame
* Summary: Prints the game board to cout using graphical based card
*	representation
* Time Complexity: O(n)
*******************************************************************************/
void Game::printGraphicalGame() {
	_STD vector<_STD vector<_STD string> > queue(4);

	// Loops through each column on the game board getting and pushing
	// the graphical representation of the cards onto the columns
	// corresponding queue.
	for (unsigned int i = 0; i < 4; i++) {

		for (unsigned int j = 0; j < this->gameBoard[i].size(); j++) {
			// Always push top half of card's graphical representation
			// onto column's queue
			queue[i].push_back(".--------.");
			queue[i].push_back(this->gameBoard[i][j].getTopLabel());

			// If card is on top of column push bottom half of card's
			// graphical representation on column's queue
			if (j == this->gameBoard[i].size() - 1) {
				for (int z = 0; z < 3; z++)
					queue[i].push_back("|  :  :  |");

				queue[i].push_back(this->gameBoard[i][j].getBotLabel());
				queue[i].push_back("'--------'");
			}
		}
	}

	// Prints each columns queue into cout
	for (unsigned int i = 0;
		i < queue[0].size() ||
		i < queue[1].size() ||
		i < queue[2].size() ||
		i < queue[3].size();
	i++) {
		_STD cout << "|";

		for (int j = 0; j < 4; j++)
			_STD cout << centerText(20, (i < queue[j].size() ? queue[j][i] : "")) << "|";

		_STD cout << "\n";
	}

	_STD cout << "+-----------------------------------------------------------------------------------+\n";
}

/*******************************************************************************
* Function: isRunning
* Return: True if the game is running else if the game has ended
*	returns False
* Time Complexity: O(1)
*******************************************************************************/
bool Game::isRunning() {
	return this->running;
}

/*******************************************************************************
* Function: drawCards
* Summary: Draws four cards and places 1 across each of the 4 columns
*	within the game board
* Time Complexity: O(n)
*******************************************************************************/
void Game::drawCards() {
	if (!this->theDeck.isEmpty())
		for (int i = 0; i < 4; i++)
			this->gameBoard[i].push_back(this->theDeck.draw());

	this->checkGameOver();
}

/*******************************************************************************
* Function: selectColumn
* Params:
*	col: Represents what column the player selected to do an action on
* Summary: Using the column selected by the player this determines and
*	calls the corresponding function in which could be done to the card
*	sitting at the top of the column
* Time Complexity: O(1)
*******************************************************************************/
void Game::selectColumn(int col) {
	if (this->gameBoard[col].empty())
		return;
	else if (this->gameBoard[col].back().getRank() == 14)
		this->moveCard(col);
	else
		this->removeCard(col);
}

/*******************************************************************************
* Function: moveCard
* Params:
*	col: Represents what column the player selected to do an action on
* Summary: Used to move an Ace to an empty column
* Time Complexity: O(n)
*******************************************************************************/
void Game::moveCard(int col) {
	_STD cout << "Ace to where? ";
	int input;
	_STD cin >> input;

	if (input >= 1 && input <= 4) {
		if (this->gameBoard[input - 1].empty()) {
			this->gameBoard[input - 1].push_back(this->gameBoard[col].back());
			this->gameBoard[col].pop_back();
		}
	}
}

/*******************************************************************************
* Function: moveCard
* Params:
*	col: Represents what column the player selected to do an action on
* Summary: Determines if selected top card in column is of a lower rank
*	but equal suit to any card of the top cards within the other
*	columns. If it is then it pops the top card on the user selected column
* Time Complexity: O(n)
*******************************************************************************/
void Game::removeCard(int col) {
	Card tmpCard = this->gameBoard[col].back();

	for (int i = 0; i < 4; i++)
		if (!this->gameBoard[i].empty() && compareCards(tmpCard, this->gameBoard[i].back())) {
			this->gameBoard[col].pop_back();
			break;
		}
}


/*******************************************************************************
* Function: checkGameOver
* Summary: Checks if the game should be declared as over by doing 3
*	checks
* Time Complexity: O(n^2)
*******************************************************************************/
void Game::checkGameOver() {
	// If deck is not empty then game is not over
	if (!this->theDeck.isEmpty())
		return;

	// Checks to see if an Ace is on top of a stack and if a column is empty
	// if both true then the game is not over
	bool flagEmpty = this->gameBoard[0].empty() || this->gameBoard[1].empty() || this->gameBoard[2].empty() || this->gameBoard[3].empty();
	if (flagEmpty) {
		if (!this->gameBoard[0].empty() && this->gameBoard[0].back().getRank() == 14)
			return;
		if (!this->gameBoard[1].empty() && this->gameBoard[1].back().getRank() == 14)
			return;
		if (!this->gameBoard[2].empty() && this->gameBoard[2].back().getRank() == 14)
			return;
		if (!this->gameBoard[3].empty() && this->gameBoard[3].back().getRank() == 14)
			return;
	}

	// Checks to see if any top card can be removed
	// If true then game is not over;
	for (int i = 0; i < 4; i++) {
		if (this->gameBoard[i].empty())
			continue;
		for (int j = 0; j < 4; j++) {
			if (this->gameBoard[j].empty())
				continue;
			if (compareCards(this->gameBoard[i].back(), this->gameBoard[j].back()))
				return;
		}
	}

	this->gameOver();
}

/*******************************************************************************
* Function: gameOver
* Summary: Starts game over procedure, checks game board and sets if
*	player has won the game then prints the results.
* Time Complexity: O(1)
*******************************************************************************/
void Game::gameOver() {
	if (this->gameBoard[0].size() == 1 && this->gameBoard[0].back().getRank() == 14)
		if (this->gameBoard[1].size() == 1 && this->gameBoard[1].back().getRank() == 14)
			if (this->gameBoard[2].size() == 1 && this->gameBoard[2].back().getRank() == 14)
				if (this->gameBoard[3].size() == 1 && this->gameBoard[3].back().getRank() == 14)
					this->won = true;

	this->running = false;
	this->printGameOver();
}

/*******************************************************************************
* Function: printGameOver
* Summary: Prints if the player has won or lost the game
* Time Complexity: O(1)
*******************************************************************************/
void Game::printGameOver() {
	for (int i = 0; i < 7; i++)
		_STD cout << (this->won ? Win[i] : Lose[i]) << "\n";
}

/*******************************************************************************
* Function: compareCards
* Params:
*	a: Card to be checked
*	b: Card to be checked against
* Return: True if a & b are the same suits and a's rank is less than b's
* Time Complexity: O(1)
*******************************************************************************/
bool compareCards(Card a, Card b) {
	if (a.getSuit() != b.getSuit())
		return false;
	if (a.getRank() >= b.getRank())
		return false;
	return true;
}

/*******************************************************************************
* Function: centerText
* Summary: Utility function that helps creating columns with centered
*	text.  Used heavily by the print game board functions within
*	the Game class.
* Time Complexity: O(n)
*******************************************************************************/
_STD string centerText(int width, _STD string str) {
	_STD string tmpStr;
	int halfWidth = width / 2;
	int halfStr = str.length() / 2;

	for (int i = 0; i < halfWidth - halfStr; i++)
		tmpStr += " ";

	tmpStr += str;

	int add = width - tmpStr.length();

	for (int i = 0; i < add; i++)
		tmpStr += " ";

	return tmpStr;
}
