#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        multiset<int>even,odd;

        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a%2 == 0)
                even.insert(a);
            else
                odd.insert(a);
        }
        if(odd.size() == 0 || even.size() == 0){
            cout<<0<<endl;
            continue;
        }
        int ans = even.size();
        int mx = *(odd.rbegin());      //max odd number
        for(int i: even){
            if(i < mx)
                mx += i;
            else{
                ans++;
                break;
            }
        }
        cout<<ans<<endl;
    }
}

