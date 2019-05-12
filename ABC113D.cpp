#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll fib(int n){
  if (n<0) return 0;
  if (n==0||n==1) return 1;
  return (fib(n-1)+fib(n-2))%MOD;
}

int main(){
  int H, W, K;cin>>H>>W>>K;

  ll dp[H+1][W];
  memset(dp, 0, sizeof(dp));
  dp[0][0]=1;
  for (int y=1;y<=H;++y){
    for (int x=0;x<W;++x){
      (dp[y][x]+=fib(x-1)*fib(W-1-x)*dp[y-1][x-1])%=MOD;
      (dp[y][x]+=fib(x)*fib(W-1-x)*dp[y-1][x])%=MOD;
      (dp[y][x]+=fib(x)*fib(W-2-x)*dp[y-1][x+1])%=MOD;
    }
  }

  cout << dp[H][K-1] << endl;
  return 0;
}
