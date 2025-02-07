#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string word = "";

        for(int i=0;i<s.length();i++){
            if(isspace(s[i])){
                if(!word.empty()){
                    st.push(word);
                    word = "";
                }
            }
            else{
                word += s[i];
            }
        }
        if(!word.empty())
            st.push(word);
            
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            ans += " ";
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "       Let's take LeetCode    contest";
    cout<<sol.reverseWords(s)<<endl;
    return 0;
}