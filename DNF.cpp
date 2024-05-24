#include<bits/stdc++.h>
using namespace std;

//DNF Sort
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void DNF(int arr[],int n){
    int low = 0,mid = 0,high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
            mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
            mid++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    DNF(arr,n);
}