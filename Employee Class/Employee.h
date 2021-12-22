#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee
{
	friend std::ostream &operator << (std::ostream &os, Employee &x);
	private:
		std::string name = "N/A";
		std::string department = "N/A";
		std::string title = "N/A";
		int salary = -1;

	public:
		Employee();
		Employee(std::string n, std::string d, std::string t, int s)
		:name(n), department(d), title(t), salary(s){}

		// mutators
		void setName(const std::string newName); // set name
		void setDepartment(const std::string newDP); // sets department
		void setTitle(const std::string newTitle);  // sets title
		void setSalary(const int newSalary);  // sets salary

		// accessors
		std::string getName( ); // retrieves salary
		std::string getDepartment( ); // retrieves department
		std::string getTitle( ); // retrieves title
		int getSalary( ); // retrieves salary

		// tostd::string
		std::string toString( );
		const Employee &operator = (const Employee &source);

};
#endif /* EMPLOYEE_H_ */
