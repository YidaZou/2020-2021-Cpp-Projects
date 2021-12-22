#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
string name = "N/A";
string department= "N/A";
string title= "N/A";
int salary= -1;

public:
// mutators
void setName(const string newName); // set name
void setDepartment(const string newDP); // sets department
void setTitle(const string newTitle);  // sets title
void setSalary(const int newSalary);  // sets salary

// accessors
string getName( ); // retrieves salary
string getDepartment( ); // retrieves department
string getTitle( ); // retrieves title
int getSalary( ); // retrieves salary

// tostring
string tostring( );
};


#endif
