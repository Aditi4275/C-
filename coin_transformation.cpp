#include<bits/stdc++.h>
using namespace std;

long long solve(long long n, unordered_map<long long, long long> map){
    if(n <= 3)
        return 1;
    
    if(map.find(n) != map.end())
        return map[n];
    
    long long spt = solve(n/4, map)*2;
    return map[n] = spt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        unordered_map<long long, long long>map;        
        cout<<solve(n,map)<<"\n";
    }
}