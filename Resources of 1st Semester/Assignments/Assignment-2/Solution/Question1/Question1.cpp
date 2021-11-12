#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double square_root(int n)
{
	int count = 0;
	double squareroot = 1;
	while (count < 10)
	{
		squareroot = (squareroot + n / squareroot) / 2;
		count++;
	}
	return squareroot;
}

void compare_Sqrt()
{
	int num;
	double sqrt1 = 0, sqrt2 = 0, difference = 0;

	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	fout << "num\tsqrt by method\t\tsqrt by function\tdifference\n\n";
	cout << "num\tsqrt by method\t\tsqrt by function\tdifference\n\n";

	while (!(fin.eof()))
	{
		fout << fixed << setprecision(15);
		cout << fixed << setprecision(15);
		fin >> num;
		sqrt1 = square_root(num);
		sqrt2 = sqrt(num);
		difference = sqrt2 - sqrt1;
		fout << num << "\t" << sqrt1 << "\t" << sqrt2 << "\t" << difference << endl;
		cout << num << "\t" << sqrt1 << "\t" << sqrt2 << "\t" << difference << endl;
	}
	fout.close();
	fin.close();
}

int main()
{
	compare_Sqrt();
	cout << endl << endl;
	system("pause");
	return 0;
}