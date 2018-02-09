// identification
// Hongseok Jang
// Lab 4, myTv.4a.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <iostream>
using std::cout;
using std::cin;
using std::ios;

#include <string>
using std::string;

#include <cstdlib>

#include <cmath>

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "myTv.4a.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  // program begins here
  string buf;
  double inch;
  cout << "Enter the diagonal size of your favorite TV, in inches: ";
  cin >> buf; inch = atof(buf.c_str());
  cin.ignore(1000,10);
  
  double area = inch * inch * 16/sqrt((pow(16,2.0)+pow(9,2.0)))*9/sqrt((pow(16,2.0)+pow(9,2.0)));
  cout << "The area of a " << inch  << " inch TV is ";
  cout.setf(ios::fixed);
  cout.precision(1);
  cout << area << "\n";
}
