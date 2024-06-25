#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][3];
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
            ans += arr[i][j];
        }
    }
    if(ans == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}