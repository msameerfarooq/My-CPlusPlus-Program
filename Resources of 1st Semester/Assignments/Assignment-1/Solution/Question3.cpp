#include <iostream>
using namespace std;

int main()
{
	cout << "\t" << "This program is the game of Rock, paper, scissors." << "\n\n";
	char choice1, choice2;
	cout << "R = Rock" << "\n" << "P = Paper" << "\n" << "S = Scissor" << "\n\n";
	cout << "Enter the choice of Player 1 (R/P/S) : ";
	cin >> choice1;

	choice1 = toupper(choice1);

	if ((choice1 == 'R') || (choice1 == 'P') || (choice1 == 'S'))
	{
		cout << "Enter the choice of Player 2 (R/P/S) : ";
		cin >> choice2;

		choice2=toupper(choice2);

			if ((choice2 == 'R') || (choice2 == 'P') || (choice2 == 'S'))
			{
				cout << "\n\n\n\n\t\t\t\t ";
				if ((choice1 == 'P') && (choice2 == 'R'))
					cout << "PLAYER 1 WINS.";
				else if ((choice1 == 'P') && (choice2 == 'S'))
					cout << "PLAYER 2 WINS.";
				else if ((choice1 == 'R') && (choice2 == 'P'))
					cout << "PLAYER 2 WINS.";
				else if ((choice1 == 'R') && (choice2 == 'S'))
					cout << "PLAYER 1 WINS.";
				else if ((choice1 == 'S') && (choice2 == 'R'))
					cout << "PLAYER 2 WINS.";
				else if ((choice1 == 'S') && (choice2 == 'P'))
					cout << "PLAYER 1 WINS.";
				else
					cout << "GAME DRAW.";
			}
			else
				cout << "\n\n\n\n\t\t\t" << "Invalid Input from Player 2 .";
	}
	else
		cout << "\n\n\n\n\t\t\t" << "Invalid Input from Player 1.";

	cout << "\n\n" << "\n\n\n\t\t\t" << "...THANK YOU..." << "\n\n\n";
	cout << "To exit this console application, ";
	system("pause");
	return 0;

}