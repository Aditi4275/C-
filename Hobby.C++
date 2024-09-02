#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> visited(n, false);
    vector<int> F(n, 0);
    string s;
    
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--; 
    }
    
    cin >> s;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int black_count = 0;
            int current = i;
            
            while (!visited[current]) {
                visited[current] = true;
                cycle.push_back(current);
                if (s[current] == '0') {
                    black_count++;
                }
                current = p[current];
            }
            
        
            for (int node : cycle) {
                F[node] = black_count;
            }
        }
    }
    
   
    for (int i = 0; i < n; i++) {
        cout << F[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
