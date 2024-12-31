#include<bits/stdc++.h>
using namespace std;
using ll= long long;

signed main(){
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        deque<ll>a;
        vector<ll>b(n);
        for(ll i=0;i<n;i++){
            ll k;
            cin>>k;
            a.push_back(k);
        }
        for(ll i=0;i<n;i++){
           cin>>b[i];
        }
        int i= 0, count=0;
        for(int i=0;i<n;i++){
            while(i<n && a[i] > b[i]){
                a.push_front(b[i]);
                a.pop_back();
                count++;
                sort(a.begin(), a.end());
            }
        }
        cout<<count<<"\n";
    }

}