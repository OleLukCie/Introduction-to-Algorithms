#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Backtracking algorithm for N-Queens */
void backtrack(int row, int n, vector<vector<string>>& state, vector<vector<vector<string>>>& res, vector<bool>& cols,
    vector<bool>& diags1, vector<bool>& diags2) {
    // When all rows are placed, record the solution
    if (row == n) {
        res.push_back(state);
        return;
    }
    // Iterate through all columns
    for (int col = 0; col < n; col++) {
        // Calculate the main and secondary diagonals for this position
        int diag1 = row - col + n - 1;
        int diag2 = row + col;
        // Pruning: Skip if there's a queen in the same column or diagonals
        if (!cols[col] && !diags1[diag1] && !diags2[diag2]) {
            // Try: Place queen in this position
            state[row][col] = "Q";
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            // Place next row
            backtrack(row + 1, n, state, res, cols, diags1, diags2);
            // Backtrack: Remove queen from this position
            state[row][col] = "#";
            cols[col] = diags1[diag1] = diags2[diag2] = false;
        }
    }
}

/* Solve N-Queens problem */
vector<vector<vector<string>>> nQueens(int n) {
    // Initialize n*n chessboard, 'Q' represents queen, '#' represents empty space
    vector<vector<string>> state(n, vector<string>(n, "#"));
    vector<bool> cols(n, false);           // Record if there's a queen in each column
    vector<bool> diags1(2 * n - 1, false); // Record if there's a queen on main diagonals
    vector<bool> diags2(2 * n - 1, false); // Record if there's a queen on secondary diagonals
    vector<vector<vector<string>>> res;

    backtrack(0, n, state, res, cols, diags1, diags2);

    return res;
}

int main() {
    int n;
    cout << "Enter the number of queens (n): ";
    cin >> n;

    // Handle invalid input
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    vector<vector<vector<string>>> solutions = nQueens(n);

    cout << "Found " << solutions.size() << " solutions for " << n << "-Queens problem:" << endl << endl;

    // Print each solution
    for (size_t i = 0; i < solutions.size(); i++) {
        cout << "Solution " << (i + 1) << ":" << endl;
        for (const auto& row : solutions[i]) {
            for (const string& cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
