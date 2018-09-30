#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
	cout << "Enter month and year";
	int month = 0,year = 0;
	cin >> month >> year;
	
	if (month < 1 || month > 12 || year < 1)
	{
		cout << "Invalid data\n";
	}
	else
	{
			cout << month << ", " << year << " has ";
			
			int day = 0;
			
			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				day = 30;
			}
			else if (month == 2)
			{
				if (year >= 1582 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) || year < 1852 && year % 4 = 0)
				{
					day = 29;
				}
				else
				{
					day = 28;
				}
			}
	}
}
