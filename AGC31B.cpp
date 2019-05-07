#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main(){
  int N;cin>>N;
  int C[200010];
  ll dp[200010];
  for (int i=0;i<N;++i){int c;cin>>c;C[i]=c;}
  ll cum[200010];
  memset(cum, 0, sizeof(cum));
  dp[0]=1;
  cum[C[0]]=1;

  if(N==1) {cout << 1 << endl;return 0;}

  for (int i=1;i<N;++i){
    if(C[i]!=C[i-1]) (cum[C[i]]+=dp[i-1])%=MOD;
    dp[i]=cum[C[i]];
  }

  cout << dp[N-1] << endl;
  return 0;
}
