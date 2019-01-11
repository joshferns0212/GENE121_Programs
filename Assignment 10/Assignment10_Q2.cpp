#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

//Joshua Fernandes

using namespace std;

bool isPrime (int num, int factor)
{
	if (factor == num)
		return true;
	else if (num % factor == 0 || num <= 1)
		return false;
	else
		return isPrime(num, factor + 1);
}
int main()
{
	cout << "51\t" << isPrime(51, 2) << endl
		<< "91\t" << isPrime(91, 2) << endl
		<< "103\t" << isPrime(103, 2) << endl
		//additional primes
		<< "2\t" << isPrime(2, 2) << endl
		<< "3\t" << isPrime(3, 2) << endl
		<< "5\t" << isPrime(5, 2) << endl
		//additional nonprimes
		<< "1\t" << isPrime(1, 2) << endl
		<< "4\t" << isPrime(4, 2) << endl
		<< "20\t" << isPrime(20, 2) << endl;

		return EXIT_SUCCESS;
}
/*Output
51      0
91      0
103     1
2       1
3       1
5       1
1       0
4       0
20      0
*/
