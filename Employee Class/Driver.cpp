#include <iostream>
#include <string>

// rest of your normal includes

#include "Employee.h"
#include "Employee.cpp"

int main()
{
	/*
	Employee EM001;
	EM001.setName("Prof. Lupoli");
	EM001.setDepartment("Computer Science");
	EM001.setTitle("Lecturer");
	EM001.setSalary(-1);
	std::cout << EM001.toString(); // uses tostring method in class

	Employee EM002;
	EM001.setName("Yida");
	EM001.setDepartment("Computer Science");
	EM001.setTitle("Student");
	EM001.setSalary(-1);
	std::cout << EM001.toString();

	Employee EM003;
	EM001.setName("Yida Clone");
	EM001.setDepartment("Computer Science");
	EM001.setTitle("Student");
	EM001.setSalary(-1);
	std::cout << EM001.toString();
	*/
	Employee Test1;
	Test1.setName("Prof. Lupoli");
	Test1.setDepartment("Computer Science");
	Test1.setTitle("Lecturer");
	Test1.setSalary(-1);

	Employee Test2;
	Test2=Test1;

	std::cout<<Test2<<std::endl;

	Employee * Martino = new Employee("Martino","Science","Student",0);
	std::cout<< *Martino;


	return 0;
}
