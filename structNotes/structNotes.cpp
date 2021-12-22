#include <iostream>
#include <string>
using namespace std;

// global variable
const int SIZE = 10;

struct DATE
{
	int month;
	int day;
	int year;
};

ostream &operator << (ostream &os, const DATE &x) //remember x is an alias
{
	os << x.month << "-" << x.day << "-" << x.year << endl;
	// so it will display the date as 11-11-1111
	return os;

// x is the temporary name of the struct when it is passed into this function
}

// prototype
float average(int grade1, int grade2);

int main()
{
	DATE y; // y is empty so far      INSTANCE!!
	y.month = 12;
	y.day = 25;
	y.year = 2001;

	DATE Lupoli = { 12, 30, 1970 }; // ORDER DOES MATTER!!! INSTANCE!!
	DATE Ryan = { 06, 11, 1984 }; // INSTANCE!!
	DATE Yida = {01, 12, 2002};

	cout << Ryan.month << endl;
  cout << Ryan.day << endl;
  cout << Ryan.year << endl;

	cout << Yida.month << endl;
  cout << Yida.day << endl;
  cout << Yida.year << endl;

	cout<<Ryan;
	cout<<Lupoli;
	return 0;
}
