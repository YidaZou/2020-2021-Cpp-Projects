//
//  Driver.cpp
//  Driver
//
//  Created by Yida Zou on 29/03/2021.
//
//

#include <iostream>
#include <string>
using namespace std;

#include "Employee.h"
#include "Employee.cpp"

int main()
{
  Employee EM001;
  EM001.setName("Mr. Lupoli");
  EM001.setDepartment("Computer Science");
  EM001.setTitle("Lecturer");
  EM001.setSalary(-1);
  cout << EM001.tostring();




   return 0;
}
