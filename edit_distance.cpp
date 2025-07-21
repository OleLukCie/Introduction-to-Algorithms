#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Edit Distance: Dynamic Programming */
int editDistanceDP(string s, string t) {
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize first column
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }

    // Initialize first row
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                // Characters match, no operation needed
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                // Take minimum of insert, delete, replace + 1
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[n][m];
}

/* Edit Distance: Space-Optimized Dynamic Programming */
int editDistanceDPComp(string s, string t) {
    int n = s.length(), m = t.length();
    vector<int> dp(m + 1, 0);

    // Initialize first row
    for (int j = 1; j <= m; j++) {
        dp[j] = j;
    }

    // Fill the DP array
    for (int i = 1; i <= n; i++) {
        int leftup = dp[0]; // Store dp[i-1][j-1]
        dp[0] = i;         // Update first column for current row

        for (int j = 1; j <= m; j++) {
            int temp = dp[j]; // Save current value before update

            if (s[i - 1] == t[j - 1]) {
                // Characters match, use diagonal value
                dp[j] = leftup;
            }
            else {
                // Take minimum of available values + 1
                dp[j] = min(min(dp[j - 1], dp[j]), leftup) + 1;
            }

            leftup = temp; // Update for next iteration
        }
    }
    return dp[m];
}

int main() {
    string str1, str2;

    // Get input strings from user
    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);

    // Calculate edit distances using both methods
    int distance1 = editDistanceDP(str1, str2);
    int distance2 = editDistanceDPComp(str1, str2);

    // Output results
    cout << "\nEdit Distance Results:\n";
    cout << "Using standard DP: " << distance1 << endl;
    cout << "Using space-optimized DP: " << distance2 << endl;

    return 0;
}
