#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
	int limit = 0;
	cin >> limit;

	for (int row = 1; row <= limit; row++)
	{
		for (int col = 1; col <= limit; col++)
		{
			cout << row * col << " ";
		}
		cout << endl;
	}

	// system ("PAUSE");
	return 0;
}
