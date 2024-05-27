#include<bits/stdc++.h>
using namespace std;
//1st approach -- Sorting
int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
}
//2nd approach --Frequency array
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count[n]={0};
    for(int i=0;i<n;i++){
        if(count[arr[i]] == 0)
            count[arr[i]]++;
        else
            cout<<arr[i];
    }
    
}