#include<bits/stdc++.h>
using namespace std;
//Brute Force
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

int majority(int arr[],int n){
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        if(it.second > (n/2));
            return it.first;
    }
    return -1;
}

int main(){
    int arr[] ={2,2,2,1,2,2,1};
    cout<<majority(arr,7); 
}