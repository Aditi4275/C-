#include<bits/stdc++.h>
using namespace std;

//Balanced Paranthesis

bool parenthesis(string s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else{
            if(st.empty())
                return false;
            char curr = st.top();
            if((s[i] == ')' && curr == '(') || (s[i] == ']' && curr == '[') || (s[i] == '}' && curr == '{'))
                st.pop();
            else    
                return false;
        }
    }
    return st.empty();
}

int main(){
    string s;
    cin>>s;
    cout<<parenthesis(s)<<endl;
}