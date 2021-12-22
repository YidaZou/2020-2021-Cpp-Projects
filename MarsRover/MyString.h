// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <fstream>
using std::cout, std::endl;
class MyString {
	private:
		size_t stringSize;
    size_t stringCapacity;
		const char * string;
	public:
		// constructors
		MyString();  //empty
    MyString(const char * str); //c-string
    MyString(const MyString& orig); //copy
    ~MyString();

    //getters
    size_t size() const{return stringSize;}
    size_t length() const{return stringSize;}
    size_t capacity() const{return stringCapacity;}
    const char& at(size_t i) const {
			if(i>stringSize){
				throw std::out_of_range("!index is out of bounds");
			}
			return string[i];
		}
    const char* data() const {return string;}
    bool empty() const{return (stringSize==0);}
    const char& front() const {return string[0];}

    //setters
    void resize(size_t n){
      stringSize =n;
      stringCapacity =n;
    }
    void clear(){
			stringSize = 0;
      string= new char[0];
    }
    friend std::ostream& operator<< (std::ostream& os, const MyString& str);

    MyString& operator= (const MyString& str);

    MyString& operator+= (const MyString& str);

		size_t find(const MyString& str, size_t pos = 0) const noexcept{
			size_t sub=0;
			for(size_t i=pos; i<stringSize; i++){
				if(string[i]==str.at(i)){
					sub=0;
					for(size_t j=i; j<str.size(); j++){
						if(string[j]==str.at(j)){
							sub++;
						}else{
							break;
						}
					}
					if(sub==str.size()){
						return i;
					}
				}
			}
			return -1;
		}
};

#endif
