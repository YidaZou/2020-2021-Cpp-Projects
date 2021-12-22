#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if (10<=a && a<=b && b<10000){
		return true;
	}
	return false;
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise

	//Find number of digits in number
	int num = number;
	int d = 0; //number of digits in number
	while(num>0){
		num/=10;
		d++;
	}

	//last two digits
	int n1 = number%10;
	int n2 = number/10%10;

	num = number/10;	//reset num
	int n = d; //set number of digits to n

		//Check Mountain
		while (n > 1){
			if(n%2 != 0 && !(n2>n1)){
					break;
			}else if(n%2 == 0 && !(n2<n1)){
					break;
			}
			n--;
			n1 = n2;
			num/=10;
			n2 = num%10;
		}
		if (!(n > 1)){
			return 'M';
		}

		num = number/10;	//reset num
		n = d; //reset n
		//reset n1 and n2
		n1 = number%10;
		n2 = number/10%10;
		//Check Valley
		while (n > 1){
			if(n%2 != 0 && !(n2<n1)){
					break;
			}else if(n%2 == 0 && !(n2>n1)){
					break;
			}
			n--;
			n1 = n2;
			num/=10;
			n2 = num%10;
		}
		if (!(n > 1)){
			return 'V';
		}
	return 'N';
/*
//Old code that only worked with numbers with 4 digits or less

	//Checks 3 digit numbers first
	if (d1==0 && d2!=0){
		if ((d2<d3) && (d3>d4)){
			return 'M';
		}else if ((d2>d3) && (d3<d4)){
			return 'V';
		}
	}else{
		//Checks 4 or 2 digit numbers
		if ((d1==0 || d1<d2) && (d2==0 || d2>d3) && (d3<d4)){
			return 'M';
		}else if ((d1==0 || d1>d2) && (d2==0 || d2<d3) && (d3>d4)){
			return 'V';
		}
	}
	return 'N';
*/
}



void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	int numValleys = 0;
	int numMountains = 0;

	for(int i=a; i<=b; i++){
		if (classify_mv_range_type(i)=='V'){
			numValleys++;
		}else if (classify_mv_range_type(i)=='M'){
			numMountains++;
		};
	}
	cout<<"There are "<< numMountains <<" mountain ranges and "<< numValleys <<" valley ranges between "<< a <<" and "<< b <<"."<<endl;
}
