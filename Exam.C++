#include<bits/stdc++.h>
using namespace std;

string ans(int a, int b){
    if((a == 0 && b%2 != 0) || (b == 0 && a%2 != 0))
        return "NO";
    else if((a == 0 && b%2 == 0) || (b == 0 && a%2 == 0))
        return "YES";
    else{
        if((a+(b*2))%2 == 0)
            return "YES";
        else
            return "NO";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<ans(a,b)<<endl;
        
    }
}