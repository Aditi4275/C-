#include<bits/stdc++.h>
using namespace std;

bool binary_search(vector<int>&nums, int target, int m){
    int left =0;
    int right =m-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(nums[mid] == target)
            return true;
        else if(nums[mid] > target)
            right = mid -1;
        else
            left = mid+1;
    }
    return false;
}


bool search(int n, int m, int target, vector<vector<int>> &arr){
    for(int i=0;i<n;i++){
        if(target >= arr[i][0] && target <= arr[i][m-1]){
           return binary_search(arr[i],target,m);
            }
        }
    return false;
}
// time complexity = O(N+logM)
//Converting 2D array into 1D array
bool search_matrix(vector<vector<int>>arr,int target){
    int n = arr.size();
    int m = arr[0].size();

    int left = 0;
    int right = (n*m)-1;            // converting 2D to 1D array
    while(left<=right){
        int mid = (left+right)/2;
        int row = mid/m;             //calculating row index
        int col = mid%m;             // calculating col index
        if(arr[row][col] == target)
            return true;
        else if(arr[row][col] > target)
            right = mid-1;
        else
            left = mid+1;
    }
    return false;
}
int main(){
    int n,m,target;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cin>>target;
    cout<<search_matrix(arr,target);
}