#pragma once
#ifndef WORD_FIND_HPP
#define WORD_FIND_HPP
#include "dictionary.hpp"
#include "gameboard.hpp"
#include<set>

class WordFind {
public:
	WordFind();
	std::set<std::string> GetAllWords(GameBoard g);
private:
	Dictionary dictionary;
	void appendDFSWords(GameBoard g, std::string stringPrefix, std::set<std::string>& foundWords, bool alreadyChosen[16], int currentCell);
};
#endif