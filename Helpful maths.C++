#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int mid = ceil(s.length()/2.0);
    for(int i=mid-1;i<s.length();i++){
        cout<<s[i];
        if(i != s.length()-1)
            cout<<"+";
    }

}