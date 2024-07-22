#include<bits/stdc++.h>
using namespace std;

//Length of shortest common supersequence

int shortest_common_supersequence(string x, string y, int n, int m){
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1] == y[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = max(t[i][j-1],t[i-1][j]);
        }
    }
    return n+m-t[n][m];
}

int main(){
    int n,m;
    string x;
    string y;
    cin>>x;
    cin>>y;
    cout<<shortest_common_supersequence(x,y,n,m);
    
}