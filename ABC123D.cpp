#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
  int X, Y, Z, K;cin>>X>>Y>>Z>>K;
  vll A, B, C;
  for (int i=0;i<X;++i){ll a;cin>>a;A.push_back(a);}
  for (int i=0;i<Y;++i){ll b;cin>>b;B.push_back(b);}
  for (int i=0;i<Z;++i){ll c;cin>>c;C.push_back(c);}

  sort(A.begin(), A.end(), greater<ll>());
  sort(B.begin(), B.end(), greater<ll>());
  sort(C.begin(), C.end(), greater<ll>());
  vll D;

  for (int i=0;i<X;++i){
    for (int j=0;j<Y;++j){
      D.push_back(A[i]+B[j]);
    }
  }

  sort(D.begin(), D.end(), greater<ll>());
  vll E;

  int K_=min(K, X*Y);

  for (int i=0;i<K_;++i){
    for (int j=0;j<Z;++j){
      E.push_back(D[i]+C[j]);
    }
  }

  sort(E.begin(), E.end(), greater<ll>());

  for (int i=0;i<K;++i){
    cout << E[i] << endl;
  }
  return 0;
}
