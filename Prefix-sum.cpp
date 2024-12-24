//Prefix Sum
#include<bits/stdc++.h>
using namespace std;

vector<int> calculate_prefix(vector<int>arr){
    int n = arr.size();
    vector<int> prefix(n,0);

    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = arr[i]+prefix[i-1];
    }
    return prefix;
}

int query_sum(int l, int r, vector<int>prefix){
    if( l == 0)
        return prefix[r];
    else
        return prefix[r] - prefix[l-1];
}
signed main(){
    
    vector<int> array = {1,2,3,4,5};
    vector<int>prefix_sum = calculate_prefix(array);    //{1,3,6,10,15}

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int res = query_sum(l,r, prefix_sum);
        cout<<"Sum from l to r is:"<<res<<"\n";
    }
}