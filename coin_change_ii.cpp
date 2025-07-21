#include <iostream>
#include <vector>

using namespace std;

/* Coin Change II: Dynamic Programming */
int coinChangeIIDP(vector<int>& coins, int amount) {
    int n = coins.size();
    // Initialize dp table
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    // Initialize first column
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    // State transition
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amount; a++) {
            if (coins[i - 1] > a) {
                // If exceeding target amount, don't select coin i
                dp[i][a] = dp[i - 1][a];
            }
            else {
                // Sum of two options: not selecting and selecting coin i
                dp[i][a] = dp[i - 1][a] + dp[i][a - coins[i - 1]];
            }
        }
    }
    return dp[n][amount];
}

/* Coin Change II: Space-optimized Dynamic Programming */
int coinChangeIIDPComp(vector<int>& coins, int amount) {
    int n = coins.size();
    // Initialize dp array
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    // State transition
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amount; a++) {
            if (coins[i - 1] > a) {
                // If exceeding target amount, don't select coin i
                dp[a] = dp[a];
            }
            else {
                // Sum of two options: not selecting and selecting coin i
                dp[a] = dp[a] + dp[a - coins[i - 1]];
            }
        }
    }
    return dp[amount];
}

int main() {
    // Example test case
    vector<int> coins = { 1, 2, 5 };
    int targetAmount = 5;

    // Calculate using standard DP approach
    int resultDP = coinChangeIIDP(coins, targetAmount);
    // Calculate using space-optimized DP approach
    int resultDPComp = coinChangeIIDPComp(coins, targetAmount);

    // Output results
    cout << "Number of ways to make amount " << targetAmount << " using the given coins:" << endl;
    cout << "Standard DP approach: " << resultDP << endl;
    cout << "Space-optimized DP approach: " << resultDPComp << endl;

    return 0;
}
