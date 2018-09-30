#include <iostream>
#include <cmath>
#include <cstdlib>

//assume angle <= 180
using namespace std;

int main ()
{
	double length = 0, theta = 0, x = 0, y = 0;

	cout << "Enter the length\n";
	cin >> length;

	cout << "Enter the angle in radians\n";
	cin >> theta;

	theta *= M_PI / 180.0;
	x = length * cos (theta);
	y = length * sin (theta);

	cout << "The coordinate pair is (" << x << ", " << y << ")\n";

	system ("PAUSE");
	return EXIT_SUCCESS;
}
