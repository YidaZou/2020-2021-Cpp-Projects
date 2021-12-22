// set name
void Employee::setName(const string newName) { name = newName; }

// sets department
void Employee::setDepartment(const string newDP){ department = newDP;}
// sets title
void Employee::setTitle(const string newTitle) { title = newTitle; }
// sets salary
void Employee::setSalary(const int newSalary) { salary = newSalary; }
// retrieves salary
string Employee::getName( ) 	{ return name; }
// retrieves department
string Employee::getDepartment( ) { return department; }
// retrieves title
string Employee::getTitle( ) { return title; }
// retrieves salary
int Employee::getSalary( ) { return salary; }
// tostring
string Employee::tostring( )
{ return name + "\n" + department + "\n" + title + "\n" + to_string(salary);}
