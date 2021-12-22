#include <iostream>
#include <cmath>
using namespace std;

struct test{
  unsigned int test1;
  unsigned int test2;
  unsigned int final;
};

void displayTests(test * a, int s){
  for(int i=0;i<s;i++){
    cout<<a[i].test1<<endl;
    cout<<a[i].test2<<endl;
    cout<<a[i].final<<endl;
  }
}

int main(){
  test CSCE121_1[20];
  int SIZE = 20;
  test * CSCE121_2 = new test[SIZE];

  CSCE121_1[0].test1 = 78;
  cout <<CSCE121_1[0].test1 << endl;

  CSCE121_2[0].test1 = 78;
  CSCE121_2[0].test2 = 78;
  CSCE121_2[0].final = 78;
  displayTests(CSCE121_2, SIZE);

}
