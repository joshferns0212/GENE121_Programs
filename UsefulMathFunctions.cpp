// Joshua Fernandes

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
	double x = 0, y = 0, TOL = 0, b = 0, angle = 0, side1 = 0, side2 = 0;

	cout << "Enter x: ";
	cin >> x;
	cout << "\nEnter y: ";
	cin >> y;
	cout << "\nEnter TOL: ";
	cin >> TOL;
	cout << "\n" << withinTolerance(x,y,TOL);

	cout << "\nEnter x: ";
	cin >> x;

	while (x <= 0)
	{
		cout << "\nRe-enter x: ";
		cin >> x;
	}

	cout << "\nEnter b: ";
	cin >> b;

	while (b < 0)
	{
		cout << "\nRe-enter b: ";
		cin >> b;
	}

	cout << "\n" << log (x,b);

	cout << "\nEnter angle: ";
	cin >> angle;
	cout << "\n" << degreesToRadians(angle);

	cout << "\nEnter angle: ";
	cin >> angle;

	while (angle >=180 )
	{
		cout << "\nRe-enter angle: ";
		cin >> angle;
	}
	cout << "\nEnter side1: ";
	cin >> side1;

	while (side1 <= 0)
	{
		cout << "\nRe-enter side1: ";
		cin >> side1;
	}

	cout << "\nEnter side2: ";
	cin >> side2;

	while (side2 <= 0)
	{
		cout << "\nRe-enter side2: ";
		cin >> side2;
	}

	cout << "\n" << cosineLaw (angle, side1, side2);
}

bool withinTolerance (double x, double y, double TOL)
{
	return fabs (x - y) < TOL;
}

double log (double x, double b)
{
	return log10(x) / log10(b);
}

double degreesToRadians (double angle)
{
	return angle * M_PI / 180.0;
}

double cosineLaw (double angle, double side1, double side2)
{
	angle = degreesToRadians(angle);
	return sqrt(pow (side1,2) + pow (side2,2) - 2 * side1 * side2 * cos(angle));
}
