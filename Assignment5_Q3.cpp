#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int timeToMinutes (int time)
{
	int minutes = time - ((int)(time / 100)) * 100 + ((int)(time / 100)) * 60;
	return minutes;
}

double distanceTo (double x, double y)
{
	double distance = sqrt (pow (x,2) + pow (y,2));
	return distance;
}

double angleTo (double x, double y)
{
	double angle = atan2(y,x) * 180 / M_PI;

	return angle;
}

int main ()
{
	ifstream fin("wascally_wabbits.txt");
	ofstream fout("output.txt");
	int time = 0, previousTime = 0, shortestTime = 24 * 60;
	double distance = 0, angle = 0, x = 0, y = 0;

	fout << "Distance Heading\n" << fixed << setprecision (2);

	if (!fin)
	{
		cout << "no file";
		system ("PAUSE");
		return EXIT_FAILURE;
	}

	while (fin >> time)
	{
		fin >> x >> y;
		time = timeToMinutes (time);
		distance = distanceTo (x,y);
		angle = angleTo (x,y);

		if (time - previousTime < shortestTime && previousTime != 0)
		{
			shortestTime = time - previousTime;
		}

		previousTime = time;

		fout << setw (8) << distance << setw(8) << angle << "\n";
	}

	fout << "Shortest Time: " << shortestTime;

	fin.close();
	fout.close();

	system ("PAUSE");
	return EXIT_SUCCESS;
}
