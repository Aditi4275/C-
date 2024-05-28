#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//to find the count of elements that are strictly smaller than it and generate a sequence from it.
vector<int> frequency(int arr[], int n){
  vector<int>v(n);
  int f[101] = {0};
  for(int i=0;i<n;i++){
    f[arr[i]]++;
  }
  for(int i=1;i<101;i++){
    f[i] = f[i]+f[i-1];
  }
  for(int i=0;i<n;i++){
    if(arr[i] == 0)
      v[i] =0;
    else
      v[i] = f[arr[i]-1];
  }
  return v;
}

int main() {
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
     cin>>arr[i];
   }
  vector<int> v = frequency(arr,n);
  for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
  }
    return 0;
}