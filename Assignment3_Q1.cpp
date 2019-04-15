// Noah Gillespie-Friesen, Joshua Fernandes

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
	const int NUMOFTESTCASES = 9;

	string clearance = "";
	string resource = "";

	ifstream fin("A3Q1.txt");
	ofstream fout("A3Q1_OUTPUT.txt");

	if (!fin)
	{
		cout << "Unable to open file. ";
		system("PAUSE");
		return EXIT_FAILURE;
	}

	for(int line = 0; line < NUMOFTESTCASES; line ++)
	{
		fin >> clearance >> resource;

		fout << "Clearance " << clearance << " Resource " << resource
		<< endl;

		if(clearance == "Staff" && resource == "journal" ||
		clearance == "Student" && (resource == "book" || resource == "journal"))
		{
			fout << "You can borrow this resource for two weeks and you may "
			<< "borrow an unlimited amount." << endl;
		}

		else if(clearance == "Staff" && resource == "electronic" ||
			clearance == "Student" && resource == "electronic")
		{
			fout << "You may borrow this resource for an unlimited amount of "
			<< "time and an unlimited amount of copies." << endl;
		}

		else if(clearance == "Staff" && resource == "book")
		{
			fout << "You may borrow this resource for an entire term and you"
			<< " may borrow an unlimited amount of copies."<< endl;
		}

		else if(clearance == "Alumni" && resource == "book")
		{
			fout << "You may borrow this resource for up to two weeks and you"
			<< " may borrow up to 20 copies."<< endl;
		}

		else if(clearance == "Alumni" && (resource == "journal" || resource ==
			"electronic"))
		{
			fout << "You may not borrow this resource." << endl;
		}

		else
		{
			fout << "Invalid input. ";
		}
	}

	fin.close();
	fout.close();

	system("PAUSE");
	return EXIT_SUCCESS;
}

/*Input
Staff book
Staff journal
Staff electronic
Student book
Student journal
Student electronic
Alumni book
Alumni journal
Alumni electronic

Output
Clearance Staff Resource book
You may borrow this resource for an entire term and you may borrow an unlimited
 amount of copies.
Clearance Staff Resource journal
You can borrow this resource for two weeks and you may borrow an unlimited
 amount.
Clearance Staff Resource electronic
You may borrow this resource for an unlimited amount of time and an unlimited
 amount of copies.
Clearance Student Resource book
You can borrow this resource for two weeks and you may borrow an unlimited
 amount.
Clearance Student Resource journal
You can borrow this resource for two weeks and you may borrow an unlimited
 amount.
Clearance Student Resource electronic
You may borrow this resource for an unlimited amount of time and an unlimited
 amount of copies.
Clearance Alumni Resource book
You may borrow this resource for up to two weeks and you may borrow up to 20
 copies.
Clearance Alumni Resource journal
You may not borrow this resource.
Clearance Alumni Resource electronic
You may not borrow this resource.
*/
