#include<bits/stdc++.h>
using namespace std;

// Equal sum partition
bool subset_sum(int arr[],int sum,int n){
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i == 0)
                t[i][j] = false;
            else if(j == 0)
                t[i][j] = true;
        }
    }
    for(int i =1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}
bool partition(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum%2 != 0)
        return false;
    else
        return subset_sum(arr,sum/2,n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<partition(arr,n)<<endl;
}