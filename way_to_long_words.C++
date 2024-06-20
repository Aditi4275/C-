#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int len = s.length(); 
        if(len <= 10)
            cout<<s<<endl;
        else{
            string ans = s[0]+to_string(len-2)+s[len-1];
            cout<<ans<<endl;
        }
        
    }
}