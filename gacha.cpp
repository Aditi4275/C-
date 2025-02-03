#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<string>st;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<"\n";
}