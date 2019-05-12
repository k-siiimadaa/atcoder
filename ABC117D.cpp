#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


vi binary_exp(ll a){
  vi ans(50);
  for (int i=0;i<50;++i){
    ans[i]=(a>>i)&1;
  }
  return ans;
}

int main(){
  int N;cin>>N;ll K;cin>>K;
  vi counter(50,0);
  vll A;
  for (int i=0;i<N;++i){
    ll a;cin>>a;vi ab=binary_exp(a);A.push_back(a);
    for (int j=0;j<50;++j) counter[j]+=ab[j];
  }

  vi vote(50,0);
  for (int i=0;i<50;++i){
    if((N&1)&&counter[i]==N/2) vote[i]=1;
    if(counter[i]<N/2) vote[i]=1;
  }

  vi Kb=binary_exp(K);

  ll X=0;
  int flag=1;
  for (int i=49;i>=0;--i){
    if(flag==1&&Kb[i]==1&&vote[i]==1) X+=(ll)pow(2,i);
    if(flag==1&&Kb[i]==1&&vote[i]==0) flag=0;
    if(flag==0&&vote[i]==1) X+=(ll)pow(2,i);
  }

  ll ans=0;
  for (int i=0;i<N;++i){
    ans+=X^A[i];
  }
  cout << ans << endl;
  return 0;
}
