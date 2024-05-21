#include<bits/stdc++.h>
using namespace std;


// Max Area Histogram
void NSL(int arr[],int n,vector<int>&left){
   
    stack<pair<int,int>>s;
    int pseudo_index = -1;

    for(int i=0;i<n;i++){
        if(s.empty())
            left.push_back(pseudo_index);
        else if(s.top().first < arr[i] )
            left.push_back(s.top().second);
        else{
            while(!s.empty() && s.top().first >= arr[i])
                s.pop();
            if(s.empty())
                left.push_back(pseudo_index);
            else
                left.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    
}

void NSR(int arr[],int n,vector<int>&right){
    
    stack<pair<int,int>>s;
    int pseudo_index = n;

    for(int i=n-1;i>=0;i--){
        if(s.empty())
            right.push_back(pseudo_index);
        else if(s.top().first < arr[i] )
            right.push_back(s.top().second);
        else{
            while(!s.empty() && s.top().first >= arr[i])
                s.pop();
            if(s.empty())
                right.push_back(pseudo_index);
            else
                right.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    reverse(right.begin(),right.end());
}

int area(int arr[],int n){
    vector<int>right;
    vector<int>left;
    NSL(arr,n,left);
    NSR(arr,n,right);
    int width[n];

    for(int i=0;i<n;i++){
        width[i] = right[i]-left[i]-1;
    }
    int max_area = 0;
    for(int i=0;i<n;i++){
        max_area = max(max_area,(width[i]*arr[i]));
    }
   return max_area;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    
    vector<int>v;
    int max_area = area(arr,n);
    cout<<max_area;
    
}