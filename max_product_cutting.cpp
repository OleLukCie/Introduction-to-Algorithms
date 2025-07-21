#include <stdio.h>
#include <math.h>

// Function to calculate maximum product of cutting a rope of length n
int maxProductCutting(int n) {
    if (n <= 3) {
        return 1 * (n - 1);
    }
    int a = n / 3;
    int b = n % 3;
    if (b == 1) {
        return (int)pow(3, a - 1) * 2 * 2;
    }
    if (b == 2) {
        return (int)pow(3, a) * 2;
    }
    return (int)pow(3, a);
}

// Main function to demonstrate the maxProductCutting function
int main() {
    int length;
    int scanResult;

    printf("Enter the length of the rope: ");
    scanResult = scanf("%d", &length);

    // Check if scanf successfully read an integer
    if (scanResult != 1) {
        printf("Error: Invalid input. Please enter an integer.\n");
        return 1; // Indicate error
    }

    if (length < 2) {
        printf("Error: Rope length must be at least 2.\n");
        return 1; // Indicate error
    }

    int maxProduct = maxProductCutting(length);
    printf("The maximum product for a rope of length %d is: %d\n", length, maxProduct);

    return 0; // Indicate successful execution
}
