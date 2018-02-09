// identification
// Hongseok Jang
// Lab 5, studentObjects.5.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <iostream>
using std::cout;
using std::ios;

#include <cstdlib>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::getline;
using std::string;

struct Student
{
  string name;
  int age;
  double gpa;
  char gender;
  string city;
};

void outputTableHeading();
void outputStudent(int, Student);
Student getStudent();

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "studentObjects.5.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  Student one = getStudent();
  Student two = getStudent();
  Student three = getStudent();
  cout << endl;
  outputTableHeading();
  outputStudent(1, one);
  outputStudent(2, two);
  outputStudent(3, three);
  cout << endl;
}

void outputTableHeading()
{
  cout << "# Name           Age  GPA  gender city\n";
  cout << "- -------------  ---  ---- ------ -----------------\n";
}

void outputStudent(int sequenceNumber, Student anyStudent)
{
  cout << sequenceNumber << ' ';
  cout.setf(ios::left); cout.width(12); cout << anyStudent.name;
  cout.unsetf(ios::left); cout.width(6); cout << anyStudent.age;
  cout.width(6); cout << anyStudent.gpa;
  cout.width(7); cout << anyStudent.gender;
  cout.width(18); cout << anyStudent.city << endl;
}

Student getStudent()
{
  Student result;
  cout << "Enter the name: ";
  getline(cin, result.name);
  
  string buf;
  cout << "And what's " << result.name << "'s age? ";
  cin >> buf; result.age = atoi(buf.c_str());
  cin.ignore(1000, 10);
  
  cout << "And now " << result.name << "'s grade point average: ";
  cin >> buf; result.gpa = atof(buf.c_str());
  cin.ignore(1000, 10);
  
  cout << "And what's " << result.name << "'s gender?(Man:M, Female:F) ";
  cin >> result.gender;
  cin.ignore(1000, 10);
  
  cout << "Where is the city "<< result.name << " lives?: ";
  getline(cin, result.city);
  return result;
}
