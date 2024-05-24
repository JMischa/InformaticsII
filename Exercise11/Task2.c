#include <stdio.h>

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}


int longest_path(int x, int y, int M[x][y]){
    int dp[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(i > 0 && j > 0 && M[i][j] > M[i-1][j] && M[i][j] > M[i][j-1]){
                dp[i][j] = 1 + max(dp[i-1][j], dp[i][j-1]);
            }
            else if(i > 0 && M[i][j] > M[i-1][j]){
                dp[i][j] = dp[i-1][j] + 1;
            }
            else if(j >0 && M[i][j] > M[i][j-1]){
                dp[i][j] = dp[i][j-1] + 1;
            }
            else{
                dp[i][j] = 1;
            }
        }
    }

    int final_answer = 1;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            if(dp[i][j] > final_answer){
                final_answer = dp[i][j];
            }
        }
    }
    return final_answer;
}


int main(){
    int M[4][6] = {{1,7,3,10,6,18},{3,2,5,6,9,16},{6,3,2,10,12,13},{8,7,5,4,8,15}};
    int x = 4;
    int y = 6;

    printf("Longest increasing subsequence of M is: %d", longest_path(x, y, M));

    return 0;
}
