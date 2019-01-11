//Joshua Fernandes
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void increment (int & time)
{
	time++;
	int hours = time / 100,
	minutes = time - 100 * hours;

	if (hours == 24)
	{
		time = minutes;
	}
	else if (minutes == 60)
	{
		time = hours + 100;
	}
}
int main ()
{
	int num = 2403;
	increment (num);
	cout << num;
}
