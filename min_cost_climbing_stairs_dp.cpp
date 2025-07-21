#include <iostream>
#include <vector>
#include <algorithm> // For min function

using namespace std;

/* Climbing Stairs with Minimum Cost: Dynamic Programming */
int minCostClimbingStairsDP(vector<int>& cost) {
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];
    // Initialize dp table to store solutions to subproblems
    vector<int> dp(n + 1);
    // Base cases: preset solutions to smallest subproblems
    dp[1] = cost[1];
    dp[2] = cost[2];
    // State transition: solve larger subproblems using smaller ones
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return dp[n];
}

/* Climbing Stairs with Minimum Cost: Space-Optimized Dynamic Programming */
int minCostClimbingStairsDPComp(vector<int>& cost) {
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];
    int a = cost[1], b = cost[2];
    for (int i = 3; i <= n; i++) {
        int tmp = b;
        b = min(a, tmp) + cost[i];
        a = tmp;
    }
    return b;
}

int main() {
    // Example 1: Staircase with 3 steps
    vector<int> cost1 = { 0, 10, 15, 20 }; // Index 0 unused for 1-based indexing
    cout << "Example 1:" << endl;
    cout << "Cost array: ";
    for (int i = 1; i < cost1.size(); i++) {
        cout << cost1[i] << " ";
    }
    cout << endl;
    cout << "Minimum cost (standard DP): " << minCostClimbingStairsDP(cost1) << endl;
    cout << "Minimum cost (optimized DP): " << minCostClimbingStairsDPComp(cost1) << endl << endl;

    // Example 2: Staircase with more steps
    vector<int> cost2 = { 0, 1, 100, 1, 1, 100, 1, 1, 100, 1 };
    cout << "Example 2:" << endl;
    cout << "Cost array: ";
    for (int i = 1; i < cost2.size(); i++) {
        cout << cost2[i] << " ";
    }
    cout << endl;
    cout << "Minimum cost (standard DP): " << minCostClimbingStairsDP(cost2) << endl;
    cout << "Minimum cost (optimized DP): " << minCostClimbingStairsDPComp(cost2) << endl;

    return 0;
}
