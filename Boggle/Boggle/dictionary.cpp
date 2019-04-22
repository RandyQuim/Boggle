#include "pch.h"
#include "dictionary.hpp"
#include<fstream>
#include<iostream>

Dictionary::Dictionary()
{
	std::ifstream dictFile;
	dictFile.open("words.txt");
	if (!dictFile.is_open()) {
		std::cout << "Unable to open file!" << std::endl;
	}

	std::string word;
	while (dictFile >> word) {
		this->dictionary.insert(word);
	}
}

bool Dictionary::IsWord(std::string word)
{
	if (this->dictionary.find(word) == this->dictionary.end()) {
		return false;
	}
	return true;
}
