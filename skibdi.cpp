#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string w;
        cin>>w;
        int last = w.size()-1;
        if(w[last -1] == 'u' && w[last] == 's'){
            w.erase(last-1,2);
            w += "i";
        }
        cout<<w<<endl;
    }
}