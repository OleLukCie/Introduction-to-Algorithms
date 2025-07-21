#include <iostream>
#include <vector>
using namespace std;

/* Backtracking function */
void backtrack(vector<int>& choices, int state, int n, vector<int>& res) {
    // When reaching the nth step, increment the count of solutions
    if (state == n)
        res[0]++;
    // Iterate through all possible choices
    for (auto& choice : choices) {
        // Pruning: do not allow exceeding the nth step
        if (state + choice > n)
            continue;
        // Try: make a choice and update the state
        backtrack(choices, state + choice, n, res);
        // Backtrack: no explicit action needed as we're using value passing
    }
}

/* Climbing stairs using backtracking */
int climbingStairsBacktrack(int n) {
    vector<int> choices = { 1, 2 }; // Can climb 1 or 2 steps at a time
    int state = 0;                // Start from step 0
    vector<int> res = { 0 };        // Use res[0] to record the number of solutions
    backtrack(choices, state, n, res);
    return res[0];
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = climbingStairsBacktrack(n);
    cout << "The number of distinct ways to climb " << n << " stairs is: " << result << endl;

    return 0;
}
