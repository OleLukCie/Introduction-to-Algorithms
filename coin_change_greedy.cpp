#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Coin Change: Greedy Algorithm */
int coinChangeGreedy(vector<int>& coins, int amt) {
    // Assume coins list is sorted
    int i = coins.size() - 1;
    int count = 0;
    // Loop to make greedy choices until no remaining amount
    while (amt > 0) {
        // Find the largest coin less than or equal to remaining amount
        while (i > 0 && coins[i] > amt) {
            i--;
        }
        // If even the smallest coin is larger than remaining amount, no solution
        if (coins[i] > amt) {
            return -1;
        }
        // Choose coins[i]
        amt -= coins[i];
        count++;
    }
    // Return the count if successful, -1 otherwise
    return amt == 0 ? count : -1;
}

int main() {
    // Example 1: US coins (works with greedy)
    vector<int> usCoins = { 1, 5, 10, 25 };
    int amount1 = 37;
    int result1 = coinChangeGreedy(usCoins, amount1);

    cout << "Example 1:" << endl;
    cout << "Coins available: 1, 5, 10, 25" << endl;
    cout << "Amount to make: " << amount1 << endl;
    if (result1 != -1) {
        cout << "Minimum coins needed (greedy): " << result1 << endl;
    }
    else {
        cout << "Cannot make amount " << amount1 << " with given coins" << endl;
    }

    // Example 2: Coins that demonstrate limitation of greedy algorithm
    vector<int> badCoins = { 1, 3, 4 };
    int amount2 = 6;
    int result2 = coinChangeGreedy(badCoins, amount2);

    cout << "\nExample 2:" << endl;
    cout << "Coins available: 1, 3, 4" << endl;
    cout << "Amount to make: " << amount2 << endl;
    if (result2 != -1) {
        cout << "Coins from greedy algorithm: " << result2 << endl;
    }
    else {
        cout << "Cannot make amount " << amount2 << " with given coins" << endl;
    }
    cout << "Note: Optimal solution is 2 coins (3+3)" << endl;

    return 0;
}
