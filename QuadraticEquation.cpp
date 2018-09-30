#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
	double a = 0, b = 0, c = 0;
	cout << "Enter a, b, and c ";
	cin >> a >> b >> c;

	if (a != 0) //quadratic
	{
		double discriminant = b * b - 4 * a * c;

		if (discriminant >= 0) //real roots
		{
			cout << (-1 * b + sqrt(discriminant)) / (2 * a) << (-1 * b - sqrt (discriminant)) / (2 * a);
		}
		else // imaginary roots
		{
			cout << (-1 * b) / (2 * a) << " "<< (sqrt(discriminant)) / (2 * a) << "j \n" << (-1 * b - sqrt (discriminant)) / (2 * a);
		}

	}
	else
	{
		if (b != 0) //linear
		{
			cout << -1 * c / b;
		}
		else
		{
			cout << "Invalid";
		}
	}
}
