#include <stdio.h>
#include <stdlib.h>

int moveCount = 0;

/**
 * Move disk n from src to dst via aux
 * Hints:
 * 1. move n-1 disks from source to auxiliary via destination
 * 2. move the n-th disk from source to destination in 1 step
 * 3. move n-1 disks from source to destination via auxiliary
*/
void hanoi(int n, char src, char aux, char dst) {
   return;
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\nHanoi Tower Steps:\n");
    // you can change the name of the columns
    hanoi(n, 'A', 'B', 'C');

    printf("\nTotal number of moves: %d\n", moveCount);

    return 0;
}