#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
  ifstream fin("num.txt");
  if (!fin)
  {
    cout << "no file";
    return EXIT_FAILURE;
  }

  int sum = 0;


  for (int count = 0; count < 5; count++)
  {
      int num = 0;
      fin >> num;

      sum += num;
  }

  cout << "average" << sum / 5.0 << "\n";
  fin.close();

  system ("PAUSE");
  return EXIT_SUCCESS;
}
