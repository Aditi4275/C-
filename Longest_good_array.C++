#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        int count = 1;
        int dif = 1;
        while(l +dif <= r){
            l = l+dif;
            dif++;
            count++;
        }
        cout<<count<<endl;
    }
}