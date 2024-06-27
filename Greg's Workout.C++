#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int chest = 0, biceps = 0, back =0;
    int c=0, b=1, p=2,k;
    for(int i=0;i<n;i++){
        cin>>k;
        if(c == i){
            chest += k;
            c += 3;
        }
        else if(b == i){
            biceps += k;
            b += 3;
        }
        else if( p == i){
            back += k;
            p +=3;
        }
    }
    int musscle = max({chest,back,biceps});
    if(musscle == chest)
        cout<<"chest"<<endl;
    else if(musscle == back)
        cout<<"back"<<endl;
    else if(musscle == biceps)
        cout<<"biceps"<<endl;
    
}