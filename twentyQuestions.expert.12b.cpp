// identification
// Hongseok Jang
// Lab 12, twentyQuestions.expert.12b.cpp
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
void serializeDown(ofstream&, Sport*);
void deallocate(Sport*);


int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "twentyQuestions.expert.12b.cpp\n";
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
          string answer;
          cout << "What is it, then? ";
          getline(cin, answer);
          Sport* yes = new Sport;
          Sport* no = new Sport;
          yes->yes = yes->no = 0;
          no->yes = no->no = 0;
          p->yes = yes;
          p->no = no;
          
          string question;
          cout << "Dang! So that I don't make this mistake again,\nwhat yes/no question can I ask to differentiate ";
          cout << answer << " from " << p->sayThis << "?";
          getline(cin, question);
          
          cout << "Thanks. And what's the answer to " << question << " for " << answer << "?";
          cin >> yesOrNo;
          cin.ignore(1000, 10);
          
          if (yesOrNo == 'Y' || yesOrNo == 'y')
          {
            yes->sayThis = answer;
            no->sayThis = p->sayThis;
          }
          else
          {
            yes->sayThis = p->sayThis;
            no->sayThis = answer;
          }
          p->sayThis = question;
        }
        else if (yesOrNo == 'Y' || yesOrNo == 'y')
          break;
        ofstream fout;
        fout.open("twentyQuestions.12b.txt");
        serializeDown(fout, top);
        fout.close();
      }
    }
    cout << "\nPlay again? [Y/N] ";
    cin >> userInput;
    if (userInput != 'Y' && userInput != 'y')
      break;
    else
      p = top;
      cout << "\n";
  }
  deallocate(top);
}

void serializeDown(ofstream& fout, Sport* p)
{
  if (p == 0)
    fout << "EOF\n";
  else
  {
    fout << p->sayThis << "\n";
    serializeDown(fout, p->yes);
    serializeDown(fout, p->no);
  }
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

