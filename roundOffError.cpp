// identification
// Hongseok Jang
// Lab 3, roundOffError.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <iostream>
using std::cout;

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "Lab 3, roundOffError.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  // program begins here
  double y = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
  cout << "the sum of ten 0.1's is 1\n";
  if (y == 1)
    cout << "it's EXACTLY one, like I thought\n";
  if (0.9999 < y && y < 1.0001)
    cout << "it's real close to one, like I thought\n";
}
