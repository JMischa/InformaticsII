 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int closestNumber(int A[], int t, int n){
    int l = 0;
    int r = n;
    int closest = A[l];

    while(l <= r){
        int m = floor((l + r)/2);

        if(abs(A[m] - t) < abs(closest - t)){
            closest = A[m];
        }
        if(A[m] == t){
            return A[m];
        }
        else if(A[m] < t){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return closest;
}

int main(){
    int A[] = {1,2,3,4,7,8,9};
    int n = sizeof(A)/sizeof(A[0]);
    int t = 6;
    printf("Closest Number in the array: %d", closestNumber(A, t, n));
}
