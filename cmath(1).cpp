#include <iostream>
using std::cout;

#include <cmath>

int main()
{
  int i = 1;
  while(true)
  {
    double squareRoot = sqrt(i)  ;
    cout << "The square root of " << i << " is " << squareRoot << "\n";
    if (i == 10)
      break;
    i++;
  }
  double j = 1;
  while(true)
  {
    double cubeRoot = pow(j,1/3.);
    cout << "The cube root of " << j << " is " << cubeRoot << "\n";
    if (j == 10)
      break;
    j++;
  }
}
