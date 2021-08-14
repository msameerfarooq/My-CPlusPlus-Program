#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

const double pi = 3.1415926535897932384626433832795;

double Reciprocal()
{
	double num;
	cout << "Enter the  number : ";
	cin >> num;
	cout << "Reciprocal of " << num << " is : " << 1 / num;
	return 0;
}

void simplestFractionForm(long long num, long long denom)
{
	int counter = 1, counter1 = 1;
	long long x, y;
	bool flag = false;
	if ((num / denom) < 0)
		flag = true;
	abs(num);
	abs(denom);
	y = denom;
	x = num;
	while (counter1 <= 10)
	{
		counter = 1;
		while ((counter <= x) && (counter <= y))
		{
			if ((x % counter == 0) && (y % counter == 0))
			{
				x /= counter;
				y /= counter;
			}
			counter++;
		}
		counter1++;
	}
	if (flag == true)
		x *= -1;
	cout << "\nThe given value(s) in simplest form would be  " << x << " / " << y;

	num = x;
	denom = y;
}

void DecimalToFraction()
{
	int counter = 1, counter1 = 1;
	long long num, denom, x, y;
	double n;
	bool flag = false;
	cout << "Enter a floating number : ";
	cin >> n;
	if (n < 0)
		flag = true;
	n = abs(n);
	y = 100000;
	x = static_cast<long long>(n*100000.0);
	while (counter1 <= 10)
	{
		counter = 1;
		while ((counter <= x) && (counter <= y))
		{
			if ((x % counter == 0) && (y % counter == 0))
			{
				x /= counter;
				y /= counter;
			}
			counter++;
		}
		counter1++;
	}
	if (flag == true)
	{
		x *= -1;
		n *= -1;
	}
	cout << "\nThe fractional form of " << n << " would be  " << x << " / " << y;

	num = x;
	denom = y;
}

long long Remainder(long long num1, long long num2)
{
	long long remainder = 1;
	remainder = num1 % num2;
	return remainder;
}

double division(double num1, double num2)
{
	int sentinal = 0;
	double division = 1.0, d = 1;
	bool flag = false;
	while (sentinal == 0)
	{
		if (!(num2 == 0))
		{
			division = num1*1.0 / num2;
			cout << "Division of " << num1 << " and " << num2 << " is : " << division;
			simplestFractionForm(static_cast<long long>(num1 * 10000), static_cast<long long>(num2 * 10000));
			d = division;
			if (d < 0)
			{
				d *= -1;
			}
			cout << "\n\nQuotient  of " << num1 << " and " << num2 << " is : " << static_cast<int>(d);
			cout << "\nRemainder of " << num1 << " and " << num2 << " is : " << abs(Remainder(static_cast<long long>(num1 * 100000), static_cast<long long>(num2 * 100000)) / 100000) << endl;
			sentinal = 1;

		}
		else
		{
			cout << "Please enter the correct input!\n\n";
			cout << "Enter the second number : ";
			cin >> num2;
			continue;
		}
	}
	return division;
}

double AirthmeticCalculations()
{
	int sentinal = 0;
	double num1 = 0, num2 = 0;
	char operation;
	while (sentinal != -1)
	{
		cout << "Enter the first number : ";
		cin >> num1;
		
		if (((num1 >= 0) || (num1 < 0)) && (num1) && cin)
		{
			while (sentinal != -1)
			{
				cout << "\nEnter the operation <'+','-','*','/'> OR Enter 0 to end this calculations  : ";
				cin >> operation;
				if (operation == '0')
				{
					sentinal = -1;
					break;
				}
				cout << "\nEnter the second number : ";
				cin >> num2;
				if (cin)
				{
					cout << endl << endl;
					if (operation == '+')
					{
						cout << "Addition of " << num1 << " and " << num2 << " is : ";
						num1 = num1 + num2;
						cout << num1 << endl;
					}
					else if (operation == '-')
					{
						cout << "Subtraction of " << num1 << " and " << num2 << " is : ";
						num1 = num1 - num2;
						cout << num1 << endl;
					}
					else if (operation == '*')
					{
						cout << "Multiplication of " << num1 << " and " << num2 << " is : ";
						num1 = num1*num2;
						cout << num1 << endl;
					}
					else if (operation == '/')
					{
						num1 = division(num1, num2);
					}

					system("pause");
					if (sentinal == 0)
					{
						system("cls");
						cout << "\nFirst number is : " << num1;
					}
				}
				else
				{
					cout << "\nEnter the correct input!\n";
					system("pause");
					continue;
				}


			}
		}
		else
		{
			cout << "\nEnter the correct input!\n";
			system("pause");
			continue;
		}
	}
	return 0;
}

