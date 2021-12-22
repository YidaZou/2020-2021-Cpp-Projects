#include <iostream>
#include <vector>
#include "AggiePatrons.h"

using namespace std;

// Function to print the contents of class members that return a vector
void printVector(vector<unsigned int> vec, string label = "") {
  cout << label << ": " << endl;
  for (unsigned int i=0; i<vec.size(); ++i) {
    cout << vec.at(i) << endl;
  }
}

int main() {
  AggiePatrons ap;
  ap.loadPatronData("data.txt");
  ap.print();
  cout<<ap.getAverageAttendanceForDay(4)<<endl; //return 1.5

  cout<<ap.getTotalAttendanceForPatron(2)<<endl; //return 3
  //cout<<ap.getTotalAttendanceForPatron(5)<<endl; //std::invalid_argument
  //cout<<ap.getTotalAttendanceForPatron(-1)<<endl; //std::invalid_argument

  cout<<"{";
  vector<unsigned int> test1 = ap.getActiveDays();
  for(unsigned int i=0; i<test1.size(); i++){
    cout<<test1[i]<<" ";
  }
  cout<<"}"<<endl;
  //returns {0 4 7 }

  cout<<"{";
  vector<unsigned int> test2 = ap.getMostActivePatrons();
  for(unsigned int i=0; i<test2.size(); i++){
    cout<<test2[i]<<" ";
  }
  cout<<"}"<<endl;
  //returns {0 3 }

  // add calls to test your functions
  // Note there is a print vector function that will print the contents
  //   of class members that return a vector.


}
