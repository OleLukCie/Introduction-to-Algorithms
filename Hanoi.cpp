#include <iostream>
#include <vector>
using namespace std;

/* Move one disk from source to target */
void move(vector<int>& src, vector<int>& tar) {
    // Take the top disk from source
    int pan = src.back();
    src.pop_back();
    // Put the disk on target
    tar.push_back(pan);
}

/* Solve Tower of Hanoi problem recursively */
void dfs(int i, vector<int>& src, vector<int>& buf, vector<int>& tar) {
    // If only one disk remains, move it directly
    if (i == 1) {
        move(src, tar);
        return;
    }
    // Subproblem f(i-1): move i-1 disks from src to buf using tar as buffer
    dfs(i - 1, src, tar, buf);
    // Subproblem f(1): move the remaining disk from src to tar
    move(src, tar);
    // Subproblem f(i-1): move i-1 disks from buf to tar using src as buffer
    dfs(i - 1, buf, src, tar);
}

/* Main function to solve Tower of Hanoi with empty check */
void solveHanoi(vector<int>& A, vector<int>& B, vector<int>& C) {
    // Check if source tower is empty to prevent unnecessary operations
    if (A.empty()) {
        cerr << "Source tower A is empty - no disks to move" << endl;
        return;
    }

    int n = A.size();
    // Move n disks from A to C using B as buffer
    dfs(n, A, B, C);
}

// Helper function to print the state of pegs
void printPegs(const vector<int>& A, const vector<int>& B, const vector<int>& C) {
    cout << "A: ";
    for (int disk : A) cout << disk << " ";
    cout << "\nB: ";
    for (int disk : B) cout << disk << " ";
    cout << "\nC: ";
    for (int disk : C) cout << disk << " \n\n";
}

int main() {
    // Test with normal case
    cout << "Test case 1: Normal scenario\n";
    vector<int> A = { 3, 2, 1 };
    vector<int> B;
    vector<int> C;

    cout << "Initial state:\n";
    printPegs(A, B, C);

    solveHanoi(A, B, C);

    cout << "Final state:\n";
    printPegs(A, B, C);

    // Test with empty source
    cout << "Test case 2: Empty source tower\n";
    vector<int> A_empty;
    vector<int> B2;
    vector<int> C2;

    solveHanoi(A_empty, B2, C2);

    return 0;
}
