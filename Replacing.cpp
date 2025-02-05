#include<bits/stdc++.h>
using namespace std;

long long sum(const unordered_map<int,int>& mp){
    long long s = 0;
    for(const auto it: mp){
        s += 1LL * (it.first * it.second);
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    int q;
    cin>>q;

    long long s = sum(mp);
    while(q--){
        int b,c;
        cin>>b>>c;
        if(mp.find(b) != mp.end()){
            s -= 1LL * mp[b] * b;
            s += 1LL * mp[b] * c;
            
            mp[c] += mp[b];
            mp.erase(b);
        }
        cout<<s<<endl;
    }

}