// identification
// Hongseok Jang
// Lab 11, myFavoritePizza.11b.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <cstdlib>
#include <cctype>

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

struct Password
{
  string acount;
  int password;
  Password* next;
};

void serializeUp(Password*&, Password*&);
void serializeDown(Password*);
void deallocatePasswords(Password*&, Password*&);
void listPasswords(Password*);
void AddAPassword(Password*&, Password*&);
void removeAPassword(Password*&, Password*&);
int comparePasswords(Password*, Password*);
string encode(string);
string decode(string);

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "myFavoritePizza.11b.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  Password* firstPassword = 0, *lastPassword = 0;
  serializeUp(firstPassword, lastPassword);
  
  while(true)
  {
    cout << "MENU\n";
    cout << "A add a password\n";
    cout << "R remove a password\n";
    cout << "L list all password\n";
    cout << "X exit\n";
    cout << "...your choice: ";
    
    char userinput;
    cin >> userinput;
    cin.ignore(1000,10);
    cout << "\n";
    
    if (toupper(userinput) == 'X')
      break;
    else if (toupper(userinput) == 'A')
      AddAPassword(firstPassword, lastPassword);
    else if (toupper(userinput) == 'L')
      listPasswords(firstPassword);
    else if (toupper(userinput) == 'R')
      removeAPassword(firstPassword, lastPassword);
  }
  
  serializeDown(firstPassword);
  deallocatePasswords(firstPassword, lastPassword);
}

void serializeUp(Password*& head, Password*& tail)
{
  ifstream fin;
  fin.open("myFavoritePizza.11b.txt");
  if (!fin.good()) return;
  
  while (true)
  {
    string buf;
    getline(fin, buf);
    if (buf == "EOF") break;
    
    Password* temp = new Password;
    temp->acount = decode(buf);
    fin >> temp->password;
    fin.ignore(1000, 10);
    
    Password* p, *prev;
    for (p = head, prev = 0; p; prev = p, p = p->next)
      if (comparePasswords(temp, p) < 0) break;
    temp->next = p;
    if(prev) prev->next = temp;
    else head = temp;
    if (p == 0) tail = temp;
  }
  fin.close();
}

void serializeDown(Password* head)
{
  ofstream fout;
  fout.open("myFavoritePizza.11b.txt");
  
  for (Password* p = head; p; p = p->next)
  {
    fout << encode(p->acount) << "\n";
    fout << p->password << "\n";
  }
  fout << "EOF\n";
  fout.close();
}

void listPasswords(Password* firstPassword)
{
  cout << "# Acount              Password\n";
  cout << "- ------------------- --------\n";
  int n = 1;
  for(Password* p = firstPassword; p; p = p->next, n++)
  {
    cout.setf(ios::left); cout.width(2);
    cout << n;
    cout.width(20); cout << p->acount;
    cout.width(11); cout << p->password;
    cout <<"\n";
  }
  cout << "\n";
}

void AddAPassword(Password*& head, Password*& tail)
{
  Password* temp = new Password;
  
  cout << "Enter a Acount: ";
  getline(cin, temp->acount);
  cout << "Enter the Password for " << temp->acount << ": ";
  string buf;
  cin >> buf;
  temp->password = atoi(buf.c_str());
  cin.ignore(1000,10);
  cout << "\n";
  
  Password* p, *prev;
  for (p = head, prev = 0; p; prev = p, p = p->next)
    if (comparePasswords(temp, p) < 0) break;
  temp->next = p;
  if (prev) prev->next = temp;
  else head = temp;
  if (p == 0) tail = temp;
}

void removeAPassword(Password*& firstPassword, Password*& tail)
{
  int n = 0;
  Password* p, *prev;
  for(p = firstPassword; p; p = p->next, n++);
  cout << "Which one to remove(1-" << n << ")?: ";
  string buf;
  cin >> buf;
  n = atoi(buf.c_str());
  cin.ignore(1000,10);
  int i = 1;
  for(p = firstPassword, prev = 0; p && i != n; prev = p, p = p->next, i++);
  if(p)
  {
    if (prev) prev->next = p->next;
    else firstPassword = firstPassword->next;
    delete p;
  }
  else
    cout << "Password numbered " << n << " not found\n";
  cout << "\n";
}

void deallocatePasswords(Password*& head, Password*& tail)
{
  while (head)
  {
    Password* p = head;
    head = head->next;
    delete p;
  }
  tail = 0;
}

int comparePasswords(Password* a, Password* b)
{
  if (a->acount < b->acount) return -1;
  if (a->acount > b->acount) return 1;
  return 0;
}

string encode(string aCppString)
{
  int n = aCppString.length();
  for (int i = 0; i < n; aCppString[i]++, i++);
  return aCppString;
}

string decode(string aCppString)
{
  int n = aCppString.length();
  for (int i = 0; i < n; aCppString[i]--, i++);
  return aCppString;
}
