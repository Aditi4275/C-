#include<bits/stdc++.h>
using namespace std;

//Minimum number of insertion and deletion to convert from a to b
void min_insert_delete(string x, string y, int n, int m){
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
                t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }
    int lcs = t[n][m];
    cout<<"Min no of insertions:"<<(m-lcs)<<endl;
    cout<<"Min no of deletions:"<<(n-lcs)<<endl;
}

int main(){
    int n,m;
    string x;
    string y;
    cin>>x;
    cin>>y;
    min_insert_delete(x,y,n,m);
    
}