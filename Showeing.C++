#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,m;
        cin>>n>>s>>m;
        
        vector<pair<int,int>>intervals(n);

        for(int i=0;i<n;i++){
            cin>>intervals[i].first >> intervals[i].second;
        }
        
        sort(intervals.begin(), intervals.end());
        
        bool canshower = false;

        if(intervals[0].first >= s)
            canshower = true;

        for(int i=1;i<n;i++){
            if(intervals[i].first - intervals[i-1].second >= s){
                canshower = true;
                break;
            }
        }

        if(m - intervals[n-1].second >= s)
            canshower = true;

        if(canshower)
            cout<<"YES\n";
        else
            cout<<"NO"<<endl;
    }
}