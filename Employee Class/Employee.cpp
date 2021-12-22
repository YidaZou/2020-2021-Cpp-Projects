// set name
void Employee::setName(const std::string newName) { name = newName; }

// sets department
void Employee::setDepartment(const std::string newDP){ department = newDP;}
// sets title
void Employee::setTitle(const std::string newTitle) { title = newTitle; }
// sets salary
void Employee::setSalary(const int newSalary) { salary = newSalary; }
// retrieves salary
std::string Employee::getName( ) 	{ return name; }
// retrieves department
std::string Employee::getDepartment( ) { return department; }
// retrieves title
std::string Employee::getTitle( ) { return title; }
// retrieves salary
int Employee::getSalary( ) { return salary; }
// tostd::string
std::string Employee::toString( )
{ return name + "\n" + department + "\n" + title + "\n" + std::to_string(salary);}

Employee::Employee(){
  name = "N/A";
  department = "N/A";
  title = "N/A";
  salary = -1;
}

const Employee & Employee::operator = (const Employee &source)
{
if(this == &source) // this is a self assignment checker
{ return *this; }	// returns the pointer to the current object
// otherwise copy

//new-instance now = source instance
name = source.name;
department = source.department;
title = source.title;
salary = source.salary;  // yes, a private data member

return *this; // returns previously empty instance

}

std::ostream &operator << (std::ostream &os, Employee &x)  // update .h file too
{
	os << x.getName() << std::endl;
	os << x.getDepartment() << std::endl;
	os << x.getTitle() << std::endl;
	os << x.getSalary() << std::endl;
	return os;
}
