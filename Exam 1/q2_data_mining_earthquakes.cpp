#include <iostream>

using std::cout, std::cin, std::endl;

int main()
{
	int test[10] = { -12, 2, -2, 3, 5, -4, 78, -3, 19, 33};
	// the largest difference between values should be 82
	unsigned int answer = 0;

	// loop and compare
	int v1;
	int v2;
	int diff;
	int bigDiff=0;//biggest difference
	for (int i=1; i<8; i++)
	{
    diff=test[i+1]-test[i];
		if(diff<0){
			diff*=-1;
		}
		if(diff>bigDiff){
			bigDiff=diff;
		}



	}
	answer = bigDiff;
	cout<<answer<<" is the answer";

	return 0;
}
