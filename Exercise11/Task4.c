#include <stdio.h>

int sum(int n, int a[]){
    int total_sum = 0;
    for(int i = 0; i < n; i++){
        total_sum = total_sum + a[i];
    }
    return total_sum;
}


int max_cost(int n, int a[]){
    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = -1;
    }

    int i = 0;
    int j = n -1;
    for(int k = 1; k <= n; k++){
        if(a[i] <= a[j]){
            dp[i] = a[i] * k;
            i++;
        }
        else{
            dp[j] = a[j] * k;
            j--;
        }
    }
    return sum(n, dp);
}

int main(){
    int a[] = {3,2,4,1};
    int n = 4;

    printf("Max cost is: %d", max_cost(n, a));
    return 0;
}
