#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    if(s.length() == 0)
        cout<< s;
   transform(s.begin(), s.end(), s.begin(), ::tolower);
    string ans = "";
    for(int i=0;i<s.length();i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i')
            continue;
        else{
            ans += '.';
            ans += s[i];
        }
    }
     cout<<ans<<endl;
}