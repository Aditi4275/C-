#include <bits/stdc++.h>
using namespace std;

bool DT(int a, int b, int c) {
    return ((a + b > c) && (a + c > b) && (b + c > a));
}

int find(int x) {
    int left = 1, right = x - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int k = x ^ mid;

        if (k > 0 && DT(x, mid, k)) {
            return mid;
        } else if (k <= 0 || !DT(x, mid, k)) {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        cout << find(x) << "\n";
    }

    return 0;
}