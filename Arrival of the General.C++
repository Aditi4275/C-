#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_no=INT_MIN;
    int min_no = INT_MAX;
    int max_idx=0;
    int min_idx=0;
    for(int i=0;i<n;i++){
        max_no = max(max_no,arr[i]);
        if(arr[i] == max_no)
            max_idx=i;
        min_no = min(min_no,arr[i]);
        if(arr[i] == min_no)
            min_idx=i;
    }
    
    if(max_idx > min_idx){
        cout<<max_idx+min_idx-1;
    }
    else{
        cout<<max_idx+min_idx;
    }
}