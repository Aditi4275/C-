#include<bits/stdc++.h>
using namespace std;
//Maximun area rectangle in Binary Matrix
void NSL(vector<int> &arr,int n,vector<int>&left){
   
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

void NSR(vector<int>&arr,int n,vector<int>&right){
    
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

int area(vector<int> v,int n){
    vector<int>right;
    vector<int>left;
    NSL(v,n,left);
    NSR(v,n,right);
    int width[n];

    int max_area = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        max_area = max(max_area, width * v[i]);
    }
    return max_area;
}

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<int>v(m,0);
    
    int max_area = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0)
                v[j] =0;
            else{
                v[j] = v[j]+arr[i][j];
                max_area = max(max_area,area(v,m));
            }
        } 
    }
    cout<<max_area;
}