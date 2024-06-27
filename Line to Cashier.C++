#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans =INT_MAX;
    for(int i=0;i<n;i++){
        int meet =0;
        for(int j=0;j<arr[i];j++){
            int val;
            cin>>val;
            meet +=(5*val);
        }
        ans = min(ans,(meet+15*arr[i]));
    }
    cout<<ans<<endl;
}