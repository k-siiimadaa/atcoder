#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll divisors(ll n){
  vll res;
  for (ll i=1;i*i<=n;++i){
    if(n%i==0){
      res.push_back(i);
      if(n/i!=i) res.push_back(n/i);
    }
  }
  return res;
}

int main(){
  ll N;cin>>N;
  vll res=divisors(N);
  ll ans=0;
  int M=res.size();
  for (int i=0;i<M;++i){
    if(N/res[i]<res[i]-1) ans+=res[i]-1;
  }
  cout << ans << endl;
  return 0;
}
