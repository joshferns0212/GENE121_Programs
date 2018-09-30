#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
	float numFloat = 0;
	double numDouble = 0;
	long double numLongDouble = 0;
	
	cout << "Enter angle in degrees.\n"; //float
	cin >> numFloat;
	
	numFloat *= M_PI / 180.0;
	
	if ((pow (sin (numFloat),2) + pow (cos (numFloat), 2) - 1) == 0)
	{
		cout << "d = sin^2x + cos^2x - 1 is equal to zero.\n";
	}
	else
	{
		cout << "d = sin^2x + cos^2x - 1 is not equal to zero.\n";
	}
	
	cout << "Enter angle in degrees.\n"; //double
	cin >> numDouble;
	
	numDouble *= M_PI / 180.0;
	
	if ((pow (sin (numDouble),2) + pow (cos (numDouble), 2) - 1) == 0)
	{
		cout << "d = sin^2x + cos^2x - 1 is equal to zero.\n";
	}
	else
	{
		cout << "d = sin^2x + cos^2x - 1 is not equal to zero.\n";
	}
	
	cout << "Enter angle in degrees.\n"; //long double
	cin >> numLongDouble;
	
	numDouble *= M_PI / 180.0;
	
	if ((pow (sin (numDouble),2) + pow (cos (numDouble), 2) - 1) == 0)
	{
		cout << "d = sin^2x + cos^2x - 1 is equal to zero.\n";
	}
	else
	{
		cout << "d = sin^2x + cos^2x - 1 is not equal to zero.\n";
	}
	
}
