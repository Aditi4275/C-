#include<bits/stdc++.h>
using namespace std;

int ans(int arr[],int n){
    int freq[n]={0};
    int a[2];
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(freq[i] == 0)
            a[0] = i;
        else if(freq[i] > 1)
            a[1] = i;
    }
    return a;
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a[2] = ans(arr,n);
    cout<<a[0]<<a[1] ;
}