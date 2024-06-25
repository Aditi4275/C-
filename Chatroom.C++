#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string h = "hello";
    int j=0;

    for(int i=0;i<s.length();i++){
        if(s[i] == h[j]){
            j++;
        }
        if(j == h.length())
            break;
    }
    
    if(j == h.length())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}