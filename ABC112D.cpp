#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;cin>>N>>M;
  int ans=0;
  for (int i=1;i*i<=M;++i){
    if(M%i==0&&i<=M/N) ans=max(ans, i);
    if(M%i==0&&M/i<=M/N) ans=max(ans, M/i);
  }
  cout << ans << endl;
  return 0;
}
