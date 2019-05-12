#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int main(){
  int N,K;cin>>N>>K;
  map<int, vll> sushi_list;

  for (int i=0;i<N;++i){
    int t;cin>>t;ll d;cin>>d;
    sushi_list[t].push_back(d);
  }

  vll winner, loser;

  for (auto p: sushi_list){
    vll q=p.second;
    sort(q.begin(), q.end(), greater<ll>());

    int M=q.size();
    winner.push_back(q[0]);
    if(M>1){
      for (int i=1;i<M;++i) loser.push_back(q[i]);
    }
  }

  sort(winner.begin(), winner.end(), greater<ll>());
  sort(loser.begin(), loser.end(), greater<ll>());

  int W=winner.size(), L=loser.size();

  vll w_cum(W+1), l_cum(L+1);w_cum[0]=0, l_cum[0]=0;
  for (int i=0;i<W;++i){w_cum[i+1]=w_cum[i]+winner[i];}
  for (int i=0;i<L;++i){l_cum[i+1]=l_cum[i]+loser[i];}

  ll ans=0;
  int K_=min(K, W);
  for (int x=1;x<=K_;++x){
    if(K-x<=L){
      ll tmp=(ll)x*x+w_cum[x]+l_cum[K-x];
      ans=max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
