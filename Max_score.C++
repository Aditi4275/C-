#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate the median of a sorted vector
long long median(vector<long long>& arr) {
    sort(arr.begin(), arr.end());
    int size = arr.size();
    return arr[size / 2];
}

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<long long> a(n);
        vector<int> b(n);
        
        for (int i = 0; i < n; ++i) 
            cin >> a[i];
        for (int i = 0; i < n; ++i) 
            cin >> b[i];
        
        // Collect indices where b[i] == 1
        vector<int> operable_indices;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 1) operable_indices.push_back(i);
        }
        
        // Collect non-operable elements to compute median
        vector<long long> non_operable;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0) non_operable.push_back(a[i]);
        }
        
        // Compute median of non-operable elements
        long long median_non_operable = median(non_operable);
        
        // Find maximum possible score
        long long max_score = LLONG_MIN;
        for (int index : operable_indices) {
            // The score we can achieve if we increase a[index] by k operations
            long long potential_score = a[index] + k + median_non_operable;
            max_score = max(max_score, potential_score);
        }
        
        // Output the maximum score
        cout << max_score << "\n";
    }
    
    return 0;
}
