#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;

ll add(ll x, ll y) {return (x+y)%MOD;}
ll mlt(ll x, ll y){return (x*y)%MOD;}

bool prohibited(int a, int b, int c, int d){
  if(      b==1&&c==2&&d==3) return true;
  if(a==1      &&c==2&&d==3) return true;
  if(a==1&&b==2      &&d==3) return true;
  if(      b==2&&c==1&&d==3) return true;
  if(      b==1&&c==3&&d==2) return true;
  return false;
}

int main(){
  int N;cin>>N;
  ll dp[N+10][4*4*4*4][2];
  memset(dp, 0, sizeof(dp));

  dp[0][0][0]=1;

  for (int i=1;i<=N;++i){
    for (int a=0;a<4;++a){
      for (int b=0;b<4;++b){
        for (int c=0;c<4;++c){
          for (int d=0;d<4;++d){
            int abcd=a*4*4*4+b*4*4+c*4+d;
            for (int e=0;e<4;++e){
              int bcde=b*4*4*4+c*4*4+d*4+e;
              if(prohibited(b,c,d,e)){
                dp[i][bcde][1]=add(dp[i][bcde][1], dp[i-1][abcd][0]);
                dp[i][bcde][1]=add(dp[i][bcde][1], dp[i-1][abcd][1]);
              }else{
                dp[i][bcde][0]=add(dp[i][bcde][0], dp[i-1][abcd][0]);
                dp[i][bcde][1]=add(dp[i][bcde][1], dp[i-1][abcd][1]);
              }
            }
          }
        }
      }
    }
  }

  ll ans=0;
  for (int i=0;i<256;++i){
    ans=add(ans, dp[N][i][0]);
  }

  cout << ans << endl;
  return 0;
}
