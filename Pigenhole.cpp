#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    map<int, int> nest_count; 
    map<int, int> pigeon_location;  
    int multi_count = 0;  

    for (int i = 1; i <= n; i++) {
        nest_count[i] = 1;
        pigeon_location[i] = i;
    }

    while (q--) {
        int c;
        cin >> c;

        if (c == 1) {
            int p, h;
            cin >> p >> h;
            int current_nest = pigeon_location[p];

            if (--nest_count[current_nest] == 1) {
                multi_count--;  
            }
            if (++nest_count[h] == 2) {
                multi_count++;  
            }

            pigeon_location[p] = h;

        } else if (c == 2) {
            cout << multi_count << '\n';
        }
    }

    return 0;
}
