#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* Minimum path sum: Brute force search */
int minPathSumDFS(vector<vector<int>>& grid, int i, int j) {
    // Terminate search if reaching top-left cell
    if (i == 0 && j == 0) {
        return grid[0][0];
    }
    // Return +¡Þ cost if indices are out of bounds
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    // Calculate minimum path costs from top-left to (i-1, j) and (i, j-1)
    int up = minPathSumDFS(grid, i - 1, j);
    int left = minPathSumDFS(grid, i, j - 1);
    // Return minimum path cost from top-left to (i, j)
    return min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
}

/* Minimum path sum: Memoized search */
int minPathSumDFSMem(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j) {
    // Terminate search if reaching top-left cell
    if (i == 0 && j == 0) {
        return grid[0][0];
    }
    // Return +¡Þ cost if indices are out of bounds
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    // Return directly if already recorded
    if (mem[i][j] != -1) {
        return mem[i][j];
    }
    // Minimum path costs from left and top cells
    int up = minPathSumDFSMem(grid, mem, i - 1, j);
    int left = minPathSumDFSMem(grid, mem, i, j - 1);
    // Record and return minimum path cost from top-left to (i, j)
    mem[i][j] = min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
    return mem[i][j];
}

/* Minimum path sum: Dynamic programming */
int minPathSumDP(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    // Initialize dp table
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];
    // State transition: first row
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    // State transition: first column
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    // State transition: remaining rows and columns
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

/* Minimum path sum: Dynamic programming with space optimization */
int minPathSumDPComp(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    // Initialize dp array
    vector<int> dp(m);
    // State transition: first row
    dp[0] = grid[0][0];
    for (int j = 1; j < m; j++) {
        dp[j] = dp[j - 1] + grid[0][j];
    }
    // State transition: remaining rows
    for (int i = 1; i < n; i++) {
        // State transition: first column
        dp[0] = dp[0] + grid[i][0];
        // State transition: remaining columns
        for (int j = 1; j < m; j++) {
            dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    return dp[m - 1];
}

int main() {
    // Test case
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int n = grid.size();
    int m = grid[0].size();

    // Brute force search
    int result_dfs = minPathSumDFS(grid, n - 1, m - 1);
    cout << "Brute force search result: " << result_dfs << endl;

    // Memoized search
    vector<vector<int>> mem(n, vector<int>(m, -1));
    int result_mem = minPathSumDFSMem(grid, mem, n - 1, m - 1);
    cout << "Memoized search result: " << result_mem << endl;

    // Dynamic programming
    int result_dp = minPathSumDP(grid);
    cout << "Dynamic programming result: " << result_dp << endl;

    // Dynamic programming with space optimization
    int result_dp_comp = minPathSumDPComp(grid);
    cout << "Space-optimized DP result: " << result_dp_comp << endl;

    return 0;
}
