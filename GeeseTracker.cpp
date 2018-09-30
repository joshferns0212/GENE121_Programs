#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
	ifstream fin ("geese.txt");

	if (!fin)
	{
		cout << "no file";
		system ("PAUSE");
		return EXIT_FAILURE;
	}

	int total = 0, numDay = 0;

	while (fin >> numDay)
	{
		int sum = 0;

		for (int count = 0; count < numDay; count++)
		{
			int numGeeseSeen = 0;
			fin >> numGeeseSeen;
			sum += numGeeseSeen;
		}

		total += sum;

		cout << "Average " << sum / numDay << endl;
	}
	// system ("PAUSE");
	return 0;
}
