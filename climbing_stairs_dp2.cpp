#include <stdio.h>

/* Climbing Stairs: Dynamic Programming with Space Optimization */
int climbingStairsDPComp(int n) {
    if (n == 1 || n == 2)
        return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}

int main() {
    int stairs;
    int result;

    printf("Enter the number of stairs: ");
    result = scanf("%d", &stairs);

    // Check if input was successfully read
    if (result != 1 || stairs <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int ways = climbingStairsDPComp(stairs);
    printf("There are %d distinct ways to climb %d stairs.\n", ways, stairs);

    return 0;
}
