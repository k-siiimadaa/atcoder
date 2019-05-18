#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int main(){
  int N, M;cin>>N>>M;
  vll X, Y,Z;
  for (int i=0;i<N;++i){
    ll x, y, z;cin>>x>>y>>z;
    X.push_back(x);Y.push_back(y);Z.push_back(z);
  }
  ll ans=0;
  vi sgn={-1,1};
  for (int i=0;i<2;++i){
    for (int j=0;j<2;++j){
      for (int k=0;k<2;++k){
        vll S;
        for (int n=0;n<N;++n){
          S.push_back(X[n]*sgn[i]+Y[n]*sgn[j]+Z[n]*sgn[k]);
        }
        sort(S.begin(), S.end(), greater<ll>());
        ll tmp=0;
        for (int n=0;n<M;++n){
          tmp+=S[n];
        }
        ans=max(ans, tmp);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
