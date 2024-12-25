#include<bits/stdc++.h>
using namespace std;

using lli = long long;

lli binpow(lli a, lli b, lli mod){  //a^b%mod
     if (b == 0)
        return 1;
    if (b % 2) {
        return a * binpow(a, b - 1, mod) % mod;
    } else {
        lli temp = binpow(a, b / 2, mod);
        return temp * temp % mod;
    }
}
int main(){
    lli a,b,c,d,e;
    lli mod = 1e9+7;
    cin>>a>>b>>c>>d>>e;

    a = a%mod;  //since d is in power, can't take it's modulo
    b = b%mod;
    c = c%mod;
    e = e%mod;

    lli x1 = (a*b)%mod;
    lli x2 = binpow(c,d,mod);
    lli x3 = (x1 - x2)%mod;
    lli x4 = binpow(e,mod-2,mod);

    lli ans = (x3*x4)%mod;

    cout<<(ans+mod)%mod<<"\n";   //to handle negative values
}

//((ans%mod)+mod)%mod