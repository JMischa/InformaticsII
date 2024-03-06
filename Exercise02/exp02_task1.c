#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Check the symbols in index i and index j
*/

int isPalindrome(char X[], int i, int j) {
    int length = strlen(X);
    for (i = 0, j = length -1; i < j; i++, j--) {
        if (X[i] != X[j]) {
            return 0;
        }
    }
    return 1;
}


int main() {
    char X[] = "1a_b3cD45t54Dc3b_a1";

    if (isPalindrome(X)) {
        printf("This is a Palindrome.");
    }
    else {
        printf("This is not a Palindrome.");
    }
    return 0;
}