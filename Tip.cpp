#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
	double subtotal = 0, tipPercent= 0;
	cout << "Enter subtotal and tip percentage " << endl;
	cin >> subtotal >> tipPercent;
	
	
	if (subtotal >= 0 && tipPercent >= 0)
	{
		double tax = subtotal * 0.13;
		double tip = subtotal * tipPercent / 100.0;
		
		cout << "Tax " << tax << endl << "Tip " << tip << endl << "Total " << tax + tip + subtotal;
	}
	else
	{
		cout << "Invalid data" << endl;
	}
	
	system ("PAUSE");
	return EXIT_SUCCESS;
}
