#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

ll n_layers(int n){
  if (n==0) return 1;
  return 2*n_layers(n-1)+3;
}

ll n_patties(int n){
  if (n==0) return 1;
  return 2*n_patties(n-1)+1;
}

ll runrun(int n, ll x){
  if(x<=0) return 0;
  if(n==0) return 1;
  if(x<=n_layers(n-1)+1) return runrun(n-1, x-1);
  if(x==n_layers(n-1)+2) return n_patties(n-1)+1;
  if(x<=n_layers(n)-1){
    return n_patties(n-1)+1+runrun(n-1, x-n_layers(n-1)-2);
  }
  return n_patties(n);
}

int main(){
  int N;cin>>N;ll X;cin>>X;
  ll ans=runrun(N, X);
  cout << ans << endl;
  return 0;
}
