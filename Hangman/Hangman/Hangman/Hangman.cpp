#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

// Simple Hangman Game created by Ethan Despres
// Scene 1: (menu)
//		Asks the user to pick between a couple of different options for the type of word used
//		Countries, Cities, Sports, Custom
// Scene 2: (Guessing Screen)
//		Displays the ASCII Hangman image with the number of limbs == the number of incorrect guesses from the player.
//		Displays the blank word with the letters that have been guessed correctly filled in.
//		Prompts the user for another letter.
// Scene 3: (Custom Word)
//		Asks the user for a word before going to scene 2.
//
//

const int MAX_TRIES = 10;
int menu();
int addLetter(char, string, string&);
void printHangman(int);

int main()
{
	string countries[]
	{
		"america",
		"india",
		"canada",
		"germany",
		"japan",
		"china",
		"russia",
		"taiwan",
		"egypt",
		"spain",
		"france",
		"ireland",
		"mexico"
	};

	string usCities[]
	{
		"baltimore",
		"dallas",
		"austin",
		"boston",
		"chicago",
		"detroit",
	};

	string sports[]
	{
		"football",
		"soccer",
		"baseball",
		"basketball",
		"boxing",
		"cycling",
		"golf",
		"hockey",
		"karate",
		"swimming"
	};

	srand(time(NULL));
	string word; int n;

	int menuChoice = menu();
	switch (menuChoice)
	{
	case 1:
		n = rand() % countries->length();
		word = countries[n];
		break;
	case 2:
		n = rand() % usCities->length();
		word = usCities[n];
		break;
	case 3:
		n = rand() % sports->length();
		word = sports[n];
		break;
	case 4:
		cout << "Enter a word: \n";
		cin >> word;
		break;
	case 5:
		return 0;
		break;

	default:
		break;
	}

	string blankWord(word.length(), '*');

	int num_tries = 0;
	while (num_tries < MAX_TRIES)
	{
		printHangman(num_tries);
		cout << "\n\n" << blankWord;
		cout << "\n\nGuess a letter: ";

		char letter;
		cin >> letter;

		int numMatches = addLetter(letter, word, blankWord);

		if (numMatches == 0)
		{
			cout << "\nThat Letter is not in the word\n";
			num_tries++;
		}
		else
		{
			cout << "\nThat letter was in the word " << numMatches << " times.\n";
		}

		cout << "Number of attempts left: " << MAX_TRIES - num_tries << endl;

		if (word == blankWord)
		{
			cout << word << endl;
			cout << "You have found the word\n";
			break;
		}
	}
	if (num_tries == MAX_TRIES)
	{
		cout << "\n";
		cout << "_____\n";
		cout << "|   |\n";
		cout << "|   O\n";
		cout << "|  -|-\n";
		cout << "|  / \\\n";
		cout << "|\n";
		cout << "|______\n";

		cout << "\nGame Over." << endl;
		cout << "The word was : " << word << endl;
	}
	cout << "Press Enter to continue\n";
	cin.ignore();
	cin.get();
	main();
	return 0;
}

int menu() {

	cout << "Welcome to Hangman, created by Ethan Despres\n";
	cout << "You have " << MAX_TRIES << " tries to guess the word\n\n";
	cout << "What Gamemode do you wish to play ? \n";
	cout << "1) Countries\n";
	cout << "2) Cities\n";
	cout << "3) Sports\n";
	cout << "4) Custom\n";
	cout << "5) exit\n";

	int usrChoice;
	cin >> usrChoice;
	return usrChoice;
}

int addLetter(char letter, string word, string &wordBlank)
{
	int i;
	int matches = 0;
	int len = word.length();
	for (i = 0; i < len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (letter == wordBlank[i])
			return 0;
		// Is the guess in the secret word?
		if (letter == word[i])
		{
			wordBlank[i] = letter;
			matches++;
		}
	}
	return matches;
}

void printHangman(int numTries) 
{
	switch (numTries)
	{
	case 0:
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "______\n";

		break;
	case 1:
		cout << "\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|______\n";
		break;
	case 2:
		cout << "\n";
		cout << "_____\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|______\n";
		break;
	case 3:
		cout << "\n";
		cout << "_____\n";
		cout << "|   |\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|______\n";
		break;
	case 4:
		cout << "\n";
		cout << "_____\n";
		cout << "|   |\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|______\n";
		break;
	case 5:
		cout << "\n";
		cout << "_____\n";
		cout << "|   |\n";
		cout << "|   O\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|______\n";
		break;
	case 6:
		cout << "\n";
		cout << "_____\n";
		cout << "|   |\n";
		cout << "|   O\n";
		cout << "|   |\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|______\n";
		break;
	case 7:
		cout << "\n";
		cout << "_____\n";
		cout << "|   |\n";
		cout << "|   O\n";
		cout << "|  -|\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|______\n";
		break;
	case 8:
		cout << "\n";
		cout << "_____\n";
		cout << "|   |\n";
		cout << "|   O\n";
		cout << "|  -|-\n";
		cout << "|\n";
		cout << "|\n";
		cout << "|______\n";
		break;
	case 9:
		cout << "\n";
		cout << "_____\n";
		cout << "|   |\n";
		cout << "|   O\n";
		cout << "|  -|-\n";
		cout << "|  / \n";
		cout << "|\n";
		cout << "|______\n";
		break;

	default:
		break;
	}
}