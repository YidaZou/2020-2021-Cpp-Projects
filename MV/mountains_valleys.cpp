#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	// TODO(student): print prompt for input
	cout<<"Enter numbers 10 <= a <= b < 10000: ";
	// TODO(student): read the numbers from standard input
	int inputA;
	int inputB;
	cin>>inputA>>inputB;
	// TODO(student): validate input (and reprompt on invalid input)

	//takes input while is_valid_range is not true.
	while (!is_valid_range(inputA, inputB)){
		cout<<"Invalid Input"<<endl;
		cout<<"Enter numbers 10 <= a <= b < 10000: ";
		cin>>inputA>>inputB;
	};

	// TODO(student): compute and display solution
	count_valid_mv_numbers(inputA, inputB);
	return 0;
}
