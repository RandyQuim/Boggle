#pragma once
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#include<string>
#include<unordered_set>

class Dictionary {
public:
	Dictionary();
	bool IsWord(std::string word);
private:
	std::unordered_set<std::string> dictionary;
};
#endif