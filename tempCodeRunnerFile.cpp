#include<bits/stdc++.h>
using namespace std;

int count(int arr[],int n){
    int freq[100]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<100;i++){
        if(freq[i] == n/2)
            return i+1;
    }
    return -1;
}

int main(){
    int arr[] ={2,2,1,1,1,2,2};
    cout<<count(arr,7); 
}