double trigonometricValues(double rad)
{
	double x, y, z;
	x = sin(rad);
	y = cos(rad);
	z = tan(rad);
	cout << fixed << setprecision(5);
	cout << "\n\nSine value of given angle is : " << x;
	cout << "\nCosine value of given angle is : " << y;
	cout << "\nTangent value of given angle is : " << z;
	cout << "\nCosecant value of given angle is : " << 1 / x;
	cout << "\nSecant value of given angle is : " << 1 / y;
	cout << "\nCotangent value of given angle is : " << 1 / z;
	return 0;
}

double inverseTrigonometricValues(double deg)
{
	double x, y, z;
	x = (asin(deg)) * 180 / pi;
	y = (acos(deg)) * 180 / pi;
	z = (atan(deg)) * 180 / pi;
	cout << fixed << setprecision(5);
	cout << "\n\nInverse Sine of given angle is : " << x;
	cout << "\nInverse Cosine of given angle is : " << y;
	cout << "\nInverse Tangent of given angle is : " << z;
	cout << "\nInverse Cosecant value of given angle is : " << 1 / x;
	cout << "\nInverse Secant value of given angle is : " << 1 / y;
	cout << "\nInverse Cotangent value of given angle is : " << 1 / z;
	return deg;
}

double hyperbolicValues(double deg)
{
	double x, y, z;
	x = sinh(deg);
	y = cosh(deg);
	z = tanh(deg);
	cout << fixed << setprecision(5);
	cout << "\n\nHyperbolic Sine value of given angle is : " << x;
	cout << "\nHyperbolic Cosine value of given angle is : " << y;
	cout << "\nHyperbolic Tangent value of given angle is : " << z;
	cout << "\nHyperbolic Cosecant value of given angle is : " << 1 / x;
	cout << "\nHyperbolic Secant value of given angle is : " << 1 / y;
	cout << "\nHyperbolic Cotangent value of given angle is : " << 1 / z;
	return deg;
}

double inverseHyperbolicValues(double deg)
{
	double x, y, z;
	x = asinh(deg);
	y = acosh(deg);
	z = atanh(deg);
	cout << fixed << setprecision(5);
	cout << "\n\nInverse Hyperbolic Sine of given angle is : " << x;
	cout << "\nInverse hyperbolic Cosine of given angle is : " << y;
	cout << "\nInverse hyperbolic Tangent of given angle is : " << z;
	cout << "\nInverse hyperbolic Cosecant value of given angle is : " << 1 / x;
	cout << "\nInverse hyperbolic Secant value of given angle is : " << 1 / y;
	cout << "\nInverse hyperbolic Cotangent value of given angle is : " << 1 / z;
	return deg;
}

double simultaneousEquations()
{
	double x1, x2, y1, y2, c1, c2, x, y;

	cout << "Enter the coefficient of x for first equation : ";
	cin >> x1;
	cout << "Enter the coefficient of y for first equation : ";
	cin >> y1;
	cout << "Enter the constant term for first equation : ";
	cin >> c1;
	cout << "Enter the coefficient of x for second equation : ";
	cin >> x2;
	cout << "Enter the coefficient of y for second equation : ";
	cin >> y2;
	cout << "Enter the constant term for second equation : ";
	cin >> c2;
	if ((x1 != x2) && (y1 != y2))
	{
		x = (((y1 * c2) - (y2 * c1)) / ((y1 * x2) - (x1 * y2)));
		y = (((x2 * c1) - (x1 * c2)) / ((y1 * x2) - (x1 * y2)));

		cout << "\nThe value of x is : " << x;
		cout << "\nThe value of y is : " << y;
	}
	else
		cout << "\n\nInvalid Input.";
	return x;
	return y;
}

