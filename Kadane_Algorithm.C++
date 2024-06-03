#include<bits/stdc++.h>
using namespace std;

//Brute Force
int maxSubarraySum(int arr[],int n){
    int maxele = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            maxele = max(maxele,sum);
        }
    }
    return maxele;
}

//Kadane's Algorithm

long long subArray(int arr[],int n){
    long long maxi = LONG_MIN;
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum > maxi)
            maxi = sum;
        if(sum < 0)
            sum = 0;   
    }
    
    return maxi;
}
int main(){
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSum = subArray(arr,n);
    cout<<maxSum<<endl;
}