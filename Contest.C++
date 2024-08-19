#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int t1 = a-((a*c)/250);
    int t2 = b-((b*d)/250);
    int misha =max(((3*a)/10),t1);
    int vasya =max(((3*b)/10),t2);
    string ans;
    if(misha > vasya)
        ans = "Misha";
    else if(misha < vasya)
        ans = "Vasya";
    else
        ans = "Tie";
    cout<<ans<<endl;
}