// identification
// Hongseok Jang
// Lab 6, myCollegeCourses.6.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Terminal

#include <iostream>
using std::cout;
using std::ios;

#include <cstdlib>

#include <iostream>
using std::cin;
using std::cout;
using std::ios;

#include <string>
using std::getline;
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

struct Course
{
  string name;
  int year;
  int units;
  char grade;
};

void coutAllCourses(Course[], int);
Course cinOneCourse(int);
int serializeUp(Course[]);
void serializeDown(Course[], int);

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "myCollegeCourses.6.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Terminal\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  const int CAPACITY = 100;
  Course course[CAPACITY];
  int size = serializeUp(course);
  for(; size < CAPACITY; size++)
  {
    coutAllCourses(course, size);
    course[size] = cinOneCourse(size);
    if (course[size].name == "Q" || course[size].name == "q")
      break;
  }
  serializeDown(course, size);

}
  
  void coutAllCourses(Course course[], int size)
  {
    cout << "Course      Year Units Grade\n";
    cout << "----------- ---- ----- -----\n"; 
    for(int i = 0; i < size; i++)
    {
      cout.setf(ios::left); cout.width(10); cout << course[i].name;
      cout.unsetf(ios::left); cout.width(6); cout << course[i].year;
      cout.width(4); cout << course[i].units;
      cout.width(6); cout << course[i].grade << "\n";
    }
    cout << "\n";
  }
  
  Course cinOneCourse(int size)
  {
    Course result;
    cout << "Enter course #" << size + 1 << " [Q to exit]: ";
    getline(cin, result.name);
    
    if (result.name != "Q" && result.name != "q")
    {
      string buf;
      cout << "What year for " << result.name << "? [e.g., 2016]: ";
      cin >> buf; result.year = atoi(buf.c_str());
      cin.ignore(1000, 10);
      
      cout << "How many units is " << result.name << "? ";
      cin >> buf; result.units = atoi(buf.c_str());
      cin.ignore(1000, 10);
      
      cout << "And what was your grade [X for in-progress or planned]: ";
      cin >> result.grade;
      cin.ignore(1000, 10);
      cout << "\n";
    }
    return result;
  }
  
  int serializeUp(Course course[])
  {
    int size = 0;
    ifstream fin;
    fin.open("myCollegeCourses.6.txt");
    if (fin.good())
    {
      for (int i = 0; fin.good(); i++)
      {
        string buf;
        getline(fin, buf);
        if (buf == "EOF") break;
        
        course[size].name = buf;
        fin >> course[size].year;
        fin.ignore(1000, 10);
        fin >> course[size].units;
        fin.ignore(1000, 10);
        fin >> course[size].grade;
        fin.ignore(1000, 10);
        ++size;
      }
      fin.close();
    }
    return size;
  }
  
  void serializeDown(Course course[], int size)
  {
    ofstream fout;
    fout.open("myCollegeCourses.6.txt");
    for(int i = 0; i < size; i++)
    {
      fout << course[i].name << "\n";
      fout << course[i].year << "\n";
      fout << course[i].units << "\n";
      fout << course[i].grade << "\n";
    }
    fout << "EOF" << "\n";
    fout.close();
  }
  
