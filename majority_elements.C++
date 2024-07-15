#include<bits/stdc++.h>
using namespace std;


// Bayer Moore Majority Algorithm
class Solution{
    public:
    int majority_element(int arr[],int n){
        int candidate = -1 , votes =1;
        for(int i=0;i<n;i++){
            if(votes == 0){
                candidate = arr[i];
                votes = 1;
            }
            else{
                if(arr[i] == candidate)
                    votes++;
                else
                    votes--;
            }
        }
        int count = 0;

        for(int i=0;i<n;i++){
            if(arr[i] == candidate)
                count++;
        }

        if(count > n/2)
            return count;

        return -1;
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    cout<<obj.majority_element(arr,n)<<endl;
}