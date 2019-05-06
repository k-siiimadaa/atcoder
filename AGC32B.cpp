#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  if(N==3){
    cout << 2 << endl;
    cout << 1 << ' ' << 3 << endl;
    cout << 2 << ' ' << 3 << endl;
    return 0;
  }

  if(N==4){
    cout << 4 << endl;
    cout << 1 << ' ' << 2 << endl;
    cout << 1 << ' ' << 3 << endl;
    cout << 4 << ' ' << 2 << endl;
    cout << 4 << ' ' << 3 << endl;
    return 0;
  }

  if(N%2==1){
    int q=N/2;
    cout << 4*q << endl;
    for (int m=1;m<q;++m){
      cout << m << ' ' << m+1 << endl;
      cout << m << ' ' << N-m-1 << endl;
      cout << N-m << ' ' << m+1 << endl;
      cout << N-m << ' ' << N-m-1 << endl;
    }
    cout << 1 << ' ' << N << endl;
    cout << N-1 << ' ' << N << endl;
    cout << q << ' ' << N << endl;
    cout << q+1 << ' ' << N << endl;
    return 0;
  }

  if(N%2==0){
    int q=N/2;
    cout << 4*q << endl;
    for (int m=1;m<q;++m){
      cout << m << ' ' << m+1 << endl;
      cout << m << ' ' << N-m << endl;
      cout << N-m+1 << ' ' << m+1 << endl;
      cout << N-m+1 << ' ' << N-m << endl;
    }
    cout << 1 << ' ' << q << endl;
    cout << 1 << ' ' << q+1 << endl;
    cout << N << ' ' << q << endl;
    cout << N << ' ' << q+1 << endl;
    return 0;
  }
}
