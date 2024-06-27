#include<bits/stdc++.h>
using namespace std;


int main(){
    string t;
    cin>>t;
    string s;
    cin>>s;
    int j=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == t[j]){
            j++;
        }
    }
    cout<<j+1<<endl;
}