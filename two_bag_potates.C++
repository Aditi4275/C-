#include<bits/stdc++.h>
using namespace std;

int main(){
    int y,k,n;
    cin>>y>>k>>n;
    vector<int>ans;

    int start;
    start = ((y/k)+1)*k;
 
    while( start <= n){
        ans.push_back(start-y);
        start += k;

    }

    if(ans.size() == 0)
        cout<<-1;

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}