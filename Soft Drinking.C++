#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int max_drinks = (k*l)/nl;
    int max_limes = c*d;
    int max_salt = p/np;

    int toast = min({max_drinks,max_limes,max_salt})/n;
    cout<<toast<<endl;
}