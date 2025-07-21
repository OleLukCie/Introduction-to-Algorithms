#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* Coin Change: Dynamic Programming */
int coinChangeDP(vector<int>& coins, int amt) {
    int n = coins.size();
    int MAX = amt + 1;
    // Initialize DP table
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));
    // Base case: first row (no coins available)
    for (int a = 1; a <= amt; a++) {
        dp[0][a] = MAX;
    }
    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // Cannot use the i-th coin
                dp[i][a] = dp[i - 1][a];
            }
            else {
                // Choose the minimum between not using and using the i-th coin
                dp[i][a] = min(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][amt] != MAX ? dp[n][amt] : -1;
}

/* Coin Change: Space-Optimized Dynamic Programming */
int coinChangeDPComp(vector<int>& coins, int amt) {
    int n = coins.size();
    int MAX = amt + 1;
    // Initialize DP array
    vector<int> dp(amt + 1, MAX);
    dp[0] = 0;  // Base case: 0 amount requires 0 coins
    // Fill DP array
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] <= a) {
                // Update only when current coin can be used
                dp[a] = min(dp[a], dp[a - coins[i - 1]] + 1);
            }
            // When coin value exceeds amount, no update is needed
        }
    }
    return dp[amt] != MAX ? dp[amt] : -1;
}

int main() {
    // Test case 1
    vector<int> coins1 = { 1, 5, 10, 25 };
    int amount1 = 36;
    cout << "Test Case 1:" << endl;
    cout << "Amount: " << amount1 << ", Coins: [1, 5, 10, 25]" << endl;
    cout << "Minimum coins (DP): " << coinChangeDP(coins1, amount1) << endl;
    cout << "Minimum coins (Optimized DP): " << coinChangeDPComp(coins1, amount1) << endl << endl;

    // Test case 2
    vector<int> coins2 = { 2 };
    int amount2 = 3;
    cout << "Test Case 2:" << endl;
    cout << "Amount: " << amount2 << ", Coins: [2]" << endl;
    cout << "Minimum coins (DP): " << coinChangeDP(coins2, amount2) << endl;
    cout << "Minimum coins (Optimized DP): " << coinChangeDPComp(coins2, amount2) << endl << endl;

    // Test case 3
    vector<int> coins3 = { 1, 2, 5 };
    int amount3 = 11;
    cout << "Test Case 3:" << endl;
    cout << "Amount: " << amount3 << ", Coins: [1, 2, 5]" << endl;
    cout << "Minimum coins (DP): " << coinChangeDP(coins3, amount3) << endl;
    cout << "Minimum coins (Optimized DP): " << coinChangeDPComp(coins3, amount3) << endl;

    return 0;
}
