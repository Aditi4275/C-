#include <bits/stdc++.h>
using namespace std;
/*
        *
    *           *
  *               *


*                   *


  *               *
    *           *
          *
*/

void func(int i, int j, int n){
    int sizeRepeat = n;
    if((i-n)*(i-n)+ (j-n)*(j-n) == n*n)
        cout<<"* ";
    else
        cout<<"  ";
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<2*n+1;i++){   // Canvas Size
        for(int j=0;j<2*m+1;j++){
            func(i,j,n);
        }
        cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(t--){
        solve();
    }
}