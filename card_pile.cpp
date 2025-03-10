#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>>st;
    int q;
    cin>>q;
    for(int i=1;i<=100;i++){
        st.push({i,0});
    }
    while(q--){
        int t;
        cin>>t;
        if(t == 2){
            if(!st.empty() && st.top().first > 0){
                int k = st.top().second;
                cout<<k<<endl;
                st.pop();
            }
        }
        else{
            int x;
            cin>>x;
            if(!st.empty())
            st.push({st.top().first+1, x});
        }
    }
    return 0;
}