// identification
// Hongseok Jang
// Lab 11, myCourseHistory.11a.cpp
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

struct Course
{
  string name;
  char grade;
  int year;
  int unit;
  Course* next;
};

void serializeUp(Course*&, Course*&);
void serializeDown(Course*);
void deallocateCourses(Course*&, Course*&);
void listCourses(Course*);
void AddACourse(Course*&, Course*&);
void removeACourse(Course*&, Course*&);
string toUpperCase(string);
int compareCourses(Course*, Course*);

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "myCourseHistory.11a.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  Course* firstCourse = 0, *lastCourse = 0;
  serializeUp(firstCourse, lastCourse);
  
  while(true)
  {
    cout << "MENU\n";
    cout << "A Add a Course\n";
    cout << "R Remove a Course\n";
    cout << "L list all Courses\n";
    cout << "X exit\n";
    cout << "...your choice: ";
    
    char userinput;
    cin >> userinput;
    cin.ignore(1000,10);
    cout << "\n";
    
    if (toupper(userinput) == 'X')
      break;
    else if (toupper(userinput) == 'A')
      AddACourse(firstCourse, lastCourse);
    else if (toupper(userinput) == 'L')
      listCourses(firstCourse);
    else if (toupper(userinput) == 'R')
      removeACourse(firstCourse, lastCourse);
  }
  
  serializeDown(firstCourse);
  deallocateCourses(firstCourse, lastCourse);
}

void serializeUp(Course*& head, Course*& tail)
{
  ifstream fin;
  fin.open("myCourseHistory.11a.txt");
  if (!fin.good()) return;
  
  while (true)
  {
    string buf;
    getline(fin, buf);
    if (buf == "EOF") break;
    
    Course* temp = new Course;
    temp->name = buf;
    fin >> temp->grade;
    fin.ignore(1000, 10);
    fin >> temp->year;
    fin.ignore(1000, 10);
    fin >> temp->unit;
    fin.ignore(1000, 10);
    
    Course* p, *prev;
    for (p = head, prev = 0; p; prev = p, p = p->next)
      if (compareCourses(temp, p) < 0) break;
    temp->next = p;
    if(prev) prev->next = temp;
    else head = temp;
    if (p == 0) tail = temp;
  }
  fin.close();
}

void serializeDown(Course* head)
{
  ofstream fout;
  fout.open("myCourseHistory.11a.txt");
  
  for (Course* p = head; p; p = p->next)
  {
    fout << p->name << "\n";
    fout << p->grade << "\n";
    fout << p->year << "\n";
    fout << p->unit << "\n";
  }
  fout << "EOF\n";
  fout.close();
}

void listCourses(Course* firstCourse)
{
  cout << "Name       Grade Year Unit\n";
  cout << "---------- ----- ---- ----\n";
  int n = 1;
  for(Course* p = firstCourse; p; p = p->next, n++)
  {
    cout.setf(ios::left); cout.width(10); cout << p->name;
    cout.unsetf(ios::left); cout.width(4); cout << p->grade;
    cout.width(7); cout << p->year;
    cout.width(4); cout << p->unit;
    cout <<"\n";
  }
  cout << "\n";
}

void AddACourse(Course*& head, Course*& tail)
{
  Course* temp = new Course;
  
  cout << "Enter a Course's name: ";
  getline(cin, temp->name);
  temp->name = toUpperCase(temp->name);
  cout << "Enter the grade you get " << temp->name << " [like A,B,C,D,F,X(in-progress or planned)]: ";
  cin >> temp->grade;
  temp->grade = toupper(temp->grade);
  cin.ignore(1000,10);
  cout << "Enter the year you take " << temp->name << " [like 2016]: ";
  string buf;
  cin >> buf;
  temp->year = atoi(buf.c_str());
  cin.ignore(1000,10);
  cout << "Enter the unit for " << temp->name << " [1, 2, 3, 4, 5]: ";
  cin >> buf;
  temp->unit = atoi(buf.c_str());
  cin.ignore(1000,10);
  cout << "\n";
  
  Course* p, *prev;
  for (p = head, prev = 0; p; prev = p, p = p->next)
    if (compareCourses(temp, p) < 0) break;
  temp->next = p;
  if (prev) prev->next = temp;
  else head = temp;
  if (p == 0) tail = temp;
}

void removeACourse(Course*& firstCourse, Course*& tail)
{
  int n = 0;
  Course* p, *prev;
  for(p = firstCourse; p; p = p->next, n++);
  cout << "Which one to remove(1-" << n << ")?: ";
  string buf;
  cin >> buf;
  n = atoi(buf.c_str());
  cin.ignore(1000,10);
  int i = 1;
  for(p = firstCourse, prev = 0; p && i != n; prev = p, p = p->next, i++);
  if(p)
  {
    if (prev) prev->next = p->next;
    else firstCourse = firstCourse->next;
    delete p;
  }
  else
    cout << "Course numbered " << n << " not found\n";
  cout << "\n";
}

string toUpperCase(string aCppString)
{
  int n = aCppString.length();
  for (int i = 0; i < n; i++)
    aCppString[i] = toupper(aCppString[i]);
  return aCppString;
}

void deallocateCourses(Course*& head, Course*& tail)
{
  while (head)
  {
    Course* p = head;
    head = head->next;
    delete p;
  }
  tail = 0;
}

int compareCourses(Course* a, Course* b)
{
  if (a->year < b->year) return 1;
  if (a->year > b->year) return -1;
  if (toUpperCase(a->name) < toUpperCase(b->name)) return -1;
  if (toUpperCase(a->name) > toUpperCase(b->name)) return 1;
  return 0;
}
