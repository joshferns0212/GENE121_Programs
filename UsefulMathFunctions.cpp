// Joshua Fernandes

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;


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

int main()
{
	double x = 0, y = 0, TOL = 0, b = 0, angle = 0, side1 = 0, side2 = 0;

	cout << "Function 1: Tolerance\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter y: ";
		cin >> y;
		cout << "Enter TOL: ";
		cin >> TOL;
		cout << "Output: " << withinTolerance(x,y,TOL) << "\n";
	}

	cout << "\nFunction 2: Logarithmic Change of Base\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter x: ";
		cin >> x;

		while (x <= 0)
		{
			cout << "Re-enter x: ";
			cin >> x;
		}

		cout << "Enter b: ";
		cin >> b;

		while (b <= 0)
		{
			cout << "Re-enter b: ";
			cin >> b;
		}

		cout << "Output: " << log (x,b) << "\n";
	}

	cout << "\nFunction 3: Convert To Radians\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter angle: ";
		cin >> angle;
		cout << "Output: " << degreesToRadians(angle) << "\n";
	}

	cout << "\nFunction 4: Cosine Law\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter angle: ";
		cin >> angle;

		while (angle >=180 && angle != 0)
		{
			cout << "Re-enter angle: ";
			cin >> angle;
		}

		cout << "Enter side1: ";
		cin >> side1;

		while (side1 <= 0)
		{
			cout << "Re-enter side1: ";
			cin >> side1;
		}

		cout << "Enter side2: ";
		cin >> side2;

		while (side2 <= 0)
		{
			cout << "Re-enter side2: ";
			cin >> side2;
		}

		cout << "Output: " << cosineLaw (angle, side1, side2) << "\n";
	}
}

/*Output
Function 1: Tolerance
Enter x: 4.5
Enter y: 5.5
Enter TOL: 1.2
Output: 1 			<- Expected Ouput: 1
Enter x: 9
Enter y: 7.9
Enter TOL: 1
Output: 0			<- Expected Ouput: 0
Enter x: 4.5
Enter y: 4.6
Enter TOL: 0
Output: 0			<- Expected Ouput: 0

Function 2: Logarithmic Change of Base
Enter x: 8
Enter b: 2
Output: 3			<- Expected Ouput: 3
Enter x: 2
Enter b: 4
Output: 0.5			<- Expected Ouput: 0.5
Enter x: 0
Re-enter x: 9
Enter b: -6
Re-enter b: 3
Output: 2			<- Expected Ouput: 2

Function 3: Convert To Radians
Enter angle: 180
Output: 3.14159		<- Expected Ouput: 3.14
Enter angle: 0
Output: 0			<- Expected Ouput: 0
Enter angle: -90
Output: -1.5708		<- Expected Ouput: -1.57

Function 4: Cosine Law
Enter angle: 90
Enter side1: 3
Enter side2: 4
Output: 5			<- Expected Ouput: 5
Enter angle: 60
Enter side1: 0
Re-enter side1: 5
Enter side2: -44
Re-enter side2: 4
Output: 4.58258		<- Expected Ouput: 4.58
Enter angle: 360
Re-enter angle: 120
Enter side1: 1
Enter side2: 1
Output: 1.73205		<- Expected Ouput: 1.73

Press any key to continue . . .
*/
