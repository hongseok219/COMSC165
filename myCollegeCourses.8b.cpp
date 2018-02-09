// identification
// Hongseok Jang
// Lab 8, myCollegeCourses.8b.cpp
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
using std::min;

#include <fstream>
using std::fstream;

struct Course
{
  char name[10];
  int year;
  int units;
  char grade;
};

void listCourses(Course*, int);
void sortByYears(Course*, int);
void sortByUnits(Course*, int);
void sortByGrade(Course*, int);
void sortByname(Course*, int);
void changeArrayCapacity(Course**, int*, int);
void addACourse(Course**, int*, int*);
void toUpperCase(char[]);

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "myCollegeCourses.8b.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  Course* c = new Course[2];
  int count = 0;
  int cap = 2;
  
  fstream fin;
  fin.open("myCollegeCourses.8b.dat", ios::binary|ios::in);
  if (fin.good())
  {
    fin.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (count >= cap)
      changeArrayCapacity(&c,&cap,count);
    fin.read(reinterpret_cast<char*>(c), count*sizeof(Course));
  }
  fin.close();

  while(true)
  {
    cout << "MENU\n";
    cout << "A add a course\n";
    cout << "L list all courses\n";
    cout << "C arrange by course\n";
    cout << "Y arrange by year\n";
    cout << "U arrange by units\n";
    cout << "G arrange by grade\n";
    cout << "Q quit\n";
    
    cout << "...your choice: ";
    char userinput;
    cin >> userinput;
    cin.ignore(1000,10);
    cout << "\n";
    
    if (toupper(userinput) == 'Q')
      break;
    else if (toupper(userinput) == 'L')
      listCourses(c, count);
    else if (toupper(userinput) == 'Y')
      sortByYears(c, count);
    else if (toupper(userinput) == 'U')
      sortByUnits(c, count);
    else if (toupper(userinput) == 'G')
      sortByGrade(c, count);
    else if (toupper(userinput) == 'C')
      sortByname(c, count);
    else if (toupper(userinput) == 'A')
      addACourse(&c, &cap, &count);
  }

  fstream fout;
  fout.open("myCollegeCourses.8b.dat", ios::binary|ios::out);
  fout.write(reinterpret_cast<char*>(&count), sizeof(int));
  fout.write(reinterpret_cast<char*>(c), count*sizeof(Course));
  fout.close();
}

void listCourses(Course* c, int n)
{
  cout << "Course        Year  Units  Grade\n";
  cout << "------------  ----  -----  -----\n";
  for(int i = 0; i < n; i++)
  {
    cout.setf(ios::left); cout.width(12); cout << c[i].name;
    cout.unsetf(ios::left); cout.width(6); cout << c[i].year;
    cout.width(5); cout << c[i].units;
    cout.width(7); cout << c[i].grade;
    cout <<"\n";
  }
  cout << "\n";
}

void sortByYears(Course* c, int count)
{
  for(int i = 0; i < count; i++)
    for(int j = i + 1; j < count; j++)
      if(c[i].year > c[j].year)
        swap(c[i],c[j]);
}

void sortByUnits(Course* c, int count)
{
  for(int i = 0; i < count; i++)
    for(int j = i + 1; j < count; j++)
      if(c[i].units > c[j].units)
        swap(c[i],c[j]);
}

void sortByGrade(Course* c, int count)
{
  for(int i = 0; i < count; i++)
    for(int j = i + 1; j < count; j++)
      if(c[i].grade > c[j].grade)
        swap(c[i],c[j]);
}

void sortByname(Course* c, int count)
{
  for(int i = 0; i < count; i++)
    for(int j = i + 1; j < count; j++)
      if(strcmp(c[i].name,c[j].name) > 0)
        swap(c[i],c[j]);
}

void changeArrayCapacity(Course** array, int* capacity, int newCapacity)
{
  Course* temp = new Course[newCapacity];
  int smallerOfTheTwo = min(*capacity, newCapacity);
  for (int i = 0; i < smallerOfTheTwo; i++)
    temp[i] = (*array)[i];
  delete [ ] *array;
  *array = temp;
  *capacity = newCapacity;
}

void addACourse(Course** c, int* cap, int* count)
{
  if(*count == *cap)
    changeArrayCapacity(c, cap, 2**cap);
  cout << "Enter a courses' name: ";
  char buf[100];
  cin >> (*c)[*count].name;
  toUpperCase((*c)[*count].name);
  cout << "Enter the year for " << (*c)[*count].name << " [like 2016]: ";
  cin >> buf;
  (*c)[*count].year = atoi(buf);
  cout << "Enter the units for " << (*c)[*count].name << " [[0, 1, 2,...]: ";
  cin >> buf;
  (*c)[*count].units = atoi(buf);
  cout << "Enter the grade for " << (*c)[*count].name << " [A, B,..., X if still in progress or planned]: ";
  cin >> (*c)[*count].grade;
  (*c)[*count].grade = toupper((*c)[*count].grade);
  (*count)++;
  cout << "\n";
}

void toUpperCase(char aCString[])
{
  for (int i = 0; aCString[i] != 0; i++)
    aCString[i] = toupper(aCString[i]);
}
