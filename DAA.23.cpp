#include <stdio.h>

// Function to calculate the binomial coefficient C(n, k) using dynamic programming
int binomialCoeff(int n, int k) {
    int C[n + 1][k + 1];

    // Initialize the first row and column to 1
    for (int i = 0; i <= n; i++)
        C[i][0] = 1;
    for (int j = 0; j <= k; j++)
        C[0][j] = 0;

    // Fill the table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k && j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

int main() {
    int n = 5;
    int k = 3;

    printf("Binomial coefficient C(%d, %d) is %d\n", n, k, binomialCoeff(n, k));

    return 0;
}
