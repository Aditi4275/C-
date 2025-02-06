#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string d;
    cin>>d;
    if(d == "N") cout<<"S\n";
    else if( d == "E") cout<<"W\n";
    else if( d == "S") cout<<"N\n";
    else if(d == "W") cout<<"E\n";
    else if(d == "NE") cout<<"SW\n";
    else if(d == "NW") cout<<"SE\n";
    else if(d == "SE") cout<<"NW\n";
    else if(d == "SW") cout<<"NE\n";
    return 0;
}