#include<bits/stdc++.h>
using namespace std;

using lli = long long;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli ans = 1;
        while(n > 3){
            ans *= 2;
            n /= 4;
        }
        cout<<ans<<"\n";
    }
}