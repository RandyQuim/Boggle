#include "pch.h"
#include "word_find.hpp"
#include<iostream>

WordFind::WordFind()
{
}

std::set<std::string> WordFind::GetAllWords(GameBoard g)
{
	std::set<std::string> foundWords;
	std::string stringPrefix = "";
	bool alreadyChosen[16];

	for (unsigned int i = 0; i < sizeof(alreadyChosen); ++i) {
		for (unsigned int j = 0; j < sizeof(alreadyChosen); ++j) {
			alreadyChosen[j] = false;
		}
		appendDFSWords(g, stringPrefix, foundWords, alreadyChosen, i);
	}
	
	return foundWords;
}

void WordFind::appendDFSWords(GameBoard g, std::string stringPrefix, std::set<std::string>& foundWords, bool alreadyChosen[16], int currentCell)
{
	int NUM_OF_ROWS = 4;
	int NUM_OF_COLS = 4;
	int row = currentCell / NUM_OF_ROWS;
	int col = currentCell % NUM_OF_COLS;
	
	stringPrefix = stringPrefix + g.GetLetterByRowCol(row, col);
	if (dictionary.IsWord(stringPrefix)) {
		foundWords.insert(stringPrefix);
	}
	
	alreadyChosen[currentCell] = true;
	for (int i = currentCell - 1; (i <= currentCell + 1) && (i < NUM_OF_ROWS * NUM_OF_COLS); i++) {
		if ((i >= 0) && (row == i / NUM_OF_ROWS) && !alreadyChosen[i]) {
			appendDFSWords(g, stringPrefix, foundWords, alreadyChosen, i);
		}
	}
	for (int j = currentCell - NUM_OF_COLS; (j <= currentCell + NUM_OF_COLS) && (j < NUM_OF_ROWS * NUM_OF_COLS); j = j + NUM_OF_COLS) {
		if ((j >= 0) && (col == j % NUM_OF_COLS) && !alreadyChosen[j]) {
			appendDFSWords(g, stringPrefix, foundWords, alreadyChosen, j);
		}
 	}
	
	int VERTICALLY_ADJACENT_CELL_DIFFERENCE = -(NUM_OF_ROWS * NUM_OF_COLS - NUM_OF_ROWS);
	int HORIZONTALLY_ADJACENT_CELL_DIFFERENCE = -(NUM_OF_COLS - 1);

	if (row == 0 && !alreadyChosen[currentCell - VERTICALLY_ADJACENT_CELL_DIFFERENCE]) {
		appendDFSWords(g, stringPrefix, foundWords, alreadyChosen, currentCell - VERTICALLY_ADJACENT_CELL_DIFFERENCE);
	}
	if (row == 3 && !alreadyChosen[currentCell + VERTICALLY_ADJACENT_CELL_DIFFERENCE]) {
		appendDFSWords(g, stringPrefix, foundWords, alreadyChosen, currentCell + VERTICALLY_ADJACENT_CELL_DIFFERENCE);
	}
	if (col == 0 && !alreadyChosen[currentCell - HORIZONTALLY_ADJACENT_CELL_DIFFERENCE]) {
		appendDFSWords(g, stringPrefix, foundWords, alreadyChosen, currentCell - HORIZONTALLY_ADJACENT_CELL_DIFFERENCE);
	}
	if (col == 3 && !alreadyChosen[currentCell + HORIZONTALLY_ADJACENT_CELL_DIFFERENCE]) {
		appendDFSWords(g, stringPrefix, foundWords, alreadyChosen, currentCell + HORIZONTALLY_ADJACENT_CELL_DIFFERENCE);
	}

	stringPrefix.erase(stringPrefix.length() - 1);
	alreadyChosen[currentCell] = false;
}
