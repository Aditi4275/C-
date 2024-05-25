#include<bits/stdc++.h>
using namespace std;

string reverse(string s){
    stack<char>st;
    string str = "";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i] != ' '){
            st.push(s[i]);
        }
        else{
            while(!st.empty()){
                str += st.top();
                st.pop();
            }
            str += ' ';
        }
    }
    while(!st.empty()){
        str += st.top();
        st.pop();
    }
    return str;
}

int main(){
    string s;
    getline(cin,s);
    string sk = reverse(s);
    cout<<sk<<endl;
}