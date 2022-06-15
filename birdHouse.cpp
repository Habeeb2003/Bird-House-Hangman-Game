#include "birdHouse.h"

birdHouse::birdHouse(string FileName) {					// constructor

	string newFileName = FileName + ".txt";				// concatenate filename
	fstream file;								
	string localStr[100];
	file.open(newFileName, ios::in);					// open file for reading
	if (file.is_open())
	{
		string line;
		NumWords = 0;
		while (getline(file, line)) {					// reading lines in file
			localStr[NumWords] = line;
			NumWords++;
		}
		file.close();
		wordList = new string[NumWords];				
		copy(localStr, localStr + NumWords, wordList);
	}
}

void birdHouse::PrintBirdHouse() {						// print bird house drawing function
	
	switch (numGuess)									
	{
	case 1:
		cout << "------------" << endl;
		cout << "|          |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		break;
	case 2:
		cout << "------------" << endl;
		cout << "|          |" << endl;
		cout << "|          \\" << endl;
		cout << "|           \\" << endl;
		cout << "|            \\" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		break;
	case 3:
		cout << "------------" << endl;
		cout << "|          |" << endl;
		cout << "|         /\\" << endl;
		cout << "|        /  \\" << endl;
		cout << "|       /    \\" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		break;
	case 4:
		cout << "------------" << endl;
		cout << "|          |" << endl;
		cout << "|         /\\" << endl;
		cout << "|        /  \\" << endl;
		cout << "|       /    \\" << endl;
		cout << "|       -------" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		break;
	case 5:
		cout << "------------" << endl;
		cout << "|          |" << endl;
		cout << "|         /\\" << endl;
		cout << "|        /  \\" << endl;
		cout << "|       /    \\" << endl;
		cout << "|       -------" << endl;
		cout << "|       {" << endl;
		cout << "|       {" << endl;
		cout << "|" << endl;
		break;
	case 6:
		cout << "------------" << endl;
		cout << "|          |" << endl;
		cout << "|         /\\" << endl;
		cout << "|        /  \\" << endl;
		cout << "|       /    \\" << endl;
		cout << "|       -------" << endl;
		cout << "|       {     }" << endl;
		cout << "|       {     }" << endl;
		cout << "|" << endl;
		break;
	case 7:
		cout << "------------" << endl;
		cout << "|          |" << endl;
		cout << "|         /\\" << endl;
		cout << "|        /  \\" << endl;
		cout << "|       /    \\" << endl;
		cout << "|       -------" << endl;
		cout << "|       {     }" << endl;
		cout << "|       {     }" << endl;
		cout << "|       -------" << endl;
		break;
	case 8:
		cout << "------------" << endl;
		cout << "|          |" << endl;
		cout << "|         /\\" << endl;
		cout << "|        /  \\" << endl;
		cout << "|       /    \\" << endl;
		cout << "|       -------" << endl;
		cout << "|       {     }" << endl;
		cout << "|       {  0  }" << endl;
		cout << "|       -------" << endl;
		break;
	default:
		break;
	}
}

void birdHouse::WinGame() {

	// print win message to player
	cout << "\n************************" << endl;
	cout << "Nice! You got the word!" << endl;
	cout << "************************" << endl;
	cout << "Enter any character to quit the game: ";
}

void birdHouse::setRandomWord() {							// randomWord member setter
	int randIndex = (rand() % NumWords) + 1;
	randomWord = wordList[randIndex];
	wordLength = randomWord.length();
}

void birdHouse::setUInput(char userInput) {					// uInput member setter
	uInput = userInput;
}

void birdHouse::setNumGuess() {								// numGuess member setter
	numGuess += 1;
}

string birdHouse::getRandomWord() {							// randomWord member getter
	return randomWord;
}

char birdHouse::getUInput() {								// uInput member getter
	return uInput;
}

unsigned short int birdHouse::getWordLength() {				// wordLength varaible getter
	return wordLength;
}

unsigned short int birdHouse::getNumWords() {				// numWords member getter
	return NumWords;
}

unsigned short int birdHouse::getNumGuess() {				// numGuess member getter
	return numGuess;
}

birdHouse::~birdHouse() {									// birdHouse class destructor
	
	// free memory and reset member values to zero
	numGuess = 0;
	wordLength = 0;
	NumWords = 0;
	delete[] wordList;
}