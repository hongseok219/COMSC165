// identification
// Hongseok Jang
// Lab 12, threeQuestions.12a.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

struct Movie
{
  string sayThis;
  Movie* yes;
  Movie* no;
};

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "threeQuestions.12a.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  Movie a = {"It's Civil war"};
  Movie b = {"It's Age of Ultron"};
  Movie c = {"It's Avengers"};
  Movie d = {"It's First Avenger"};
  Movie e = {"It's Hulk"};
  Movie f = {"It's Iron Man"};
  Movie g = {"It's Thor"};
  Movie h = {"It's Dead Pool"};
  
  Movie i = {"Is there Spider man?", &a, &b};
  Movie j = {"Is there Hawk Eye?", &d, &d};
  Movie k = {"Can main character change into monster?", &e, &f};
  Movie l = {"Is there Special hammer?", &g, &h};
  
  Movie m = {"Is there Scarlet Witch?", &i, &j};
  Movie n = {"Is main character Scientist?", &k, &l};
  Movie o = {"Is there Captain America?", &m, &n};
  
  Movie* top = &o;
  char userInput;
  
  while (true)
  {
    cout << "I have a list of Marvel movies";
    cout << "You think one of them. I will try to guess what it is.\n";
    
    Movie* p = top;
    while (true)
    {
      cout << p->sayThis;
      if (p->yes == 0 && p->no == 0) break;
      cout << "[Y/N] ";
      
      cin >> userInput;
      if (userInput == 'y' || userInput == 'Y') p = p->yes;
      else if (userInput == 'n' || userInput == 'N') p = p->no;
    }
    cout << "\n\nPlay again? [Y/N] ";
    cin >> userInput;
    if (userInput != 'Y' && userInput != 'y')break;
  }
}