#include <stdio.h>

int algo1(int A[], int n, int k){
    int sum = 0;
    for(int i = 0; i < k; i++){
        int maxi = i;
        for(int j = i; j < n; j++){
            if(A[j] > A[maxi]){
                maxi = j;
            }
        }
    sum += A[maxi];
    int swp = A[i];
    A[i] = A[maxi];
    A[maxi] = swp;
    }
    return sum;
}



int main(){
    int A[] = {1,4,5,8,9,3,2,5,6,1,2,9,};
    int n = sizeof(A)/sizeof(A[0]);
    int k = 2;
    printf("Sum result of algo1: %d", algo1(A, n, k));
}
