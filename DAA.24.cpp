#include <stdio.h>

// Function to reverse a number using recursion
int reverseNumber(int num, int rev) {
    if (num == 0)
        return rev;
    else {
        int digit = num % 10;
        rev = rev * 10 + digit;
        return reverseNumber(num / 10, rev);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int reversedNum = reverseNumber(num, 0);
    printf("Reverse of %d is %d\n", num, reversedNum);

    return 0;
}
