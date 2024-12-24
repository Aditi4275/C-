#include <bits/stdc++.h>
using namespace std;
/*
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
*/

void func(int i, int j, int n){
    int sizeRepeat = n;
    if(i%sizeRepeat - j >= -(n-1) && i%sizeRepeat + j >= (n-1))
        cout<<"* ";
    else
        cout<<"  ";
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){   // Canvas Size
        for(int j=0;j<2*n-1;j++){
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