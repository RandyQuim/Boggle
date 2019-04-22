#pragma once
#ifndef DIE_HPP
#define DIE_HPP
#include<string>
class Die {
public:
	Die();
	Die(std::string possibleLetters);
	char Roll();
private:
	char possibleLetters[6];
};

#endif