#include <iostream>
#include <string>
using namespace std;
void prep_dynamic_array(int *x, const size_t size){
  for(int i=0; i<size; i++){
    x[i] = -1;
  }
}

void print_dynamic_array(const int * x, const size_t size){
  for(int i=0; i<size; i++){
    cout<<x[i]<<endl;
  }
}

int main(){
  int size;
  cin>>size;
  int * array = new int[size];
  prep_dynamic_array(array, size);
  print_dynamic_array(array, size);
}
