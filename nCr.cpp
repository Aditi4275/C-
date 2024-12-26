#include<bits/stdc++.h>
using namespace std;
// n<1e6

using  ll = long long;
const ll mod = 1e9 + 7;
const int max_val = 1e6;

vector <ll> fact(max_val+1), inv_fact(max_val+1);

ll bin_pow(ll base, ll exp, ll mod){
    ll result = 1;
    while(exp > 0){
        if(exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void factorials(){
    fact[0] = 1;
    for(ll i=1;i<= max_val;i++){
        fact[i] = (i * fact[i-1])%mod;
    }
    inv_fact[max_val] = bin_pow(fact[max_val],mod-2,mod);

    for(ll i=max_val-1;i>=0;i--){
        inv_fact[i] = (inv_fact[i+1] * (i+1))%mod;
    }
}

ll nCr(ll n, ll k){
    if(k > n) return 0;
    return (fact[n] * ((inv_fact[n-k] * inv_fact[k]) % mod)) % mod;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,k;
    cin>>n>>k;
    
    factorials();
    cout<<nCr(n,k)<<"\n";

}