#include <bits/stdc++.h>
using namespace std;

bool T(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int maxLast(vector<int>& arr) {
    priority_queue<int> maxHp(arr.begin(), arr.end());

    while (maxHp.size() > 1) {
        int f = maxHp.top(); maxHp.pop();
        int s = maxHp.top(); maxHp.pop();

        int x = f + s - 1; 
        maxHp.push(x);
    }

    return maxHp.top();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (n == 1) {
            cout << arr[0] << "\n";
            continue;
        }

        int ans = maxLast(arr);
        cout << ans << "\n";
    }

    return 0;
}