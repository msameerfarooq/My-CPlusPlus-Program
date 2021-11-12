#include <iostream>
using namespace std;

int main()
{
	cout << "This program is used to check whether the entered number is duplicate or not." << "\n\n";
	int a, b, c, d, e;
	cout << "Enter 1st number : ";
	cin >> a;
	if (a >= 0)
	{
		cout << "Enter 2nd number : ";
		cin >> b;
		if ((b > 0) || (b == 0) || (b < 0))
		{
			cout << "Enter 3rd number : ";
			cin >> c;
			if ((c > 0) || (c == 0) || (c < 0))
			{
				cout << "Enter 4th number : ";
				cin >> d;
				if ((d > 0) || (d == 0) || (d < 0))
				{
					cout << "Enter 5th number : ";
					cin >> e;
					if ((e > 0) || (e == 0) || (e < 0))
					{

						if (a == b || a == c || a == d || a == e || b == c || b == d || b == e || c == d || c == e || d == e)
							cout << "\n\n\n\t\t\t" << "DUPLICATE EXISTS.";
						else
							cout << "\n\n\n\t\t\t" << "DUPLICATE DOES NOT EXISTS.";

					}
					else
						cout << "\n\n" << "Invalid input.";
				}
				else
					cout << "\n\n" << "Invalid input.";
			}
			else
				cout << "\n\n" << "Invalid input.";
		}
		else
			cout << "\n\n" << "Invalid input.";
	}
	else
		cout << "\n\n" << "Invalid Input.";


	cout << "\n\n\n\n\t\t\t..." << "THANK YOU..." << "\n\n\n";
	cout << "To exit this console application, ";
	system("pause");
	return 0;
}