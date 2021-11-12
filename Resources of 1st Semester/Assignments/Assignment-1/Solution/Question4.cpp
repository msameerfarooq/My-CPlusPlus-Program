#include <iostream>
using namespace std;

int main()
{
	cout << "   This program is used to check whether the given number is prime or not." << "\n\n";
	cout << "A prime number is a natural number, greater than 1 and that cannot be formed by multiplying two smaller natural numbers. Its positive divisors are 1 and itself." << "\n\n\n";

	int a, b, c, d, e, f, g, h, i, j, k, x;

	cout << "Enter the positive integer between 1 and 1000(inclusive) : ";
	cin >> x;
	cout << "\n\n";

	if ((x >= 1) && (x <= 1000))
	{
		if (x == 1)
		{
			cout << "1 is not a prime number." << "\n\n";
			cout << "Because it doesn't have exactly two positive divisors.";
		}
		else if (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19 || x == 23 || x == 29 || x == 31)
		{
			cout << "Given number is a Prime Number.";
		}
		else
		{
			a = x % 2;
			b = x % 3;
			c = x % 5;
			d = x % 7;
			e = x % 11;
			f = x % 13;
			g = x % 17;
			h = x % 19;
			i = x % 23;
			j = x % 29;
			k = x % 31;

			if ((a != 0) && (b != 0) && (c != 0) && (d != 0) && (e != 0) && (f != 0) && (g != 0) && (h != 0) && (i != 0) && (j != 0) && (k != 0))
			{
				cout << "Given number is a Prime Number.";
			}
			else
			{
				cout << "Given number is not a Prime Number." << "\n\n";
				cout << "Given number is divisible by ";

				if (a == 0)
					cout << " 2";
				if (b == 0)
					cout << " 3";
				if (c == 0)
					cout << " 5";
				if (d == 0)
					cout << " 7";
				if (e == 0)
					cout << " 11";
				if (f == 0)
					cout << " 13";
				if (g == 0)
					cout << " 17";
				if (h == 0)
					cout << " 19";
				if (i == 0)
					cout << " 23";
				if (j == 0)
					cout << " 29";
				if (k == 0)
					cout << " 31";
				cout << ".";
			}
		}
	}
	else
	{
		cout << "Invalid Input.";
	}

	cout << "\n\n\n\n" << "				...THANK YOU..." << "\n\n\n";
	cout << "To exit this console application, ";
	system("pause");
	return 0;
}