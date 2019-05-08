#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
  int N, K;cin>>N>>K;
  string S;cin>>S;

  char beg=S[0], en=S[N-1];

  vi C0, C1;

  int l=0;

  for (int i=0;i<=N;++i){
    if(i==0) l++;

    else if(i==N){
      if(S[i-1]=='0') C0.push_back(l);
      else C1.push_back(l);
    }

    else{
      if(S[i]!=S[i-1]){
        if(S[i-1]=='0') {C0.push_back(l);l=1;}
        else{C1.push_back(l);l=1;}
      }
      else l++;
    }
  }

  int L=C0.size();
  if(L<=K){cout << N << endl; return 0;}

  C1.push_back(0);

  int tmp=0;
  int ans=0;

  if(beg=='0'){
    for (int i=0;i<K;++i){
      tmp+=C0[i]+C1[i];
    }
    ans=tmp;

    for (int i=K;i<L;++i){
      if(i==K){
        tmp+=C0[i]+C1[i]-C0[0];
        ans=max(tmp, ans);
      }
      else{
        tmp+=C0[i]+C1[i]-C0[i-K]-C1[i-K-1];
        ans=max(ans, tmp);
      }
    }
  }

  else{
    tmp+=C1[0];
    for (int i=0;i<K;++i){
      tmp+=C0[i]+C1[i+1];
    }
    ans=tmp;

    for (int i=K;i<L;++i){

      tmp+=C0[i]+C1[i+1]-C0[i-K]-C1[i-K];
      ans=max(ans, tmp);
    }
  }


  cout << ans << endl;
  return 0;
}
