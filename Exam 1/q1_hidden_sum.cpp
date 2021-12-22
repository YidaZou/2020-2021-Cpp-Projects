#include <iostream>

using std::cout, std::cin, std::endl;

int sum(int num) {

  int sumE = 0;
  int digit;
  while (num>0){
    digit = num%10; //rightmost digit in num
    if(digit%2==0){
      sumE+=digit;
    }
    num/=10;
  }

  if(digit==4){    // if first digit in num is 4. Ex:466618983
    return 0;
  }
  return sumE;
}

int main () {
  int input;
  cin>>input;
  int out = sum(input);
  cout<<out<<endl;
  return 0;
}
