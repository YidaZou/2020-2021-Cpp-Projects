#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    cout << ">> "<<endl;
    string input;
    int op = 0; //find the index of the operator
    getline(cin,input);
    while (input!="q" && input!="quit"){
      op = input.find('+');
      if(op > 0){
        cout<<"ans ="<<endl;
        cout<<endl;
        cout<<"    "<<add(input.substr(0,op-1),input.substr(op+2,input.size()-op-2))<<endl;
        cout<<endl;
        cout << ">> "<<endl;
      }
      op = 0; //reset index
      op = input.find('*');
      if(op > 0){
        cout<<"ans ="<<endl;
        cout<<endl;
        cout<<"    "<<multiply(input.substr(0,op-1),input.substr(op+2,input.size()-op-2))<<endl;
        cout<<endl;
        cout << ">> "<<endl;
      }
      op = 0; //reset index
      getline(cin,input);
    }
    cout<<"farvel!"<<endl;
    cout<<endl;
    return 0;

    // TODO(student): implement the UI
}
