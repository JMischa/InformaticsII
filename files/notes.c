#include <stdio.h>

// Function to find the maximum of three numbers
int max(int a, int b, int c) {
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    return c;
}

// Function to find the longest increasing path in a matrix
int longest_path(int x, int y, int M[x][y]) {
    int dp[x][y];
    int max_length = 1;

    // Initialize dp array with 1
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            dp[i][j] = 1;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (i > 0 && M[i][j] > M[i-1][j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + 1, dp[i][j]);
            }
            if (j > 0 && M[i][j] > M[i][j-1]) {
                dp[i][j] = max(dp[i][j], dp[i][j-1] + 1, dp[i][j]);
            }
            if (i > 0 && j > 0 && M[i][j] > M[i-1][j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1, dp[i][j]);
            }
            if (i > 0 && j < y-1 && M[i][j] > M[i-1][j+1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 1, dp[i][j]);
            }
            if (dp[i][j] > max_length) {
                max_length = dp[i][j];
            }
        }
    }

    return max_length;
}

int main() {
    int M[4][6] = {
        {1, 7, 3, 10, 6, 18},
        {3, 2, 5, 6, 9, 16},
        {6, 3, 2, 10, 12, 13},
        {8, 7, 5, 4, 8, 15}
    };
    int x = 4;
    int y = 6;

    printf("Longest increasing path in M is: %d\n", longest_path(x, y, M));

    return 0;
}
