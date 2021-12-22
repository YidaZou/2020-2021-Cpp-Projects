#include <iostream>

using std::cout, std::cin, std::endl, std::string;

string scrambleWord(string word);

int main() {
	string input;
  cin>>input;
  string out = scrambleWord(input);
  cout<<out<<endl;
	return 0;
}

string scrambleWord(string word) {
	char temp; //to help swap
	for(int i=2; i<word.size()-2; i+=2){
		temp = word[i];
		word[i] = word[i+1];
		word[i+1] = temp;
	}
	return word;
}
