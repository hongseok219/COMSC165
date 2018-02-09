// identification
// Hongseok Jang
// Lab 3, makeChange.3.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <iostream>
using std::cout;
using std::cin;
using std::ios;

#include <string>
using std::string;

#include <cstdlib>

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "makeChange.3.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  // program begins here
  double purchaseAmount;
  double amountTendered;
  string buf;

  cout << "Enter Purchase amount (space) Amount tendered:  ";
  cin >> buf; purchaseAmount = atof(buf.c_str());
  cin >> buf; amountTendered = atof(buf.c_str());
  cin.ignore(1000, 10);
  
  double changeOrigin = amountTendered - purchaseAmount;
  double changePlus = changeOrigin + 0.0001;
  int change = 100 * changePlus;

  int hundred = change / 10000;
  change = change % 10000;

  int fifty = change / 5000;
  change = change % 5000;

  int twenty = change / 2000;
  change = change % 2000;

  int ten = change / 1000;
  change = change % 1000;

  int five = change / 500;
  change = change % 500;

  int one = change / 100;
  change = change % 100;

  int fiftyCent = change /50;
  change = change % 50;

  int twentyfiveCent = change / 25;
  change = change % 25;

  int tenCent = change / 10;
  change = change % 10;

  int fiveCent = change / 5;
  change = change % 5;

  int oneCent = change;

  cout << "$" << changeOrigin << "\n";
  
  if (hundred != 0)
  {
    cout << hundred << " $100 bill";
      if (hundred != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (fifty != 0)
  {
    cout << fifty << " $50 bill";
      if (fifty != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (twenty != 0)
  {
    cout << twenty << " $20 bill";
      if (twenty != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (ten != 0)
  {
    cout << ten << " $10 bill";
      if (ten != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (five != 0)
  {
    cout << five << " $5 bill";
      if (five != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (one != 0)
  {
    cout << one << " $1 bill";
      if (one != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (fiftyCent != 0)
  {
    cout << fiftyCent << " 50-cent coin";
      if (fiftyCent != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (twentyfiveCent != 0)
  {
    cout << twentyfiveCent << " 25-cent coin";
      if (twentyfiveCent != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (tenCent != 0)
  {
    cout << tenCent << " 10-cent coin";
      if (tenCent != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (fiveCent != 0)
  {
    cout << fiveCent << " 5-cent coin";
      if (fiveCent != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
  if (oneCent != 0)
  {
    cout << oneCent << " 1-cent coin";
      if (oneCent != 1)
        cout << "s\n";
      else
        cout << "\n";
  }
}
