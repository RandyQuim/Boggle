#include "pch.h"
#include "game.hpp"
#include "word_find.hpp"
#include<algorithm>
#include<random>
#include<iostream>

Game::Game()
{
	initDice();
	WordFind wordFind;
	GameBoard gameBoard(GetAllDiceValues());
	this->board = gameBoard;
	this->fullSetOfCorrectWords = wordFind.GetAllWords(this->board);
}

Game::Game(std::string diceRolls)
{
	WordFind wordFind;
	GameBoard gameBoard(diceRolls);
	this->board = gameBoard;
	this->fullSetOfCorrectWords = wordFind.GetAllWords(board);
}

std::string Game::ShowBoard()
{
	return board.ShowBoard();
}

bool Game::Guess(std::string word)
{
	if (IsValidGuess(word)) {
		if (NewWord(word)) {
			correctGuesses.insert(word);
			return true;
		}
		else {
			return false;
		}
	}
	++this->numberOfWrongGuesses;
	return false;
}

int Game::GetScore()
{
	std::set<std::string>::iterator itr;
	int totalPoints = 0;
	for (itr = this->correctGuesses.begin(); itr != this->correctGuesses.end(); itr++) {
		totalPoints += GetWordScore(*itr);
	}
	return totalPoints;
}

int Game::GetIncorrectGuesses()
{
	return this->numberOfWrongGuesses;
}

int Game::GetTotalPointsPossible()
{
	std::set<std::string>::iterator itr;
	int totalPoints = 0;
	for (itr = this->fullSetOfCorrectWords.begin(); itr != this->fullSetOfCorrectWords.end(); itr++) {
		totalPoints += GetWordScore(*itr);
	}
	return totalPoints;
}

void Game::initDice()
{
	Die d1("RIFOBX"), d2("IFEHEY"), d3("DENOWS"), d4("HMSRAO"), d5("LUPETS"), d6("ACITOA"), d7("YLGKUE"), d8("QBMJOA");
	Die d9("EHISPN"), d10("VETIGN"), d11("BALIYT"), d12("EZAVND"), d13("RALESC"), d14("UWILRG"), d15("PACEMD"), d16("UTOKND");
	this->dice[0] = d1,	this->dice[1] = d2, this->dice[2] = d3,	this->dice[3] = d4,	this->dice[4] = d5,	this->dice[5] = d6,	this->dice[6] = d7,
	this->dice[7] = d8, this->dice[8] = d9,	this->dice[9] = d10, this->dice[10] = d11, this->dice[11] = d12, this->dice[12] = d13,
	this->dice[13] = d14, this->dice[14] = d15, this->dice[15] = d16;
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(dice), std::end(dice), rng);
}

std::string Game::GetAllDiceValues()
{
	std::string allLetters = "";
	for (int i = 0; i < 16; ++i) {
		allLetters += this->dice[i].Roll();
	}
	return allLetters;
}

bool Game::IsValidGuess(std::string word)
{
	if (this->fullSetOfCorrectWords.find(word) == this->fullSetOfCorrectWords.end()) {
		return false;
	}
	return true;
}

bool Game::NewWord(std::string word)
{
	if (this->correctGuesses.find(word) == this->correctGuesses.end()) {
		return true;
	}
	return false;
}

int Game::GetWordScore(std::string word)
{
	if (word.length() == 3 || word.length() == 4) {
		return 1;
	}
	if (word.length() == 5) {
		return 2;
	}
	if (word.length() == 6) {
		return 3;
	}
	if (word.length() == 7) {
		return 4;
	}
	if (word.length() >= 8) {
		return 11;
	}
	return 0;
}

int Game::GetPointsForSet(const std::set<std::string>& wordList)
{
	std::set<std::string>::iterator itr;
	int totalPoints = 0;
	for (itr = wordList.begin(); itr != wordList.end(); itr++) {
		totalPoints += GetWordScore(*itr);
	}

	return totalPoints;
}
