// identification
// Hongseok Jang
// Lab 4, fiveHDTVs.4b.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <iostream>
using std::cout;
using std::ios;

#include <cstdlib>

#include <cmath>

double width(int);
double height(int);
int area(int);
void sampleTv(int);

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "fiveHDTVs.4b.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  cout << "diagonal      width      height        area\n";
  cout << "--------      -----      ------        ----\n";
  sampleTv(42);
  sampleTv(50);
  sampleTv(80);
  sampleTv(32);
  sampleTv(24);
  cout << "\n";
}

double width(int diagonal)
{
  return diagonal * 16 / sqrt((pow(16,2.0) + pow(9,2.0)));
}

double height(int diagonal)
{
  return diagonal * 9 / sqrt((pow(16,2.0) + pow(9,2.0)));
}

int area(int diagonal)
{
  return diagonal * diagonal * 16 / sqrt((pow(16,2.0) + pow(9,2.0))) * 9/sqrt((pow(16,2.0) + pow(9,2.0))) + 0.5;
}

void sampleTv(int diagonal)
{
  cout.width(5);
  cout << diagonal;

  cout.width(14);
  cout.setf(ios::fixed);
  cout.precision(1);
  cout << width(diagonal);
  
  cout.width(12);
  cout << height(diagonal);
  
  cout.width(12);
  cout << area(diagonal) << "\n";
}
