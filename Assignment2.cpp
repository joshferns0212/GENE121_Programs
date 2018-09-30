#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
	const double SMALL_COFFEE = 0.9, REGULAR_COFFEE = 1.2, MINI_TART = 0.5, CHOCOLATE = 0.6, DONUT = 1;
	double mikesMoney = 0;

	cout << "Enter the amount of money you have Mike.\n";
	cin >> mikesMoney;
	cout << "You can buy:";

	if (mikesMoney >= 1.2)
	{
		cout << "\nregular coffee";

		mikesMoney -= REGULAR_COFFEE;
	}
	else if (mikesMoney >= 0.9)
	{
		cout << "\nsmall coffee";

		mikesMoney -= SMALL_COFFEE;
	}

	if (mikesMoney < 0.5)
	{
		cout << "\nMike, you are broke";
	}
	else if (mikesMoney < 0.6)
	{
		cout << "\nmini tart";
	}
	else if (mikesMoney < 1)
	{
		cout << "\nchocolate";
	}
	else
	{
		cout << "\ndonut";
	}


	return EXIT_SUCCESS;
}
