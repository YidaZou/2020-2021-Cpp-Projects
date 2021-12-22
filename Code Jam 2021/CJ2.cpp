#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;


void solve() {
  int x, y, c=0;
  cin>>x>>y;

  string m;
  cin>>m;

  int l=0;
  for(int i=0;m[i]!='\0';i++)
    l++;
  char last='0';
  int i=0;
  while(i<l)
  {
    if(last=='J' && m[i]=='C')
        c+=y;
    if(last=='C' && m[i]=='J')
        c+=x;
    if(m[i]!='?')
        last=m[i];
    i++;
  }
  cout<<c<<endl;
}

int main(){
  int T;
  cin>>T;
  for(int t=1; t<=T; t++){
    cout<<"Case #"<< t <<": ";
    solve();
  }
  return 0;
}
