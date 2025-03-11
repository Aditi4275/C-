#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

ll count(int n, int m, vector<ll>& x, vector<int>& r) {
    set<ii> p; 

    for (int i = 0; i < n; i++) {
        ll Xi = x[i];
        int radius = r[i];

        for (int y = -radius; y <= radius; y++) {
            int Offset = sqrt(radius * radius - y * y);

            for (int set = -Offset; set <= Offset; set++) {
                ll curX = Xi + set;
                p.insert({curX, y});
            }
        }
    }

    return p.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;

        vector<ll>x(n);
        for (int i = 0; i < n; i++) {
            cin>>x[i];
        }

        vector<int>r(n);
        for (int i = 0; i < n; i++) {
            cin>>r[i];
        }

        ll ans = count(n, m, x, r);
        cout << ans << "\n";
    }

    return 0;
}