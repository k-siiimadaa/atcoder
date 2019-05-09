#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll single(ll X){
  if(X&1) return ((X+1)/2)&1;
  else return ((X/2)&1)^X;
}

int main(){
  ll A, B;cin>>A>>B;
  ll ans;
  if(A==0){ans=single(B);}else{
    ans=single(A-1)^single(B);
  }
  cout << ans << endl;
  return 0;
}
