#include <iostream>

using namespace std;

int SIZE = 5;

void displayArray(int * array)
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << array[i] << endl;
	}
}

void displayArrayX2(int * array)
{

	for(int i = 0; i < SIZE*2; i++)
	{
		cout << array[i] << endl;
	}
}

void displayArrayCustom(int * array, unsigned int newSize)
{
	for(int i = 0; i < newSize; i++)
	{
		cout << array[i] << endl;
	}
}

void fillArray(int * array)
{

	for(int i = 0; i < SIZE; i++)
	{
		array[i] = -1;
	}
}

void resizeArray(int * array) // copy of the pointer
{
	//delete[] array;

	array = new int[SIZE * 2]; // this is where the pointer really changes

	for(int i = SIZE; i < SIZE * 2; i++)
	{
		array[i] = -2;
	}

}

void resizeArrayCorrect(int *&array)
{


	array = new int[SIZE * 2]; // this is where the pointer really changes

	for(int i = SIZE; i < SIZE * 2; i++)
	{
		array[i] = -2;
	}

}

void resizeArrayCustom(int *&array, unsigned int newSize)
{


	array = new int[newSize]; // this is where the pointer really changes

	for(int i = SIZE; i < newSize; i++)
	{
		array[i] = -3;
	}

}


// pointer reference *&array

// pointer *array

int main()
{

	int * testArray = new int[SIZE];

	cout << "displaying the array BEFORE values are placed" << endl;
	displayArray(testArray);

	fillArray(testArray);

	cout << "displaying the array AFTER values are placed" << endl;
	displayArray(testArray);


	resizeArray(testArray);

	cout << "displaying the array AFTER resizing the array and values are placed" << endl;
	displayArrayX2(testArray);

	resizeArrayCorrect(testArray);

	displayArrayX2(testArray);

	resizeArrayCustom(testArray, 100);

	displayArrayCustom(testArray, 100);



	delete [] testArray;

	return 0;
}
