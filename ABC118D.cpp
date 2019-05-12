#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

map<int, int> n_mat={{1,2}, {2,5}, {3,5}, {4,4}, {5,5}, {6,6},{7,3},{8,7},{9,6}};

int main(){
  int N, M;cin>>N>>M;
  vi A;
  for (int i=0;i<M;++i){int a;cin>>a;A.push_back(a);}

  vi u(10,-1);
  for (int i=2;i<=7;++i){
    for(int m=0;m<M;++m){
      if(n_mat[A[m]]==i) u[i]=max(u[i], A[m]);
    }
  }

  vvi dp(N+10, vi(10, -1));
  dp[0]=vi(10,0);

  for (int i=0;i<=N;++i){
    for (int j=2;j<=7;++j){
      if(u[j]==-1) continue;
      int p=10-u[j];
      dp[i][p]++;dp[i][0]++;
      dp[i+j]=max(dp[i], dp[i+j]);
      dp[i][p]--;dp[i][0]--;
    }
  }

  for (int i=1;i<10;++i){
    for (int j=0;j<dp[N][i];++j){cout << 10-i;}
  }
  return 0;
}
