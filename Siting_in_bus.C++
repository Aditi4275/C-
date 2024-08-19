#include <iostream>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        set<int> occupied;
        bool valid = true;
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                // First passenger can sit anywhere
                occupied.insert(a[i]);
            } else {
                // Check if a[i] has a neighbor that is already occupied
                if (occupied.count(a[i] - 1) || occupied.count(a[i] + 1)) {
                    occupied.insert(a[i]);
                } else {
                    valid = false;
                    break;
                }
            }
        }
        
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
