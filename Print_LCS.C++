#include<bits/stdc++.h>
using namespace std;

//Printing the longest common subsequence
string print_LCS(string x, string y, int n, int m){
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
    int i = n;
    int j = m;
    string s = "";
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            s += x[i-1];
            i--;
            j--;
        }
        else{
            if(t[i][j-1] > t[i-1][j])
                j--;
            else
                i--;
        }
    }
    return s;
}

int main(){
    string x;
    string y;
    cin>>x;
    cin>>y;
    int n = x.length();
    int m = y.length();
    cout<<print_LCS(x,y,n,m)<<endl;
}