#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans |= a[i];
        }
        cout<<ans<<endl;
    }
}