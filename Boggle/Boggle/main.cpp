// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "game.hpp"

using namespace std;

int main()
{
	cout << "Loading...";
	Game game;
	string word = "";
	cout << endl << endl;
	cout << game.ShowBoard() << endl;
	cout << "Enter a word (q to quit): ";
	cin >> word;
	while (word != "q") {
		if (!game.Guess(word)) {
			cout << "Not worth any points" << endl;
		}
		if (game.GetScore() == game.GetTotalPointsPossible()) {
			cout << "Congratulations! You achieved " << game.GetTotalPointsPossible() << 
				" out of " << game.GetTotalPointsPossible() << " possible points!" << endl;
		}
		cout << "Enter a word: ";
		cin >> word;
	}
	cout << "You got " << game.GetScore() << " points and had " << game.GetIncorrectGuesses() << " incorrect guesses." << endl;
	cout << "There were " << game.GetTotalPointsPossible() << " points possible" << endl;
}