#include <iostream>
#include <vector>
using namespace std;

/* Climbing Stairs: Dynamic Programming */
int climbingStairsDP(int n) {
    if (n == 1 || n == 2)
        return n;
    // Initialize dp table to store subproblem solutions
    vector<int> dp(n + 1);
    // Base cases: pre-set solutions for smallest subproblems
    dp[1] = 1;
    dp[2] = 2;
    // State transition: solve larger subproblems using smaller ones
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int stairs;
    cout << "Enter the number of stairs: ";
    cin >> stairs;

    if (stairs <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int ways = climbingStairsDP(stairs);
    cout << "There are " << ways << " distinct ways to climb " << stairs << " stairs." << endl;
    cout << "(You can climb 1 or 2 steps at a time)" << endl;

    return 0;
}
