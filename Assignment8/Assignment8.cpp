// Joshua Fernandes
#include <cmath>
#include <fstream>
#include "ccc_win.h"

using namespace std;

int ccc_win_main()
{
	int numberOfPumpkins = cwin.get_int("Enter the number of pumpkins");
	
	for (int i = 0; i < numberOfPumpkins; i++)
	{
		Point position = cwin.get_mouse("Click where you want the pumpkin to go");
		
		cwin << Circle (position,2)
		<< Point (position.get_x() - 0.75, position.get_y() + 0.75) 
		<< Point (position.get_x() + 0.75, position.get_y() + 0.75)
		<< Line (Point (position.get_x() - 0.75,position.get_y() - 0.75),
		 Point (position.get_x() + 0.75, position.get_y() - 0.75))
		<< Line (Point (position.get_x() - 0.4, position.get_y() + 2.6),
		 Point (position.get_x() + 0.4, position.get_y() + 2.6))
		<< Line (Point (position.get_x() - 0.4, position.get_y() + 2.6),
		 Point (position.get_x() - 0.4, position.get_y() + 1.95))
		<< Line (Point (position.get_x() + 0.4, position.get_y() + 2.6),
		 Point (position.get_x() + 0.4, position.get_y() + 1.95));
	}

return 0;
}
