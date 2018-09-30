//Abhinav Gupta and Joshua Fernandes

#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin("taxi.txt");
	ofstream fout("output.txt");
	
	double distance = 0, xCoord = 0, yCoord = 0, currentX = 0,
	currentY = 0, cost = 0,	cumulativeDistance = 0, cumulativeCost = 0, 
	longestTrip = 0, leastCost = 2000;
	int tripNum = 1, roundTrip = 0, numOfStops = 0;
	const double COST_PER_STOP = 11, COST_PER_KILOMETER = 2.7;
	
	fout <<"Trip" << setw (8) << "Return" << setw (7) << "Stops" << setw (10)
	<< "Distance" << setw (8) << "Cost" << setw (12) << "Cumulative" 
	<< setw (12) << "Cumulative\n" << setw (49) << "Distance" << setw (12)
	<< "Cost\n" << fixed << setprecision (2);
	
	
	while (fin >> roundTrip)
	{
		fin >> numOfStops;
		
		for (int i = 1; i <= numOfStops; i++)
		{
			fin >> xCoord >> yCoord;
			
			currentX += xCoord;
			currentY += yCoord;
			
			distance += sqrt (pow(xCoord,2) + pow(yCoord,2));
		}
		
		if (roundTrip)
		{
			distance += sqrt (pow(currentX,2) + pow(currentY,2));
		}
		
		cost = numOfStops * COST_PER_STOP + distance * COST_PER_KILOMETER;
		
		if (distance > longestTrip)
		{
			longestTrip = distance;
		}
		if (cost < leastCost)
		{
			leastCost = cost;
		}
		
		cumulativeDistance += distance;
		cumulativeCost += cost;
		
		if (tripNum <= 7 || (tripNum - 7) % 10 == 0)
		{
			fout << setw (4) <<tripNum << setw (8) << roundTrip << setw (7) 
			<< numOfStops << setw (10) << distance << setw (8) << cost << setw (12) 
			<< cumulativeDistance << setw (12) << cumulativeCost<<"\n";
		}
		
		distance = 0, xCoord = 0, yCoord = 0, cost = 0;
		tripNum++;
	}
	
		fout << "Cumulative Distance: " << cumulativeDistance
		<< "\nCumulative Cost: " << cumulativeCost << "\nLongest Trip: "
		<< longestTrip << "\nLeast Cost: " << leastCost;
	
	system ("PAUSE");
	return EXIT_SUCCESS;
}

/*Output
Trip  Return  Stops  Distance    Cost  Cumulative Cumulative
                                         Distance       Cost
   1       0      1     10.20   38.54       10.20       38.54
   2       1      2     13.80   59.26       24.00       97.80
   3       0      4     23.81  108.29       47.81      206.09
   4       0      3     17.35   79.85       65.17      285.95
   5       0      5     33.61  145.76       98.78      431.71
   6       1      7     52.17  217.86      150.95      649.57
   7       0      2      8.60   45.21      159.55      694.78
  17       0      5     40.04  163.11      490.23     1983.61
  27       0      3     22.78   94.50     1261.57     4396.25
  37       0      2     14.85   62.10     2178.00     7200.61
  47       1      2    301.81  836.88     3464.00    10991.80
  57       0      2     19.40   74.38     4732.60    14725.03
  67       0      4     26.26  114.89     6504.17    19816.25
  77       0      1      7.73   31.88     8448.07    25295.80
Cumulative Distance: 8465.98
Cumulative Cost: 25377.14
Longest Trip: 485.36
Least Cost: 23.44
*/
