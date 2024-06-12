#include<bits/stdc++.h>
using namespace std;

/*void NSL(int arr[],int n,vector<int>&left){
    stack<pair<int,int>>s;
    int pseudo=-1;
    for(int i=0;i<n;i++){
        if(s.empty())
            left.push_back(pseudo);
        else if(s.top().first > arr[i])
            left.push_back(s.top().second);
        else
    }
}*/



void matrix(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 9){
               if(j+1 <m) mat[i][j+1] +=1;
               if(j-1 >= 0) mat[i][j-1] += 1;
               if(i-1 >= 0) mat[i-1][j] += 1;
               if(i+1 < n) mat[i+1][j] += 1;
               }
            }
        }
  
}

int main(){
     int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    matrix(mat);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
