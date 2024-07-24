#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0)
            sum += i;
    }
    return (sum == num);
}

int main() {
    int limit;
    printf("Enter a limit: ");
    scanf("%d", &limit);

    printf("Perfect numbers up to %d are: ", limit);
    for (int i = 1; i <= limit; i++) {
        if (isPerfect(i))
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
