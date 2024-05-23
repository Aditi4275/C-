#include<bits/stdc++.h>
using namespace std;

void set_zero(int i,int j,int n,int m,int &matrix[][m]){
    //rows
    for(int k=0;k<m;k++){
        matrix[i][k] = 0;
    }
    //cols
    for(int l=0;l<n;l++){
        matrix[l][j] = 0;
    }
    
}
int get_zero(int n,int m, int arr[][m]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            set_zero(i,j,n,m,arr[][m]);
        }
    }
    return arr[][];
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}