#pragma once
#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include<string>

class GameBoard {
public:
	GameBoard();
	GameBoard(std::string letters);
	char GetLetterByRowCol(int row, int col);
	std::string ShowBoard();
private:
	char letters[4][4];
};
#endif