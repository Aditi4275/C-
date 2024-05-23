#include<bits/stdc++.h>
using namespace std;

//Subset Sum Problem  
bool subset_sum(int arr[],int n,int sum){
    bool t[n+1][sum+1];
    //initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i == 0)
                t[i][j] = false;
            else if( j == 0)
                t[i][j] = true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1] <= j){
                t[i][j] = (t[i-1][j-arr[i-1]]) || (t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<subset_sum(arr,n,sum)<<endl;
}