#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> black(N);
    vector<long long> white(M);

    for (int i = 0; i < N; ++i) {
        cin >> black[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> white[i];
    }

    // Sort black and white balls in descending order
    sort(black.rbegin(), black.rend());
    sort(white.rbegin(), white.rend());

    // Compute prefix sums for black and white balls
    vector<long long> prefixBlack(N + 1, 0);
    vector<long long> prefixWhite(M + 1, 0);

    for (int i = 0; i < N; ++i) {
        prefixBlack[i + 1] = prefixBlack[i] + black[i];
    }

    for (int i = 0; i < M; ++i) {
        prefixWhite[i + 1] = prefixWhite[i] + white[i];
    }

    long long maxSum = 0;

    // Iterate over the number of white balls to choose (k)
    for (int k = 0; k <= min(M, N); ++k) {
        // Sum of top k white balls and top k black balls
        long long sum = prefixWhite[k] + prefixBlack[k];
        maxSum = max(maxSum, sum);
    }

    // Also consider cases where we choose more black balls than white balls
    for (int k = 0; k <= M; ++k) {
        // Ensure that the number of black balls is at least k
        if (k > N) continue;
        // Sum of top k white balls and top k black balls
        long long sum = prefixWhite[k] + prefixBlack[k];
        maxSum = max(maxSum, sum);
    }

    // Handle cases where we choose more black balls than white balls
    for (int k = 0; k <= N; ++k) {
        // Ensure that the number of white balls is at most k
        if (k > M) continue;
        // Sum of top k white balls and top k black balls
        long long sum = prefixWhite[k] + prefixBlack[k];
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

    return 0;
}