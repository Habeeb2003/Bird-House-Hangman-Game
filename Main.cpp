#include "birdHouse.h"

int main(){		// main function
	
	srand(time(NULL));			// set seed
	string fileName;

	// print welcome message
	cout << "************************" << endl;
	cout << "**Welcome to BirdhOUSE**" << endl;
	cout << "************************" << endl;
	cout << "Enter the name of the file without extension: ";
	cin >> fileName;
	birdHouse bHouse(fileName);
	
	bHouse.setRandomWord();

	cout << "\nThis is a "<< bHouse.getWordLength() <<" letter word." << endl;
	cout << "Current guessed word is :\n" << endl;
	
	for (unsigned short int i = 0; i < bHouse.getWordLength(); i++)
	{
		bHouse.userGuess += "-";
	}
	cout << bHouse.userGuess << endl;
	
	// asking player for guesses
	while (bHouse.getNumGuess() < 8)
	{
		cout << "\nPlease enter a character" << endl;
		cout << "(If you know the word, enter 1):" << endl;
		char userInput;
		cin >> userInput;
		bHouse.setUInput(userInput);
		if (bHouse.getUInput() == '1')
		{
			string wordGuess;
			cout << "Please guess the word:" << endl;
			cin >> wordGuess;
			// check if guessed word is equal to random word
			if (wordGuess == bHouse.getRandomWord())
			{
				bHouse.WinGame();
				cin >> userInput;
				break;
			}
			else {
				break;
			}
		}
		// check if guessed character is in the random word
		else if (bHouse.getRandomWord().find(userInput) < bHouse.getRandomWord().length())
		{
			for (size_t i = 0; i < bHouse.getRandomWord().length(); i++)
			{
				if (bHouse.getRandomWord()[i] == bHouse.getUInput())
				{
					bHouse.userGuess[i] = bHouse.getUInput();
				}
			}
			cout << "Current guessed word is : " << bHouse.userGuess << endl;
			if (bHouse.getRandomWord() == bHouse.userGuess)
			{
				bHouse.WinGame();
				cin >> userInput;
				break;
			}
		}
		// runs if player guess is wrong
		else {
			bHouse.setNumGuess();
			// print bird house drawing
			bHouse.PrintBirdHouse();
		}
		
	}
}
