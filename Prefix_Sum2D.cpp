#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000;

int arr[maxn][maxn];
int p[maxn][maxn];

void PrefixSum(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            p[i][j] = arr[i][j];
            if(i > 0) p[i][j] += p[i-1][j];
            if(j > 0) p[i][j] += p[i][j-1];
            if(i > 0 && j > 0) p[i][j] -= p[i-1][j-1];
        }
    }
}

int RectangleSum(int u, int l, int d, int r){
    int ans = p[d][r];
    if(l > 0) ans -= p[d][l-1];
    if(u > 0) ans -= p[u-1][r];
    if(u >0 && l > 0) ans += p[u-1][l-1];
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    PrefixSum(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<"\n";
    }
    int u,l,d,r;
    cin>>u>>l>>d>>r;
    cout<<RectangleSum(u,l,d,r)<<"\n";
}