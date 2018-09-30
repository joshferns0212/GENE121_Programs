#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

main ()
{
	int temperature = 0;
	cout << "Enter temperature ";
	cin >> temperature;

	if (temperature < -40 || temperature > 40)
	{
		cout << "Invalid temperature";
	}
	else if (temperature < 10)
	{
		cout << "Cold temperature";
	}
	else if (temperature < 25)
	{
		cout << "Warm temperature";
	}
	else
	{
		cout << "Hot temperature";
	}

	system ("PAUSE");
	return EXIT_SUCCESS;
}
