#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement

    // 0<=digit<=9
    if ((digit-'0'>9) || (digit-'0'<0)){
      throw std::invalid_argument("invalid digit");
    }
    int decimal = digit - '0';
    return decimal;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    if ((decimal>9)){
      throw std::invalid_argument("invalid decimal");
    }
    char digit = (char)(decimal+'0');
    return digit;
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    bool negative = false;
    //remove '-' sign
    if (num[0]=='-'){
      num.erase(0,1);
      negative = true;
    }
    //find the first index that doesn't contain a zero and erase eveything before
    num.erase(0, std::min(num.find_first_not_of('0'), num.size()-1));
    //print out "0" so that "-0" doesn't get printed
    if (num=="0"){
      return "0";
    }
    //add back '-' sign
    if (negative){
      num = "-" + num;
    }
    return num;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    int min, max;
    string sum = ""; //sum to output
    int digitSum; //sum of each digit
    int ten = 0; //if digitSum>9 carry over the 10
    string biggerNum; //the longer number of either lhs or rhs
    bool negative = false; //remember if the output is negative or positive
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    //erasing the '-' sign
    if(lhs[0]=='-'){
      lhs.erase(0,1);
      negative = true;
    }
    if(rhs[0]=='-'){
      rhs.erase(0,1);
      negative = true;
    }

    //finding the lengths of the numbers
    min = std::min(lhs.size(),rhs.size());
    max = std::max(lhs.size(),rhs.size());

    //finding the longer number
    if(lhs.size()>rhs.size()){
      biggerNum = lhs;
    }else{
      biggerNum = rhs;
    }

    //adding lhs + rhs
    for(int i=0; i<min; i++){
      //cout<<lhs[(rhs.size()-1)-i]<<" "<<rhs[(rhs.size()-1)-i];
      digitSum = ten + digit_to_decimal(lhs[(lhs.size()-1)-i]) + digit_to_decimal(rhs[(rhs.size()-1)-i]);
      ten = 0;
      if(digitSum>9){
        ten = 1;
        sum = decimal_to_digit(digitSum%10) + sum;
      }else{
        sum = decimal_to_digit(digitSum) + sum;
      }
    }

    //adding the remaining digits of the biggerNum to sum
    for(int i=min; i<max; i++){
      //cout<<biggerNum[(biggerNum.size()-1)-i];
      digitSum = ten + digit_to_decimal(biggerNum[(biggerNum.size()-1)-i]);
      ten = 0;
      if(digitSum>9){
        ten = 1;
        sum = decimal_to_digit(digitSum%10) + sum;
      }else{
        sum = decimal_to_digit(digitSum) + sum;
      }
    }

    //carry over the last 10
    if(ten>0){
      sum = "1" + sum;
    }

    //add back '-' sign
    if(negative){
      sum = "-" + sum;
    }

    return sum;
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
    string product = "0"; //product to output
    int digitProduct; //product of each digit
    string partialProduct; //to add together
    int ten = 0; //if digitSum>9 carry over the digit in the tens place
    string biggerNum; //the longer number of either lhs or rhs
    bool negative = false; //remember if the output is negative or positive
    string zeros = ""; //zeros to add to the right
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    //multiplying by 0
    if (lhs=="0" || rhs=="0"){
      return "0";
    }

    bool lhsNegative = false;
    bool rhsNegative = false;
    //erasing the '-' sign
    if(lhs[0]=='-'){
      lhs.erase(0,1);
      lhsNegative = true;
    }
    if(rhs[0]=='-'){
      rhs.erase(0,1);
      rhsNegative = true;
    }

    //deciding if product is negative or positive
    if (!((!lhsNegative && !rhsNegative) || (lhsNegative && rhsNegative))){
      negative = true;
    }

    int lhsSize = lhs.size();
    int rhsSize = rhs.size();

    //multiplying lhs * rhs
    for(int i=0; i<lhsSize; i++){
      for(int j=0; j<rhsSize; j++){
        digitProduct = ten + digit_to_decimal(lhs[(lhsSize-1)-i]) * digit_to_decimal(rhs[(rhsSize-1)-j]);
        ten = digitProduct/10;
        //cout<<"t "<<ten<<" dP "<<digitProduct<<endl;
        partialProduct = decimal_to_digit(digitProduct%10) + partialProduct;
      }
      if (ten>0){
        partialProduct = decimal_to_digit(ten) + partialProduct;  //adding final tens place
      }
      //cout<<"p "<<partialProduct<<" ten: "<<ten<<endl;
      product = add(product,partialProduct);
      zeros += "0";
      partialProduct = zeros;  //adding zeros to right side and resetting partialProduct
      ten = 0; //reset ten
    }



    //adding '-' sign if product is negative
    if(negative){
      product = "-" + product;
    }


    return product;
}
