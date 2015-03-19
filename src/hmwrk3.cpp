/*******************************************************************************
* Ruben Castaneda
* Homework 3: 4 Card Solitaire
* hmwrk3.cpp
* 2/6/15
* Main class which creates a game instance of solitaire and runs through the
*	game until game has been declared as over printing out results.
* Time Complexity: O(n)
* Storage Complexity: O(n)
*******************************************************************************/

#include <iostream>
#include <string>

#include "Game.h"

/*******************************************************************************
* Function: main
* Summary: Main function creation solitaire instance and looping
*	while the game is running/
* Time Complexity: O(n)
*******************************************************************************/
int main() {
	Game solitaire;
	bool enableGraphics = false;

	//STRING!!!!
	_STD string inGraphics;
	_STD cout << "Enabled Graphics Mode [1/0]: ";
	_STD cin >> inGraphics;

	if (inGraphics == "1")
		enableGraphics = true;	

	while (solitaire.isRunning()) {
		
		solitaire.printGame(enableGraphics);

		_STD cout << "Enter a column number (0 to draw four new cards): ";
		_STD string input;
		_STD cin >> input;

		if (input == "0")
			solitaire.drawCards();
		else if (input == "1")
			solitaire.selectColumn(0);
		else if (input == "2")
			solitaire.selectColumn(1);
		else if (input == "3")
			solitaire.selectColumn(2);
		else if (input == "4")
			solitaire.selectColumn(3);
	}

	return 0;
}
