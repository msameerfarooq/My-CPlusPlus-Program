#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0)); // seed the random number generator
	int number;
	number = static_cast<int>(rand() % 100 + 1);
	int tries = 0, guess;

	cout << "\tWelcome to Guess My Number!\n";
	cout << "You have 6 tries to find the integer number in between 1 and 100\n\n";
	do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;
		if (guess > number)
			cout << "Too high!\n\n";
		else if (guess < number)
			cout << "Too low!\n\n";

	} while ((guess != number) && (tries < 7));

	if (tries < 7)
	{
		cout << "\nThat's it!\nYou Won! You got it in " << tries << " guesses!\n";
	}
	else
		cout << "You Lose!\nThe number is " << number << endl;

	cout << "\nPress Enter to exit.\n";
	cin.ignore(cin.rdbuf()->in_avail() + 1);
	return 0;
}