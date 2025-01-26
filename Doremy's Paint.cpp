#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        bool found = false; 
        sort(v.begin(), v.end()); 

        do {
            bool flag = true; 
            int k = v[1] + v[0];
            for(int i = 2; i < n; i++){
                if(v[i - 1] + v[i] != k){
                    flag = false;
                    break;
                }
            }
            if(flag){
                found = true;
                break;
            }
        } while (next_permutation(v.begin(), v.end()));

        if(found)
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
}
