#include<bits/stdc++.h>
using namespace std;


//Recursive Approach
int LCS_recursive(const string &x,const string &y,int n,int m){
    if(n == 0 || m == 0)
        return 0;
    if(x[n-1] == y[m-1])
        return 1 + LCS_recursive(x,y,n-1,m-1);
    else
        return max(LCS_recursive (x,y,n-1,m),LCS_recursive(x,y,n,m-1));
}

//Memoization Approach
static int t[1001][1001];
int LCS_memoization(string x, string y, int n, int m){
    if(n == 0 || m == 0)
        return 0;
    if(t[n][m] != -1)
        return t[n][m];
    if(x[n-1] == y[m-1])
        return t[n][m] = 1 + LCS_memoization(x,y,n-1,m-1);
    else
        return t[n][m] = max(LCS_memoization (x,y,n-1,m),LCS_memoization(x,y,n,m-1));
}

//Top down Approach
int LCS_top_down(string x,string y, int n, int m){
    int k[n+1][m+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0 || j == 0)
                k[i][j] = 0;
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1] == y[j-1])
                k[i][j] = 1+k[i-1][j-1];
            else
                k[i][j] = max(k[i-1][j], k[i][j-1]);
        }
    }
    return k[n][m];
}
int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n = x.length();
    int m = y.length();
    memset(t,-1,sizeof(t));
    cout<<LCS_recursive(x,y,n,m)<<endl;
    cout<<LCS_memoization(x,y,n,m)<<endl;
    cout<<LCS_top_down(x,y,n,m)<<endl;
}