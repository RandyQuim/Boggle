#include "pch.h"
#include "die.hpp"
#include <stdlib.h>
#include<time.h>
#include<string>

Die::Die()
{
}

Die::Die(std::string possibleLetters)
{
	for (int i = 0; i < possibleLetters.length(); i++) {
		this->possibleLetters[i] = possibleLetters[i];
	}
	srand(time(0));
}

char Die::Roll()
{
	return this->possibleLetters[rand() % 6];
}