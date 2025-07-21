#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 0-1 Knapsack: Brute Force Search */
int knapsackDFS(vector<int>& wgt, vector<int>& val, int i, int c) {
    // If all items are selected or knapsack has no remaining capacity, return 0 value
    if (i == 0 || c == 0) {
        return 0;
    }
    // If exceeding knapsack capacity, can only choose not to put in the knapsack
    if (wgt[i - 1] > c) {
        return knapsackDFS(wgt, val, i - 1, c);
    }
    // Calculate maximum value of not putting in and putting in item i
    int no = knapsackDFS(wgt, val, i - 1, c);
    int yes = knapsackDFS(wgt, val, i - 1, c - wgt[i - 1]) + val[i - 1];
    // Return the greater value of the two schemes
    return max(no, yes);
}

/* 0-1 Knapsack: Memoized Search */
int knapsackDFSMem(vector<int>& wgt, vector<int>& val, vector<vector<int>>& mem, int i, int c) {
    // If all items are selected or knapsack has no remaining capacity, return 0 value
    if (i == 0 || c == 0) {
        return 0;
    }
    // If there is a record, return directly
    if (mem[i][c] != -1) {
        return mem[i][c];
    }
    // If exceeding knapsack capacity, can only choose not to put in the knapsack
    if (wgt[i - 1] > c) {
        return knapsackDFSMem(wgt, val, mem, i - 1, c);
    }
    // Calculate maximum value of not putting in and putting in item i
    int no = knapsackDFSMem(wgt, val, mem, i - 1, c);
    int yes = knapsackDFSMem(wgt, val, mem, i - 1, c - wgt[i - 1]) + val[i - 1];
    // Record and return the greater value of the two schemes
    mem[i][c] = max(no, yes);
    return mem[i][c];
}

/* 0-1 Knapsack: Dynamic Programming */
int knapsackDP(vector<int>& wgt, vector<int>& val, int cap) {
    int n = wgt.size();
    // Initialize dp table
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    // State transition
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                // If exceeding knapsack capacity, do not select item i
                dp[i][c] = dp[i - 1][c];
            }
            else {
                // The maximum value between not selecting and selecting item i
                dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][cap];
}

/* 0-1 Knapsack: Dynamic Programming with Space Optimization */
int knapsackDPComp(vector<int>& wgt, vector<int>& val, int cap) {
    int n = wgt.size();
    // Initialize dp table
    vector<int> dp(cap + 1, 0);
    // State transition
    for (int i = 1; i <= n; i++) {
        // Traverse in reverse order
        for (int c = cap; c >= 1; c--) {
            if (wgt[i - 1] <= c) {
                // The maximum value between not selecting and selecting item i
                dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[cap];
}

int main() {
    // Example: items with weights and corresponding values
    vector<int> weights = { 2, 3, 4, 5 };
    vector<int> values = { 3, 4, 5, 6 };
    int capacity = 8;
    int n = weights.size();

    // Test brute force search
    int maxValueDFS = knapsackDFS(weights, values, n, capacity);

    // Test memoized search
    vector<vector<int>> memo(n + 1, vector<int>(capacity + 1, -1));
    int maxValueMem = knapsackDFSMem(weights, values, memo, n, capacity);

    // Test dynamic programming
    int maxValueDP = knapsackDP(weights, values, capacity);

    // Test space-optimized dynamic programming
    int maxValueDPComp = knapsackDPComp(weights, values, capacity);

    // Output results
    cout << "0-1 Knapsack Problem Solutions:" << endl;
    cout << "Brute Force Search: " << maxValueDFS << endl;
    cout << "Memoized Search: " << maxValueMem << endl;
    cout << "Dynamic Programming: " << maxValueDP << endl;
    cout << "Space-Optimized DP: " << maxValueDPComp << endl;

    return 0;
}
