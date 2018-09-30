#include <iostream> 
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
	double length = 0, x_coord = 0, y_coord = 0, dist = 0;
	const double TOL = 0.1;
	ifstream fin("A3Actual.txt");
	
	if (!fin)
	{
		cout << "Unable to open file. ";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	fin >> length;
	
	int can = 0, can_not = 0;
	
	while(fin >> x_coord >> y_coord)
	{
		dist = sqrt(pow(x_coord,2)+ pow(y_coord,2));
		
		if(fabs(length-dist) < TOL)
			can ++;
		else
			can_not ++;
	}
	
	cout << "The robot was able to reach " << can << " trajectories, and "
		<< "missed " << can_not << " trajectories. " << endl;
		 
	fin.close();
