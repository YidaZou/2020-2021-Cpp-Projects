/******************************************************************************

File: ArraysHW.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section:
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track
event with 9 lanes. The code will sort the order, then display the results

Data File Information
name: data.csv
content: The csv file will contain data in the constant form of:
<Time (float)>,<Abbreviated Country (String)>,<Uniform number (int)>,<Lastname (String)>
32.7,USA,12,Moore
36.5,RUS,35,Polsley
45.8,ENG,73,Teale
52.34,CHN,14,Nemec
76.45,ITY,23,Lupoli

* max 2 decimals

*******************************************************************************/

#include "parallel_tracks.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument;

int main()
{
    // create arrays needed
		float timeArray[9];
		unsigned int rankArray[9];
		string countryArray[9];
		unsigned int numberArray[9];
		string lastnameArray[9];
		string fileName;
		bool validFile = false;
    // prep all arrays

	// prompt until both the file and the contained data are valid
	while(!validFile){
		try{
			cout<<"Enter file name: ";
			cin>>fileName;
			get_runner_data(fileName, timeArray, countryArray, numberArray, lastnameArray);
			validFile = true;
		}catch (invalid_argument& ia){
			cout << "Invalid File: " << ia.what()<< endl;
		}
	}

	// determine ranking, notice the rank array receives the results
	get_ranking(timeArray, rankArray);
	print_results(timeArray, countryArray, lastnameArray, rankArray);

    return 0;
}
