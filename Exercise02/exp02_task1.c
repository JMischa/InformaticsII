#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Check the symbols in index i and index j
*/

int isPalindrome(char X[], int i, int j) {
    if (j<=i){
        return 1;
    }
    if (X[i] != X[j]) {
        return 0;
    }
    return isPalindrome(X, i+1, j-1);
}


int main(){
    char X[] = "1a_b3cD45t54Dc3b_a1";
    // put your code here
    if (isPalindrome(X)) {
        printf ("This is a Palindrom");
    }
    if (isPalindrome(X) == 0) {
        printf("This is not a palindrom %c:\n");
    }
}
