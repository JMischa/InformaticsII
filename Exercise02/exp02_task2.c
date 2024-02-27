#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N = 8;
int count = 0;

void printBoard(int board[N][N]) {
    printf("Solution %d:\n", count);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Check if it's safe to place a new Queen in the given position
*/
int isSafe(int board[N][N], int row, int col) {

    return 1;
}


/**
 * Try to place N queens in the board 
 * and update the global variable 'count'
*/
void solveNQueens(int board[N][N], int row) {
    if (...) {
        count++;
        // printBoard(board);
        return;
    }

    // try to place the queen col by col
    ...
}

int main() {
    int board[N][N];
    memset(board, 0, sizeof(board));

    // try to place the queen row by row
    solveNQueens(..., ...);

    printf("Total solutions: %d\n", count);

    return 0;
}