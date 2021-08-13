#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	cout << "   This program is used to convert the temperature from one scale to another.\n\n\n";
	double cel, far, kel;
	char inscale, outscale;

	while (a == 0)
	{
		cout << "Enter the input scale in which you want to enter the temperature (c/f/k) : ";
		cin >> inscale;

		inscale = tolower(inscale);

		if (inscale == 'c' || inscale == 'f' || inscale == 'k')
		{
			if (inscale == 'c')
			{
				cout << "Enter the temperature in Celsius : ";
				cin >> cel;
				if (cel)
				{
					far = (cel * 9 / 5.0) + 32;
					kel = cel + 273.15;
					cout << "\n" << "Temperature in Fahrenheit is : " << far;
					cout << "\n" << "Temperature in Kelvin is : " << kel << endl << endl;
				}
				else
					break;
			}
			else if (inscale == 'f')
			{
				cout << "Enter the temperature in Fahrenheit : ";
				cin >> far;
				if (far)
				{
					cel = (far - 32) * 5 / 9;
					kel = ((far - 32) * 5 / 9) + 273.15;
					cout << "\n" << "Temperature in Kelvin is :" << kel;
					cout << "\n" << "Temperature in Celsius is : " << cel << endl << endl;
				}
				else
					break;
			}
			else if (inscale == 'k')
			{
				cout << "Enter the temperature in Kelvin : ";
				cin >> kel;
				if (kel)
				{
					cel = kel - 273.15;
					far = ((kel - 273.15) * 9 / 5.0) + 32;
					cout << "\n" << "Temperature in Fahrenheit is : " << far;
					cout << "\n" << "Temperature in Celsius is : " << cel << endl << endl;
				}
				else
					break;
			}
			a = 1;
		}
		else
		{
			cout << "Please enter a correct input scale!!!\n\n";
			continue;
		}
	}
	system("pause");
	return 0;
}
