#include<bits/stdc++.h>
using namespace std;
//Set Matrix Zero
void set_zero(int i,int j,int n,int m,vector<vector<int>>& arr){
    //rows
    for(int k=0;k<m;k++){
        arr[i][k] = 0;
    }
    //cols
    for(int l=0;l<n;l++){
        arr[l][j] = 0;
    }
    
}
void get_zero(int n,int m, vector<vector<int>>& arr){

    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0)
                v.push_back({i,j});
        }
    }
    for(int k=0;k<v.size();k++){
        set_zero(v[k].first,v[k].second,n,m,arr);
    }
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    get_zero(n,m,arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}