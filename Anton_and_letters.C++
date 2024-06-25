#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    set<char>distinct_letters;

    for(int i=0;i<s.length();i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            distinct_letters.insert(s[i]);
    }
    
    cout<<distinct_letters.size()<<endl;
}