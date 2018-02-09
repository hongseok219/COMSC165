// identification
// Hongseok Jang
// Lab 9, myFavoriteMovies.9.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <cstdlib>
#include <cstring>
#include <cctype>

#include <iostream>
using std::cin;
using std::cout;
using std::ios;

#include <algorithm>
using std::swap;

struct Movie
{
  char title[50];
  int year;
  char rating;
  Movie* next;
};

void listMovies(Movie*);
void sortByTitle(Movie*);
void sortByYears(Movie*);
void sortByRating(Movie*);
void updateAMovie(Movie*);
void removeAMovie(Movie*);
int compareStrings(char[ ], char[ ]);

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "myFavoriteMovies.9.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  Movie a, b, c;
  strcpy(a.title, "movie3");
  a.year = 0;
  a.rating = 0;
  strcpy(b.title, "movie2");
  b.year = 0;
  b.rating = 0;
  strcpy(c.title, "movie1");
  c.year = 0;
  c.rating = 0;
  
  Movie* firstMovie = 0;
  a.next = firstMovie;
  firstMovie = &a;
  b.next = firstMovie;
  firstMovie = &b;
  c.next = firstMovie;
  firstMovie = &c;
  
  while(true)
  {
    cout << "MENU\n";
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
}

void listMovies(Movie* firstMovie)
{
  cout << "Title             Viewed  Rating\n";
  cout << "----------------- ------  -------\n";
  for(Movie* p = firstMovie; p; p = p->next)
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
      if(compareStrings(p->title, q->title) > 0)
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

void updateAMovie(Movie* firstMovie)
{
  char buf[100];
  char changeThis[100];
  cout << "Enter a Movie's name to update: ";
  cin.getline(changeThis, 100);
  Movie* p;
  for(p = firstMovie; p; p = p->next)
    if (strcmp(p->title,changeThis) == 0)
      break;
  
  if(p)
  {
    cout << "Enter an updated name for " << changeThis << ": ";
    cin.getline(p->title, 100);
    cout << "Enter the year you saw " << p->title << " [like 2016]: ";
    cin >> buf;
    p->year = atoi(buf);
    cin.ignore(1000,10);
    cout << "Enter the rating for " << p->title << " [1, 2, X if not yet seen]: ";
    cin >> p->rating;
    cin.ignore(1000,10);
  }
  else
    cout << "Movie titled " << changeThis << " not found\n";
  cout << "\n";
}

void removeAMovie(Movie* firstMovie)
{
  char removeThis[100];
  cout << "Enter a Movie's name to remove: ";
  cin.getline(removeThis, 100);
  Movie* p;
  for(p = firstMovie; p; p = p->next)
    if (strcmp(p->title,removeThis) == 0)
      break;
  if(p)
  {
    strcpy(p->title, "gone");
    p->year = 0;
    p->rating = 0;
  }
  else
    cout << "Movie titled " << removeThis << " not found\n";
  cout << "\n";
}

int compareStrings(char a[], char b[])
{
  int result;
  for (int i = 0;; i++)
  {
    result = tolower(a[i]) - tolower(b[i]);
    if (result != 0 || a[i] == 0) break;
  }
  return result;
}