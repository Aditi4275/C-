#include<bits/stdc++.h>
using namespace std;

//Length of longest common substring
int longest_common_substring(string x, string y, int n, int m){
    int t[n+1][m+1];
    int max_length = 0;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1+t[i-1][j-1];
                max_length = max(max_length,t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }
    return max_length;
}
int main(){
    int n,m;
    string x,y;
    cin>>x;
    cin>>y;
    n = x.length();
    m = y.length();
    cout<<longest_common_substring(x,y,n,m)<<endl;
}