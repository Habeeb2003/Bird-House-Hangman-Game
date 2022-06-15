
// headers
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;

// class declaration
class birdHouse {
	
public:		// public members
	birdHouse(string FileName);		// constructor declaration
	~birdHouse();
	string userGuess;
	void PrintBirdHouse();
	void WinGame();
	void setRandomWord();
	/*void setWordLength(unsigned short int wordLen) {

	}*/
	void setUInput(char userInput);
	void setNumGuess();
	string getRandomWord();
	char getUInput();
	unsigned short int getWordLength();
	unsigned short int getNumWords();
	unsigned short int getNumGuess();

private:	// private members
	string* wordList;
	string randomWord;
	unsigned short int NumWords;
	unsigned short int numGuess;
	char uInput;
	unsigned short int wordLength;
};