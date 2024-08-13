#include <iostream>
using namespace std;

// Function to count the number of games Suneet wins
int countWins(int a1, int a2, int b1, int b2) {
    int winCount = 0;

    // Evaluate all 2x2 possible combinations of flips
    // Check each possible way of flipping cards to see if Suneet wins more rounds
    
    // Check scenario 1: (a1 vs b1) and (a2 vs b2)
    int suneetWins1 = (a1 > b1) + (a2 > b2);
    int slavicWins1 = (a1 < b1) + (a2 < b2);
    if (suneetWins1 > slavicWins1) winCount++;
    
    // Check scenario 2: (a1 vs b2) and (a2 vs b1)
    int suneetWins2 = (a1 > b2) + (a2 > b1);
    int slavicWins2 = (a1 < b2) + (a2 < b1);
    if (suneetWins2 > slavicWins2) winCount++;

    return winCount;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        cout << countWins(a1, a2, b1, b2) << endl;
    }
    return 0;
}
