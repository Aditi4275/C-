#include<bits/stdc++.h>
using namespace std;

pair<bool,int> square(int n){
     int root = sqrt(n); // Get the square root
    if(root * root == n) {
        return {true, root};
    }
    return {false, 0};
}
bool matrix(string s, int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(i==0 || i==k-1 || j==0 || j==k-1){
                if(s[i*k+j] != '1')
                    return false;
            }
            else{
                if(s[i*k+j] != '0')
                    return false;
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        pair<bool,int> sq = square(n);
        if(!sq.first){
            cout<<"No"<<endl;
        }
        else{
            if(matrix(s,sq.second))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}