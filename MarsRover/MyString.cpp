// TODO: Implement this source file
#include <iostream>
#include "MyString.h"
using std::cout, std::endl;
MyString::MyString():stringSize(0),stringCapacity(1),string{nullptr}{
}  //empty
MyString::MyString(const char * str):stringSize(0),stringCapacity(1),string(str){
  for(size_t i=0; str[i]!='\0'; i++){
    stringSize++;
    stringCapacity++;
  }
} //c-string

MyString::MyString(const MyString& orig):stringSize(orig.stringSize),stringCapacity(orig.stringCapacity),string(orig.string){
} //copy

MyString::~MyString(){
  delete string;
}

std::ostream& operator<< (std::ostream& os, const MyString& str){
  if(str.size()>0) {
    for(unsigned int i=0; i<str.size(); i++)
      os<<str.at(i);
  }else{
    os<<"";
  }
  return os;
}

MyString& MyString::operator= (const MyString& str){
  if(this == &str) return *this;

  stringSize = str.stringSize;
  stringCapacity = str.stringCapacity;
  string = str.string;
  return *this;
}

MyString& MyString::operator+= (const MyString& str){
  size_t newSize = stringSize + str.size();
  char * newStr = new char[newSize];
  for(size_t i=0;i<stringSize;i++){
    newStr[i]=string[i];
  }
  for(size_t j=0;j<str.size();j++){
    newStr[stringSize+j]=str.at(j);
  }
  //delete [] string;
  stringSize = newSize;
  stringCapacity = newSize;
  string = newStr;
  return *this;
}
