#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int dy[4]={-1,0,1,0}, dx[4]={0,-1,0,1};

int main(){
  int H,W;cin>>H>>W;
  char A[H][W];
  queue<ii> que;
  int dist[H][W];
  for (int i=0;i<H;++i){
    for (int j=0;j<W;++j){
      dist[i][j]=2001;
    }
  }

  for (int i=0;i<H;++i){
    for (int j=0;j<W;++j){
      cin>>A[i][j];
      if(A[i][j]=='#') {que.push({i,j});dist[i][j]=0;}
    }
  }

  while(!que.empty()){
    ii p=que.front();que.pop();
    int y=p.first, x=p.second;
    for (int k=0;k<4;++k){
      int ny=y+dy[k], nx=x+dx[k];
      if(0<=ny&&ny<H&&0<=nx&&nx<W){
        dist[ny][nx]=min(dist[y][x]+1, dist[ny][nx]);
        if(A[ny][nx]!='#'){
          que.push({ny,nx});A[ny][nx]='#';
        }
      }
    }
  }

  int ans=0;
  for (int i=0;i<H;++i){
    for (int j=0;j<W;++j){
      ans=max(ans, dist[i][j]);
    }
  }

  cout << ans << endl;
  return 0;
}
