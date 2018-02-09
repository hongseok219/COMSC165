// identification
// Hongseok Jang
// Lab 2, theBasics.2.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <iostream>
using std::cout;
using std::cin;
using std::ios;;

#include <string>
using std::string;
using std::getline;

#include <cstdlib>

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "Lab 0, hello.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  // program begins here
  int age;
  string buf;
  cout << "Enter your age: ";
  cin >> buf; age = atoi(buf.c_str());
  cin.ignore(1000,10);
  
  string name;
  cout << "Enter your name: ";
  getline (cin, name);
  
  double temperatureF;
  cout << "Enter the temperature outside right now (degrees F): ";
  cin >> buf; temperatureF = atof(buf.c_str());
  cin.ignore(1000,10);
  
  string city;
  cout << "What city are you in right now? ";
  getline (cin, city);
  
  cout << name << " is " << age << " years old now, and will be " << age + 10 << " ten years from now.\n";
  cout << "It's " << temperatureF << " degrees F in " << city << " -- that's ";
  double temperatureC = (temperatureF-32)/1.8;
  cout.setf(ios::fixed);
  cout.precision(1);
  cout << temperatureC << " degrees C.\n";
}
