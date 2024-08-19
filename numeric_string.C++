#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // To speed up input/output operations
    cin.tie(nullptr); // To untie cin and cout for faster input/output

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int m;
        cin >> m;

        vector<string> s(m);
        for (int i = 0; i < m; i++) {
            cin >> s[i];
        }

        for (const auto& k : s) {
            if (k.length() != n) {
                cout << "NO" << endl;
                continue;
            }

            unordered_map<char, int> charToNum;
            unordered_map<int, char> numToChar;
            bool valid = true;

            for (int j = 0; j < n; j++) {
                char ch = k[j];
                int num = arr[j];

                // Check if the current character maps to the correct number
                if (charToNum.find(ch) != charToNum.end()) {
                    if (charToNum[ch] != num) {
                        valid = false;
                        break;
                    }
                } else {
                    charToNum[ch] = num;
                }

                // Check if the current number maps to the correct character
                if (numToChar.find(num) != numToChar.end()) {
                    if (numToChar[num] != ch) {
                        valid = false;
                        break;
                    }
                } else {
                    numToChar[num] = ch;
                }
            }

            if (valid)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
