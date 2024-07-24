#include <stdio.h>

// Function to find the optimal cost of a BST with keys from i to j
int optimalBST(int keys[], int freq[], int i, int j, int n) {
    int cost[n][n];

    // Initialize the cost matrix
    for (int k = 0; k < n; k++)
        cost[k][k] = freq[k];

    // Fill the cost matrix in a bottom-up manner
    for (int L = 2; L <= j - i + 1; L++) {
        for (int k = i; k < j - L + 2; k++) {
            int min_cost = INT_MAX;
            for (int r = k; r < k + L - 1; r++) {
                int c = ((r > k) ? cost[k][r - 1] : 0) + ((r < k + L - 1) ? cost[r + 1][k + L - 1] : 0) + sum(freq, k, k + L - 1);
                if (c < min_cost)
                    min_cost = c;
            }
            cost[k][k + L - 1] = min_cost;
        }
    }

    return cost[i][j];
}

// Function to calculate the sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Optimal cost of BST is %d\n", optimalBST(keys, freq, 0, n - 1, n));

    return 0;
}
