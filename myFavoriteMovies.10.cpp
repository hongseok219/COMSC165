// identification
// Hongseok Jang
// Lab 10, myFavoriteMovies.10.cpp
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

#include <algorithm>
using std::swap;

#include <fstream>
using std::ifstream;
using std::ofstream;

struct Movie
{
  string title;
  int year;
  int rating;
  Movie* next;
};

void serializeUp(Movie*&);
void serializeDown(Movie*);
void listMovies(Movie*);
void sortByTitle(Movie*);
void sortByYears(Movie*);
void sortByRating(Movie*);
void AddAMovie(Movie*&);
void updateAMovie(Movie*);
void removeAMovie(Movie*&);
string toLowerCase(string);
void deallocateMovies(Movie*&);

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "myFavoriteMovies.10.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  Movie* firstMovie = 0;
  serializeUp(firstMovie);

  while(true)
  {
    cout << "MENU\n";
    cout << "A Add a movie\n";
    cout << "U update a Movie\n";
    cout << "E rEmove a Movie\n";
    cout << "L list all Movies\n";
    cout << "T arrange by title\n";
    cout << "V arrange by year viewed\n";
    cout << "R arrange by rating\n";
    cout << "Q quit\n";
    cout << "...your choice: ";
    
    char userinput;
    cin >> userinput;
    cin.ignore(1000,10);
    cout << "\n";
    
    if (toupper(userinput) == 'Q')
      break;
    else if (toupper(userinput) == 'A')
      AddAMovie(firstMovie);
    else if (toupper(userinput) == 'L')
      listMovies(firstMovie);
    else if (toupper(userinput) == 'T')
      sortByTitle(firstMovie);
    else if (toupper(userinput) == 'V')
      sortByYears(firstMovie);
    else if (toupper(userinput) == 'R')
      sortByRating(firstMovie);
    else if (toupper(userinput) == 'U')
      updateAMovie(firstMovie);
    else if (toupper(userinput) == 'E')
      removeAMovie(firstMovie);
  }

  serializeDown(firstMovie);
  deallocateMovies(firstMovie);
}

void serializeUp(Movie*& head)
{
  ifstream fin;
  fin.open("myFavoriteMovies.10.txt");
  if (!fin.good()) return;
    
  while (true)
  {
    string buf;
    getline(fin, buf);
    if (buf == "EOF") break;

    Movie* temp = new Movie;
    temp->title = buf;

    fin >> temp->year;
    fin.ignore(1000, 10);
    fin >> temp->rating;
    fin.ignore(1000, 10);

    temp->next = head;
    head = temp;
  }
  fin.close();
}

void serializeDown(Movie* head)
{
  ofstream fout;
  fout.open("myFavoriteMovies.10.txt");
 
  for (Movie* p = head; p; p = p->next)
  {
    fout << p->title << "\n";
    fout << p->year << "\n";
    fout << p->rating << "\n";
  }
  fout << "EOF\n";
  fout.close();
}

void listMovies(Movie* firstMovie)
{
  cout << "Title             Viewed  Rating\n";
  cout << "----------------- ------  -------\n";
  int n = 1;
  for(Movie* p = firstMovie; p; p = p->next, n++)
  {
    cout.setf(ios::left); cout.width(15); cout << p->title;
    cout.unsetf(ios::left); cout.width(7); cout << p->year;
    cout.width(8); cout << p->rating;
    cout <<"\n";
  }
  cout << "\n";
}

void sortByTitle(Movie* firstMovie)
{
  for(Movie* p = firstMovie; p; p = p->next)
    for(Movie* q = p->next; q; q = q->next)
      if(toLowerCase(p->title) > toLowerCase(q->title))
      {
        swap(*p, *q);
        swap(p->next, q->next);
      }
}

void sortByYears(Movie* firstMovie)
{
  for(Movie* p = firstMovie; p; p = p->next)
    for(Movie* q = p->next; q; q = q->next)
      if(p->year > q->year)
      {
        swap(*p, *q);
        swap(p->next, q->next);
      }
}

void sortByRating(Movie* firstMovie)
{
  for(Movie* p = firstMovie; p; p = p->next)
    for(Movie* q = p->next; q; q = q->next)
      if(p->rating > q->rating)
      {
        swap(*p, *q);
        swap(p->next, q->next);
      }
}

void AddAMovie(Movie*& head)
{
  Movie* temp = new Movie;
  cout << "Enter a Movie's name: ";
  getline(cin, temp->title);
  cout << "Enter the year you saw " << temp->title << " [like 2016]: ";
  string buf;
  cin >> buf;
  temp->year = atoi(buf.c_str());
  cin.ignore(1000,10);
  cout << "Enter the rating for " << temp->title << " [1, 2, 3, 4, 5]: ";
  cin >> buf;
  temp->rating = atoi(buf.c_str());
  cin.ignore(1000,10);
  cout << "\n";
  temp->next = head;
  head = temp;
}

void updateAMovie(Movie* firstMovie)
{
  int n = 0;
  Movie* p;
  for(p = firstMovie; p; p = p->next, n++)
  {
  }
  cout << "Which one to rename(1-" << n << ")? ";
  string buf;
  cin >> buf;
  n = atoi(buf.c_str());
  cin.ignore(1000,10);
  int i = 1;
  for(p = firstMovie; p && i != n; p = p->next, i++)
  {
  }
  if (p)
  {
    cout << "Enter an updated name for " << n << ": ";
    getline(cin, p->title);
    cout << "Enter the year you saw " << p->title << " [like 2016]: ";
    cin >> buf;
    p->year = atoi(buf.c_str());
    cin.ignore(1000,10);
    cout << "Enter the rating for " << p->title << " [1, 2, 3, 4, 5]: ";
    cin >> buf;
    p->rating = atoi(buf.c_str());
    cin.ignore(1000,10);
  }
  else
    cout << "Movie numbered " << buf << " not found\n";
  cout << "\n";
}

void removeAMovie(Movie*& firstMovie)
{
  int n = 0;
  Movie* p, *prev;
  for(p = firstMovie; p; p = p->next, n++)
  {
  }
  cout << "Which one to remove(1-" << n << ")?: ";
  string buf;
  cin >> buf;
  n = atoi(buf.c_str());
  cin.ignore(1000,10);
  int i = 1;
  for(p = firstMovie, prev = 0; p && i != n; prev = p, p = p->next, i++)
  {
  }
  if(p)
  {
    if (prev) prev->next = p->next;
    else firstMovie = firstMovie->next;
    delete p;
  }
  else
    cout << "Movie numbered " << n << " not found\n";
  cout << "\n";
}

string toLowerCase(string aCppString)
{
  int n = aCppString.length();
  for (int i = 0; i < n; i++)
    aCppString[i] = tolower(aCppString[i]);
  return aCppString;
}

void deallocateMovies(Movie*& head)
{
  while (head)
  {
    Movie* p = head; 
    head = head->next; 
    delete p;
  }  
}
