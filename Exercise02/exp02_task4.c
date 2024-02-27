#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Find the position of the operator with the lowest 
 * priority between index h and index t
*/
int findOperator(char *expr, int h, int t) {
    // use count to make sure the current operator are not inside of a pair of '()'
    // because the ops inside '()' have higher priority
    int count = 0;
    
    // looking for '+' or '-'
    ...

    // looking for '*' or '/'
    ...

    // -1 means no operator
    return -1;
}

/**
 * Calculate the result of the expression between index h and index t
*/
float calculator(char *expr, int h, int t) {

    // check if both sides have a pair of ()
    // remove them because they don't make any sense
    // !!!! Attension! You must check if the '(' and ')' are paired
    ...

    int opIndex = findOperator(expr, h, t);
    // printf("op idx %d", opIndex);

    
    if (...) {
        // no operator or the given expr is a negative number (-xxx)
        // Hint: use atoi() to convert numerical string to number
    }
    else {
        // do the math
    }
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);
    
    // Remove trailing newline character
    if (expr[strlen(expr) - 1] == '\n') {
        expr[strlen(expr) - 1] = '\0';
    }

    float result = calculator(expr, 0, strlen(expr) - 1);
    printf("\nAns = %f\n", result);

    return 0;
}