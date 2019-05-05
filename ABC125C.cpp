#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
typedef vector<ll> vll;

int N;
vll A;
ll left_cum[100001], right_cum[100001];

int main(){
  cin>>N;
  for (int i=0;i<N;++i){ll a;cin>>a;A.push_back(a);}

  left_cum[0]=A[0];right_cum[N-1]=A[N-1];
  for (int i=1;i<N;++i){
    left_cum[i]=__gcd(left_cum[i-1], A[i]);
    right_cum[N-i-1]=__gcd(right_cum[N-i], A[N-i-1]);
  }

  ll ans=max(left_cum[N-2], right_cum[1]);
  if(N==2){cout << ans << endl;return 0;}
  for (int i=1;i<N-1;++i){
    ll tmp=__gcd(left_cum[i-1], right_cum[i+1]);
    ans=max(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
