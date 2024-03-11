#include <stdio.h>


int k_largest_int(int A[], int n, int k){
    int result = -1000;

    for(int i = 0; i < n; i++){
        int current = 0;
        for(int j = i; j < n; j+= k){
            current = current + A[j];
        }
        if(current > result){
            result = current;
        }
    }
    return result;
}


int main(){
    int A[] = {3,5,6,1,3,8,9,4,0,23,56,5};
    int n = sizeof(A)/ sizeof(A[0]);
    int k = 1;
    printf("Sum of k-th elements in array: %d", k_largest_int(A, n, k));
}
