#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;


void solve() {
  int x , y;
  cin>>x;
  cin>>y;
  string s,sM, cjs, cjsM;
  cin>>sM;
  int qCount=0;
  for(int i=0; sM[i] !='\0'; i++){
    if(sM[i]=='?'){
      qCount++;
    }
  }
  int qI;
  int xC=0;
  int yC=0;
  int price;
  int min = INT_MAX;
  if(qCount==0){
    s=sM;
    size_t nPos1 = s.find("CJ", 0);
    while(nPos1 != string::npos)
    {
        xC++;
        nPos1 = s.find("CJ", nPos1 + 1);
    }
    size_t nPos2 = s.find("JC", 0);
    while(nPos2 != string::npos)
    {
        yC++;
        nPos2 = s.find("JC", nPos2 + 1);
    }
    //price
    price = xC*x+yC*y;
    //cout<<"!!"<<xC<<"--"<<yC<<"::"<<price<<endl;
    if(price<min){
      min = price;
    }
  }else{
    for(int p=0; p<qCount; p++){
      cjsM.push_back('C');
      for(int a=0; a<p; a++){
        cjsM.push_back('J');
      }
        do{
          cjs= cjsM;
          s = sM;
          //mural
            for(int j=0; j<qCount; j++){
              qI = s.find('?');
              string t(1,cjs[j]);
              s.replace(qI,1,t);
            }
          size_t nPos1 = s.find("CJ", 0);
          while(nPos1 != string::npos)
          {
              xC++;
              nPos1 = s.find("CJ", nPos1 + 1);
          }
          size_t nPos2 = s.find("JC", 0);
          while(nPos2 != string::npos)
          {
              yC++;
              nPos2 = s.find("JC", nPos2 + 1);
          }
          //price
          price = xC*x+yC*y;
          //cout<<"!!"<<xC<<"--"<<yC<<"::"<<price<<endl;
          if(price<min){
            min = price;
          }

        }
        while(next_permutation(begin(cjsM),end(cjsM)));
        if(min<1){
          break;
        }
    }
  }
  cout<<min<<endl;
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
