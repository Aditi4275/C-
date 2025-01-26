#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int arr[n+1], partial[n+2] = {0}; 

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        partial[l]++;
        partial[r+1]--;
    }

    for(int i=1; i<=n; i++) {
        partial[i] += partial[i-1];
    }

    sort(arr+1, arr+n+1); // Sort the array from index 1 to n
    sort(partial+1, partial+n+1); // Sort the partial array from index 1 to n

    long long ans = 0;
    for(int i=1; i<=n; i++) {
        ans += static_cast<long long>(partial[i]) * arr[i];
    }

    cout << ans << endl;
    return 0;
}