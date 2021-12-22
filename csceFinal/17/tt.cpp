#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> t1 = {0,2};
  int t2[2] = {0,2};
  cout<<t1[0]<<endl;
  cout<<t1[1]<<endl;
  cout<<t2[0]<<endl;
  cout<<t2[1]<<endl;

  cout<<t1.at(7)<<endl;
  cout<<t2[7]<<endl;
}
