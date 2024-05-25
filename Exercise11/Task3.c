#include <stdio.h>

const int INF = 1000000;

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}


int max_value(int n, int w[], int v[], int W){
    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(i >= 1 && j < w[i]){
                dp[i][j] = dp[i-1][j];
            }
            else if(i >= 1 && j >= w[i]){
                dp[i][j]= max(dp[i-1][j], dp[i-1][j-w[i]]+ v[i]);
            }
            else{
                dp[i][j] = -INF;
            }
        }
    }
    int final_answer = 0;
    for(int i = 0; i <= W; i++){
        final_answer = max(final_answer, dp[n][i]);
    }
    return final_answer;
}

int main() {
    int n = 5, w[] = {0, 2, 4, 5, 3, 9}, v[] = {0, 3, 5, 8, 4, 10}, W = 20;
    printf("The max value is: %d", max_value(n, w, v, W));
    return 0;
}
