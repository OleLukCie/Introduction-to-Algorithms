#include <stdio.h>

/* Search */
int dfs(int i) {
    // dp[1] and dp[2] are known, return them
    if (i == 1 || i == 2)
        return i;
    // dp[i] = dp[i-1] + dp[i-2]
    int count = dfs(i - 1) + dfs(i - 2);
    return count;
}

/* Climbing Stairs: Search */
int climbingStairsDFS(int n) {
    return dfs(n);
}

int main() {
    int stairs;
    int result;

    printf("Enter the number of stairs: ");
    result = scanf("%d", &stairs);

    // Check if scanf succeeded in reading an integer
    if (result != 1) {
        printf("Error: Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    if (stairs <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return 1;
    }

    int ways = climbingStairsDFS(stairs);
    printf("There are %d ways to climb %d stairs.\n", ways, stairs);

    return 0;
}
