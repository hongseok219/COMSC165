#include <iostream>
using std::cout;

int main()
{
  int i = 0;
  while(true)
  {
    cout << i << ". hello\n";
    if (i == 9)
      break;
    i++;
  }
}
