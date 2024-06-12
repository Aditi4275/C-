#include<bits/stdc++.h>
using namespace std;

//Updating 2D Matrix:
//If the value is 9 then upgrade all its neighbour elements 
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
    cout<<"The resultant matrix is: "
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
