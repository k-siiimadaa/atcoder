#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e14;

int main(){
  int N;cin>>N;
  vll A;
  for (int i=0;i<N;++i){
    ll a;cin>>a;A.push_back(a);
  }
  vll cum(N+1);cum[0]=0;
  for (int i=0;i<N;++i){
    cum[i+1]=cum[i]+A[i];
  }

  ll ans=INF;

  for (int mid=2;mid<N-1;++mid){
    int n=lower_bound(cum.begin(), cum.end(), cum[mid]/2)-cum.begin();
    int m=lower_bound(cum.begin(), cum.end(), (cum[N]-cum[mid])/2)-cum.begin();
    ll P=cum[n], Q=cum[mid]-cum[n], R=cum[m]-cum[mid], S=cum[N]-cum[m];
    if(P-Q>cum[mid]-2*cum[n-1]){P=cum[n-1]; Q=cum[mid]-cum[n-1];}
    if(R-S>cum[N]-2*cum[m-1]+cum[mid]){R=cum[m-1]-cum[mid]; S=cum[N]-cum[m-1];}
    ll ma=max(max(P, Q), max(R,S)), mi=min(min(P,Q), min(R, S));
    if(n>0){
      ll P_=cum[n-1], Q_=cum[mid]-cum[n-1];
    }
    ans=min(ma-mi, ans);
  }

  cout << ans << endl;
  return 0;
}
