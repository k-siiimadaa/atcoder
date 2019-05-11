#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

struct UnionFind{
  vi data;

  UnionFind(int N): data(N,-1){}

  int find(int x){
    if(data[x]<0) return x;
    return find(data[x]);
  }

  void unite(int x, int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(data[x]>data[y]) swap(x,y);
    data[x]+=data[y];
    data[y]=x;
  }

  int size(int x){return -data[find(x)];}

  bool same(int x, int y){return find(x)==find(y);}
};

ll num_pairs(int n){return (ll)n*(n-1)/2;}

int main(){
  int N, M;cin>>N>>M;
  vi A, B;
  for (int i=0;i<M;++i){
    int a, b;cin>>a>>b;A.push_back(a-1);B.push_back(b-1);
  }

  vll num_connected;
  num_connected.push_back(0);

  UnionFind tree(N);

  ll tmp=0;

  for (int i=M-1;i>=0;--i){
    if(tree.same(A[i], B[i])) {num_connected.push_back(tmp);}
    else{
      ll tmp1=num_pairs(tree.size(A[i])), tmp2=num_pairs(tree.size(B[i]));
      tree.unite(A[i], B[i]);
      ll tmp3=num_pairs(tree.size(A[i]));
      tmp+=tmp3-tmp1-tmp2;
      num_connected.push_back(tmp);
    }
  }

  for (int i=M-1;i>=0;--i){
    cout << num_connected[M]-num_connected[i] << endl;
  }
  return 0;
}
