#include<bits/stdc++.h>
using namespace std;

int distance(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

bool Square(pair<int, int> x1, pair<int, int> x2, pair<int, int> x3, pair<int, int> x4) {
    vector<int> dist;
    dist.push_back(distance(x1, x2));
    dist.push_back(distance(x1, x3));
    dist.push_back(distance(x1, x4));
    dist.push_back(distance(x2, x3));
    dist.push_back(distance(x2, x4));
    dist.push_back(distance(x3, x4));

    sort(dist.begin(), dist.end());

    return (dist[0] > 0 && dist[0] == dist[1] && dist[1] == dist[2] && dist[2] == dist[3] && dist[4] == dist[5]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        pair<int, int> x1, x2, x3, x4;
        x1 = {-l, 0};
        x2 = {r, 0};
        x3 = {0, -d};
        x4 = {0, u};

        if (Square(x1, x2, x3, x4)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}