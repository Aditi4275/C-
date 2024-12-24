#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        int d;
        cin >> n >> d;

        long long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact = (fact * i) % MOD;
        }

        cout << 1 << " ";

        if ((fact * d) % 3 == 0) {
            cout << 3 << " ";
        }

        if (d == 5) {
            cout << 5 << " ";
        }
        
        if ((fact * d) % 7 == 0) {
            cout << 7 << " ";
        }

        if ((fact * d) % 9 == 0) {
            cout << 9 << " ";
        }

        cout << endl;
    }

    return 0;
}