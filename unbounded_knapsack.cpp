#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Unbounded Knapsack: Dynamic Programming */
int unboundedKnapsackDP(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    // Initialize DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // State transition
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= capacity; c++) {
            if (weights[i - 1] > c) {
                // If exceeding capacity, don't select item i
                dp[i][c] = dp[i - 1][c];
            }
            else {
                // Maximum value between not selecting and selecting item i
                dp[i][c] = max(dp[i - 1][c], dp[i][c - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    return dp[n][capacity];
}

/* Unbounded Knapsack: Space-optimized Dynamic Programming */
int unboundedKnapsackDPComp(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    // Initialize DP array
    vector<int> dp(capacity + 1, 0);

    // State transition
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= capacity; c++) {
            if (weights[i - 1] > c) {
                // If exceeding capacity, don't select item i
                dp[c] = dp[c];  // Can be omitted, kept for clarity
            }
            else {
                // Maximum value between not selecting and selecting item i
                dp[c] = max(dp[c], dp[c - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    return dp[capacity];
}

int main() {
    // Example: item weights and values
    vector<int> weights = { 2, 3, 4 };
    vector<int> values = { 3, 5, 6 };
    int capacity = 10;  // Knapsack capacity

    // Calculate results with both methods
    int result1 = unboundedKnapsackDP(weights, values, capacity);
    int result2 = unboundedKnapsackDPComp(weights, values, capacity);

    // Output results
    cout << "Unbounded Knapsack Problem Results:" << endl;
    cout << "Solution using 2D DP table: " << result1 << endl;
    cout << "Space-optimized solution: " << result2 << endl;

    return 0;
}
