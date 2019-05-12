#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main(){
  int N;cin>>N;
  map<int, int> counter;
  for (int i=2;i<=N;++i){
    int j=i;
    for (int m=0;m<25;++m){
      int p=primes[m];
      while(j%p==0){
        counter[p]++;
        j/=p;
      }
    }
  }

  int C74=0, C24=0, C14=0, C4=0, C2=0;

  for (auto p: counter){
    if(p.second>=74) C74++;
    if(p.second>=24) C24++;
    if(p.second>=14) C14++;
    if(p.second>=4) C4++;
    if(p.second>=2) C2++;
  }


  int ans=0;
  ans+=C74;
  ans+=C24*(C2-1);
  ans+=C14*(C4-1);
  ans+=C4*(C4-1)*(C2-2)/2;
  cout << ans << endl;
  return 0;
}
