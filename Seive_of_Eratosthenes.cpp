//Seive of Eratosthenes
#include<bits/stdc++.h>
using namespace std;

void Seive_of_Eratosthenes(int n){
    vector<bool>prime(n+1, true);
    for(int i=2; i*i<=n; i++){
        if(prime[i] == true){
            for(int j = i*i; j<=n;j+= i){
                prime[j] = false;
            }
        }
    }
    for(int i=2;i<n+1;i++){
        if(prime[i])
            cout<<i<<" ";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n = 50;
    Seive_of_Eratosthenes(n);
}