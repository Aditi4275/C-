#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int len = s.length(); 
        if(len < 10)
            cout<<n<<endl;
        else{
            string sl = to_string(len-2);
            string ans ="";
            ans += s[0]+sl+s[len-1];
            cout<<ans<<endl;
        }
        
    }
}