#include <stdio.h>

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}


int max_cost(int n, int a[]){
    int dp[n+1][n+1];

    dp[1][n] = 0;

    for(int length = n-1; length >= 1; length --){
        for(int i = 1; i <= n -length + 1; i++){
            int j = i + length - 1;
            if(i > 1 && j < n){
                dp[i][j] = max((n-j+i-1) *a[i-1] + dp[i-1][j], (n-j+i-1) * a[j+1] + dp[i][j+1]);
            }
            else if(i > 1){
                dp[i][j] = (n-j+i-1)* a[i-1] + dp[i-1][j];
            }
            else if(j < n){
                dp[i][j] = (n-j+i-1)* a[j+1] + dp[i][j+1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int final_answer = 0;
    for(int i = 1; i <= n; i++){
        final_answer = max(final_answer, dp[i][i] + n*a[i]);
    }
    return final_answer;
}

int main(){
    int a[]= {0,3,2,4,1};
    printf("Max cost: %d", max_cost(4, a));
    return 0;
}