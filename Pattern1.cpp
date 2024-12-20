#include <bits/stdc++.h>
using namespace std;

void func(int i, int j, int n, int m){
    if(i == 2 || j == 3){
        cout<<"*";
    }
    else
        cout<<" ";
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){   // Canvas Size
        for(int j=0;j<m;j++){
            func(i,j,n,m);
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