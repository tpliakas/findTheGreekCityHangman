#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAX_TRIES=5;

int fillCity (char, string, string&);

int main ()
{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string city;
	string words[] =
	{
		"larisa",
		"volos",
		"athens",
		"thessaloniki",
		"patra",
		"xania",
		"irakleio",
		"serres",
		"ksanthi",
		"ioannina"
	};

	srand(time(NULL));
	int n=rand()% 10;
	city=words[n];

	string unknown(city.length(),'*');

	cout << "\n\nFind the Greek city - Hangman!";
	cout << "\n\nEach letter is a star (*).";
	cout << "\n\nOn each try, you type only one letter!";
	cout << "\n\nYou have " << MAX_TRIES << " tries to find the city!";
	cout << "\n--------------------------------------------";

	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\nCity: " << unknown;
		cout << "\n\nPick a letter: ";
		cin >> letter;
		if (fillCity(letter, city, unknown)==0)
		{
			cout << endl << "\nNope! This letter is NOT in city's name!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "\nYes! This letter is in city's name!" << endl;
		}
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		if (city==unknown)
		{
			cout << city << endl;
			cout << "\nYeah! You got it!!!";
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you've been HANGED!" << endl;
		cout << "The city was : " << city << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}

int fillCity (char guess, string secretcity, string &guesscity)
{
	int i;
	int matches=0;
	int len=secretcity.length();
	for (i = 0; i< len; i++)
	{
		if (guess == guesscity[i])
			return 0;

		if (guess == secretcity[i])
		{
			guesscity[i] = guess;
			matches++;
		}
	}
	return matches;
}