double quadraticEquations()
{
	double a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
	cout << "Enter coefficient of a : ";
	cin >> a;
	cout << "Enter coefficient of b : ";
	cin >> b;
	cout << "Enter coefficient of c : ";
	cin >> c;
	discriminant = b*b - 4 * a*c;

	if (discriminant > 0)
	{
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "Roots are real and different." << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else if (discriminant == 0)
	{
		cout << "Roots are real and same." << endl;
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		cout << "x1 = x2 =" << x1 << endl;
	}
	else
	{
		realPart = -b / (2 * a);
		imaginaryPart = sqrt(-discriminant) / (2 * a);
		cout << "Roots are complex and different." << endl;
		cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
		cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
	}
	return 0;
}

double polynomialEquations()
{
	double x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, z1 = 0, z2 = 0, z3 = 0, c1 = 0, c2 = 0, c3 = 0, x = 0, y = 0, z = 0, aa, bb, cc, dd, ee, ff;
	double x4 = 0, y4 = 0, z4 = 0, w1 = 0, w2 = 0, w3 = 0, w4 = 0, c4 = 0;
	cout << "Enter the coefficient of w for first equation : ";
	cin >> w1;
	cout << "Enter the coefficient of x for first equation : ";
	cin >> x1;
	cout << "Enter the coefficient of y for first equation : ";
	cin >> y1;
	cout << "Enter the coefficient of z for first equation : ";
	cin >> z1;
	cout << "Enter the constant term for first equation : ";
	cin >> c1;
	cout << "Enter the coefficient of w for second equation : ";
	cin >> w2;
	cout << "Enter the coefficient of x for second equation : ";
	cin >> x2;
	cout << "Enter the coefficient of y for second equation : ";
	cin >> y2;
	cout << "Enter the coefficient of z for second equation : ";
	cin >> z2;
	cout << "Enter the constant term for second equation : ";
	cin >> c2;
	cout << "Enter the coefficient of w for third equation : ";
	cin >> w3;
	cout << "Enter the coefficient of x for third equation : ";
	cin >> x3;
	cout << "Enter the coefficient of y for third equation : ";
	cin >> y3;
	cout << "Enter the coefficient of z for third equation : ";
	cin >> z3;
	cout << "Enter the constant term for third equation : ";
	cin >> c3;
	cout << "Enter the coefficient of w for fourth equation : ";
	cin >> w4;
	cout << "Enter the coefficient of x for fourth equation : ";
	cin >> x4;
	cout << "Enter the coefficient of y for fourth equation : ";
	cin >> y4;
	cout << "Enter the coefficient of z for fourth equation : ";
	cin >> z4;
	cout << "Enter the constant term for fourth equation : ";
	cin >> c4;


	aa = (x3*w4 - w3*x4)*(y1*x2 - x1*y2) + (x1*w2 - w1*x2)*(x3*y4 - y3*x4);
	bb = (z1*x2 - x1*z2)*(x3*w4 - w3*x4) + (x1*w2 - w1*x2)*(x3*z4 - w3*x4);
	cc = (x3*w4 - w3*x4)*(c1*x2 - x1*c2) + (x1*w2 - w1*x2)*(c3*x4 - x3*c4);
	dd = (x1*w4 - w1*x4)*(y2*x3 - x2*y3) + (x2*w3 - w2*x3)*(x1*y4 - y1*x4);
	ee = (z2*x3 - x2*z3)*(x1*w4 - w1*x4) + (x2*w3 - w2*x3)*(x1*z4 - z1*x4);
	ff = (x1*w4 - w1*x4)*(c2*x3 - x2*c3) + (x2*w3 - w2*x3)*(x1*c4 - c1*x4);



	y = (cc*ee - bb*ff) / (aa*ee - bb*dd);
	z = (cc*dd - aa*ff) / (bb*dd - aa*ee);

	cout << y << endl << z;


	return y;
	return z;
}

long long factorial()
{
	int num;
	long long fact = 1;
	cout << "Enter the positive number upto 20 : ";
	cin >> num;
	if ((cin) && (num <= 20))
	{
		while (num > 1)
		{
			fact *= num;
			num--;
		}
		cout << "Factorial of given number is " << fact << endl;
	}
	else
		cout << "Invalid Input.";
	return fact;
}

double power()
{
	double num, degree, power = 0;

	cout << "Enter the number : ";
	cin >> num;
	if (cin)
	{
		cout << "Enter the power : ";
		cin >> power;
		if (cin)
		{
			degree = pow(num, power);
			cout << "Power of given number is : " << degree << endl;
		}
		else
			cout << "Invalid Input.";
	}
	else
		cout << "Invalid Input.";

	return power;
}

long long binToDec(long long bin)
{
	long long  temp = 0, i = 0, dec = 0;
	temp = bin;
	while (temp > 0)
	{
		dec = static_cast<long long>(dec + (temp % 10) * pow(2, i));
		i++;
		temp /= 10;
	}

	cout << "\nThe decimal equivalent of " << bin << " is " << dec;
	return dec;
}

long long binToOct(long long bin)
{
	long long temp = 0, i = 0, dec = 0, oct = 0;

	temp = bin;
	while (temp > 0)
	{
		dec = static_cast<long long>(dec + (temp % 10) * pow(2, i));
		i++;
		temp /= 10;
	}
	temp = dec;
	i = 0;
	while (temp > 0)
	{
		oct = static_cast<long long>(oct + (temp % 8) * pow(10, i));
		i++;
		temp /= 8;
	}
	cout << "\nThe octal equivalent of " << bin << " is " << oct;
	return oct;
}

long long decToBin(long long dec)
{
	long long temp = 0, i = 0, bin = 0;

	temp = dec;
	while (temp > 0)
	{
		bin = static_cast<long long>(bin + temp % 2 * pow(10, i));
		i++;
		temp /= 2;
	}
	cout << "\nThe binary equivalent of " << dec << " is " << bin;

	return bin;
}

long long decToOct(long long dec)
{
	long long temp = 0, i = 0, oct = 0;
	temp = dec;
	while (temp > 0)
	{
		oct = static_cast<long long>(oct + (temp % 8) * pow(10, i));
		i++;
		temp /= 8;
	}
	cout << "\nThe octal equivalent of " << dec << " is " << oct;
	return oct;
}

long long octToBin(long long oct)
{
	long long temp = 0, dec = 0, i = 0, bin = 0;
	temp = oct;
	while (temp > 0)
	{
		dec = static_cast<long long>(dec + (temp % 10) * pow(8, i));
		i++;
		temp /= 10;
	}
	temp = dec;
	i = 0;
	while (temp > 0)
	{
		bin = static_cast<long long>(bin + temp % 2 * pow(10, i));
		i++;
		temp /= 2;
	}
	cout << "\nThe binary equivalent of " << oct << " is " << bin;

	return bin;
}

long long octToDec(long long oct)
{
	long long temp = 0, dec = 0, i = 0;
	temp = oct;
	while (temp > 0)
	{
		dec = static_cast<long long>(dec + (temp % 10) * pow(8, i));
		i++;
		temp /= 10;
	}
	cout << "\nThe decimal equivalent of " << oct << " is " << dec;
	return dec;
}

void Natural_Logarithm()
{
	cout << "Enter a Number : ";
	int num;
	cin >> num;
	cout << log(num);
}

void Common_Logarithm()
{
	int num;
	cout << "Enter a Number : ";
	cin >> num;
	cout << log(num);
}

void main()
{

	int num = 0, sentinal = 0, choice = 0, counter = 0;
	float rad = 0;
	while (sentinal != -1)
	{
		system("cls");
		cout << "\tWelcome to the calculater program v.1.0 written by M Sameer Farooq." << endl;
		cout << "********************************************************************************" << endl;
		cout << endl << endl << endl;
		cout << "\t\tWhat do you want to choose\n1-->To calculate the power of a number\n2-->To calculate the factorial of number\n3-->For Airthmetic Calculations\n4-->Number System Converter\n5-->Trigonometric Values\n6-->For Algebraic Equations\n7-->To convert decimal number into fraction form\n\nEnter your choice : ";
		cin >> choice;
		system("cls");

		if (choice == 1)
			power();
		else if (choice == 2)
			factorial();
		else if (choice == 3)
		{
			AirthmeticCalculations();
		}
		else if (choice == 4)
		{
			int choice1;
			cout << "\n1-->To convert Binary Number into other Number Systems\n2-->To convert Decimal Number into other Number Systems\n3-->To convert Octal Number into other Number Systems\n\n\tEnter your choice : ";
			cin >> choice1;
			if (choice1 == 1)
			{
				long long bin;
				cout << "Enter the Binary Number : ";
				cin >> bin;
				binToDec(bin);
				binToOct(bin);
			}
			else if (choice1 == 2)
			{
				long long dec;
				cout << "Enter the Decimal Number : ";
				cin >> dec;
				decToBin(dec);
				decToOct(dec);
			}
			else if (choice1 == 3)
			{
				long long oct;
				cout << "Enter the Octal Number : ";
				cin >> oct;
				octToBin(oct);
				octToDec(oct);
			}
		}
		else if (choice == 5)
		{
			double deg, rad, choice1;
			char unit;
			cout << "Press,\n\t1 for Trigonometric Values\n\t2 for Inverse Trigonometric Values\n\t3 for Hyperbolic Values\n\t4 for Inverse Hyperbolic Values\n\t5 to perform all at a time\n\n\t\tEnter your choice : ";
			cin >> choice1;
			cout << "Enter the unit of angle : ";
			cin >> unit;
			cout << fixed << setprecision(16);
			if (unit == 'd')
			{
				cout << "Enter the angle in degree : ";
				cin >> deg;
				rad = (deg*pi) / 180.0;
			}
			else if (unit == 'r')
			{
				cout << "Enter the angle in radian : ";
				cin >> rad;
				deg = rad * 180.0 / pi;
			}
			if (choice1 == 1)
			{
				trigonometricValues(rad);
			}
			else if (choice1 == 2)
			{
				inverseTrigonometricValues(deg);
			}
			else if (choice1 == 3)
			{
				hyperbolicValues(deg);
			}
			else if (choice1 == 4)
			{
				inverseHyperbolicValues(deg);
			}
			else if (choice1 == 5)
			{
				trigonometricValues(rad);
				inverseTrigonometricValues(deg);
				hyperbolicValues(deg);
				inverseHyperbolicValues(deg);
			}
		}
		else if (choice == 6)
		{
			int choice1;
			cout << "1-->Simultaneous Equations\n2-->Quadratic Equations\n\n\t\tEnter your Choice : ";
			cin >> choice1;

			if (choice1 == 1)
			{
				simultaneousEquations();
			}
			else if (choice1 == 2)
			{
				quadraticEquations();
			}
			else if (choice1 == 3)
			{
				polynomialEquations();
			}
		}
		else if (choice == 7)
		{
			DecimalToFraction();
		}
		cout << endl;
		while (true)
		{
			cout << "\n\nEnter 4 to home screen of calculator : ";
			cin >> sentinal;

			if (sentinal == 4 || sentinal == -1)
				break;
			else
			{
				cout << "Enter the correct input.";
				continue;
			}
		}
	}
	cout << "\n\n";
	system("pause");
}