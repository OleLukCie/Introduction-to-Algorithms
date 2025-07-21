#include <iostream>
#include <vector>

using namespace std;

/* Constrained Climbing Stairs: Dynamic Programming */
int climbingStairsConstraintDP(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    // Initialize dp table to store subproblem solutions
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    // Base cases: predefine solutions for smallest subproblems
    dp[1][1] = 1;  // 1 step to reach 1st stair
    dp[1][2] = 0;  // Can't reach 1st stair with 2 steps
    dp[2][1] = 0;  // Can't reach 2nd stair with 1 step (constraint)
    dp[2][2] = 1;  // 2 steps to reach 2nd stair
    // State transition: solve larger subproblems using smaller ones
    for (int i = 3; i <= n; i++) {
        // To end with 1 step at i, previous must end with 2 steps at i-1
        dp[i][1] = dp[i - 1][2];
        // To end with 2 steps at i, previous can end with either step at i-2
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    }
    // Total ways is sum of ending with 1 step or 2 steps
    return dp[n][1] + dp[n][2];
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int result = climbingStairsConstraintDP(n);
    cout << "Number of distinct ways to climb " << n << " stairs: " << result << endl;

    return 0;
}
