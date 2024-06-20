#include<bits/stdc++.h>
using namespace std;

bool watermelon(int n){
    if(n % 2 == 0 && n != 0)
        return true;
    else{
        int first = n/2;
        int second = n/2;
        while(first >0 && second > 0){
            if((first % 2 == 0) && (second % 2 == 0) && (first + second == n))
                return true;
            first = first+2;
            second = second-2;
            
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    if(watermelon(n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}