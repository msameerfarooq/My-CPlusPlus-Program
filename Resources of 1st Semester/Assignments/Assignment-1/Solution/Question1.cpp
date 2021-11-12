#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "\t" << "This program is used to tells aboout the cost of paint on cone." << "\n\n";
	float radius, area, height = 30.0, pi = 3.141592653589793, diameter = 8.0, greencosts, orangecosts, bluecosts;
	height = height / 12.0;
	diameter = diameter / 12.0;
	radius = diameter / 2.0;

	area = pi*radius*(sqrt((radius*radius) + (height*height)));
	greencosts = 20.75*area;
	orangecosts = 30.5*area;
	bluecosts = 15.25*area;
	cout << "\n\n" << "Area of cone(except base) is " << area << " square feet." << "\n";
	cout << "\n" << "Cost of green painting is " << greencosts << " rupees." << "\n";
	cout << "\n" << "Cost of orange painting is " << orangecosts << " rupees." << "\n";
	cout << "\n<" << "Cost of blue painting is " << bluecosts << " rupees." << "\n";

	cout << "\n\n\n\n\t\t\t..."<<"THANK YOU...\n\n\n" << "To exit this console application, ";
	system("pause");
	return 0;
}