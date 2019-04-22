#include "pch.h"
#include "gameboard.hpp"
#include<string>
#include<iostream>

GameBoard::GameBoard()
{
}

GameBoard::GameBoard(std::string letters)
{
	int k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->letters[i][j] = letters[k];
			++k;
		}
	}
}

char GameBoard::GetLetterByRowCol(int row, int col)
{
	return this->letters[row][col];
}

std::string GameBoard::ShowBoard()
{
	std::string board = "";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (j == 3) {
				board = board + letters[i][j] + "\n";
			}
			else {
				board = board + letters[i][j] + " ";
			}
		}
	}
	return board;
}