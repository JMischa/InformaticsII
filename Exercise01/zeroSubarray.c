#include <stdio.h>


void zeroSubarray(int const A[], int length){
    int res = 0;
    for(int i = 0; i < length; i++){
        int sum = 0;
        for(int j = i; j < length; j++){
            sum += A[j];
            if(sum == 0){
                res = 1;
            }
        }
    }
    printf("Solution: %d", res);
}
int main(){
    int A[] = {0,-2,4,2,1,-5};
    int length = sizeof(A)/sizeof(A[0]);
    zeroSubarray(A, length);
    return 0;
}
