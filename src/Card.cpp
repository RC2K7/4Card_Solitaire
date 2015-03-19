/*******************************************************************************
* Ruben Castaneda
* Homework 3: 4 Card Solitaire
* Card.cpp
* 2/6/15
* Deck source file containing the functionality for each of the given functions
* Time Complexity: O(n)
* Storage Complexity: O(n)
*******************************************************************************/

#include "Card.h"

#include <sstream>

/*******************************************************************************
* Function: Card
* Summary: Default Card Constructor
* Time Complexity: O(1)
*******************************************************************************/
Card::Card() {
	this->rank = 2;
	this->suit = diamond;
}

/*******************************************************************************
* Function: Card
* Params:
*	suitVal: Suit to be assigned to new Card
*	rankVal: Rank to be assigned to new Card
* Summary: Constructor which takes and sets a rank and suit
* Time Complexity: O(1)
*******************************************************************************/
Card::Card(suits suitVal, int rankVal) {
	this->rank = rankVal;
	this->suit = suitVal;
}


/*******************************************************************************
* Function: getRank
* Return: Returns the Rank of a Card
* Time Complexity: O(1)
*******************************************************************************/
int Card::getRank() {
	return this->rank;
}

/*******************************************************************************
* Function: getSuit
* Return: Returns the Suit of a Card
* Time Complexity: O(1)
*******************************************************************************/
suits Card::getSuit() {
	return this->suit;
}

/*******************************************************************************
* Function: toString
* Return: String representation of Card
* Summary: Used in Printing card Rank and Suit while in text based
*	print mode
* Time Complexity: O(1)
*******************************************************************************/
_STD string Card::toString() {
	_STD ostringstream sStream;

	switch (this->getRank()) {
		case 11:
			sStream << "Jack";
			break;
		case 12:
			sStream << "Queen";
			break;
		case 13:
			sStream << "King";
			break;
		case 14:
			sStream << "Ace";
			break;
		default:
			sStream << this->getRank();
	}

	switch (this->getSuit()) {
		case diamond:
			sStream << " of Diamonds";
			break;
		case spade:
			sStream << " of Spades";
			break;
		case heart:
			sStream << " of Hearts";
			break;
		case club:
			sStream << " of Clubs";
			break;
	}

	return sStream.str();
}

/*******************************************************************************
* Function: getTopLabel
* Return: Top label of card in graphical string representation of Card
* Summary: Used in Printing card Rank and Suit while in graphical based
*	print mode Ex. [ |Q .--. D| ]
* Time Complexity: O(1)
*******************************************************************************/
_STD string Card::getTopLabel() {
	_STD ostringstream sStream;
	sStream << "|";

	switch (this->getRank()) {
	case 14:
		sStream << "A ";
		break;
	case 13:
		sStream << "K ";
		break;
	case 12:
		sStream << "Q ";
		break;
	case 11:
		sStream << "J ";
		break;
	case 10:
		sStream << "10";
		break;
	default:
		sStream << this->getRank() << " ";
		break;
	}

	sStream << ".--. ";

	switch (this->getSuit()) {
	case diamond:
		sStream << "D|";
		break;
	case spade:
		sStream << "S|";
		break;
	case heart:
		sStream << "H|";
		break;
	case club:
		sStream << "C|";
		break;
	}

	return sStream.str();
}

/*******************************************************************************
* Function: getBotLabel
* Return: Bottom label of card in graphical string representation of Card
* Summary: Used in Printing card Rank and Suit while in graphical based
*	print mode Ex. [ |D '--' Q| ]
* Time Complexity: O(1)
*******************************************************************************/
_STD string Card::getBotLabel() {
	_STD ostringstream sStream;
	sStream << "|";

	switch (this->getSuit()) {
	case diamond:
		sStream << "D ";
		break;
	case spade:
		sStream << "S ";
		break;
	case heart:
		sStream << "H ";
		break;
	case club:
		sStream << "C ";
		break;
	}

	sStream << "'--'";

	switch (this->getRank()) {
	case 14:
		sStream << " A|";
		break;
	case 13:
		sStream << " K|";
		break;
	case 12:
		sStream << " Q|";
		break;
	case 11:
		sStream << " J|";
		break;
	case 10:
		sStream << "10|";
		break;
	default:
		sStream << " " << this->getRank() << "|";
		break;
	}

	return sStream.str();
}