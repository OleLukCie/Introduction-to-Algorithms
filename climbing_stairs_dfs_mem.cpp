#include <iostream>
#include <vector>
using namespace std;

/* Memoization search */
int dfs(int i, vector<int>& mem) {
    // Known values for dp[1] and dp[2], return them directly
    if (i == 1 || i == 2)
        return i;
    // If dp[i] is already recorded, return it
    if (mem[i] != -1)
        return mem[i];
    // dp[i] = dp[i-1] + dp[i-2]
    int count = dfs(i - 1, mem) + dfs(i - 2, mem);
    // Record dp[i]
    mem[i] = count;
    return count;
}

/* Climbing stairs: memoization search */
int climbingStairsDFSMem(int n) {
    // mem[i] records the total number of ways to climb to the i-th step, -1 means unrecorded
    vector<int> mem(n + 1, -1);
    return dfs(n, mem);
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int result = climbingStairsDFSMem(n);
    cout << "There are " << result << " distinct ways to climb " << n << " stairs." << endl;

    return 0;
}
