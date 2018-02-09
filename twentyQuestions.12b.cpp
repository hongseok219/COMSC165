// identification
// Hongseok Jang
// Lab 12, twentyQuestions.12b.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <string>
using std::string;
using std::getline;

#include <iostream>
using std::cin;
using std::cout;
using std::ios;

#include <fstream>
using std::ifstream;
using std::ofstream;

struct Sport
{
  string sayThis;
  Sport* yes;
  Sport* no;
};

Sport* serializeUp(ifstream&);
void deallocate(Sport*);


int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "twentyQuestions.12b.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  Sport* top = 0;
  
  ifstream fin;
  fin.open("twentyQuestions.12b.txt");
  if (fin.good())
  {
    top = serializeUp(fin);
    fin.close();
  }
  else
  {
    top = new Sport;
    top->sayThis = "Soccer";
    top->yes = top->no = 0;
  }
  
  Sport* p = top;
  
  cout << "You think of a Sport. I'll try to guess what it is.\n";
  char yesOrNo;
  char userInput;
  while (true)
  {
    while (true)
    {
      if (p->yes != 0)
      {
        cout << p->sayThis << "[Y/N]";
        cin >> yesOrNo;
        if (yesOrNo == 'y' || yesOrNo == 'Y') p = p->yes;
        else if (yesOrNo == 'n' || yesOrNo == 'N') p = p->no;
      }
      else
      {
        cout << "It's " << p->sayThis;
        cout << " Right? ";
        cin >> yesOrNo;
        cin.ignore(1000, 10);
        
        if (yesOrNo == 'N' || yesOrNo == 'n')
        {
          cout << "Oh...Ok I will make better program in next semester\n";
          break;
        }
        else if (yesOrNo == 'Y' || yesOrNo == 'y')
        {
          cout << "You're god damn right(in Breaking Bad)\n";
          break;
        }
      }
    }
    cout << "\nPlay again? [Y/N] ";
    cin >> userInput;
    if (userInput == 'N' || userInput == 'n')
      break;
    else if (userInput == 'Y' || userInput == 'y')
      p = top;
  }
  deallocate(top);
}

Sport* serializeUp(ifstream& fin)
{
  string buf;
  getline(fin, buf);
  if (buf == "EOF") return 0;
  
  Sport* p = new Sport;
  p->sayThis = buf;
  p->yes = serializeUp(fin);
  p->no = serializeUp(fin);
  return p;
}

void deallocate(Sport* p)
{
  if (p == 0) return;
  deallocate(p->yes);
  deallocate(p->no);
  delete p;
}

