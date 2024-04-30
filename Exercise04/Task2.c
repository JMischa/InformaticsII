#include <stdio.h>

int maxOverlap(int A[], int l, int m, int r){
    int lsum = 0;
    int rsum = 0;
    
    int left = -9999;
    int right = -9999;

    for (int i = m; i>=l; i--){
        lsum += A[i];
        if (lsum > left){
            left = lsum;
        }
    }
    for (int i = m+1; i<=r; i++){
        rsum += A[i];
        if (rsum > right){
            right = rsum;
        }
    }
    return right + left;
}

int maxSubArray(int A[], int l, int r){
    if (l == r){
        return A[l];
    }

    if (l < r){
        int m = (l+r)/2;
        int left = maxSubArray(A, l, m);
        int right = maxSubArray(A, m+1, r);
        int overlap = maxOverlap(A, l, m, r);

        if (right > left && right > overlap){
            return right;
        }
        else if (left > right && left > overlap){
            return left;
        }
        else {
            return overlap;
        }
    }
    return 0;
}

void print_array(int A[], int n){
    for (int i = 0; i < n - 1; i++){
        printf("%d, ", A[i]);
    }
    printf("%d", A[n-1]);
}

int main(){
    int A[] = {-1, 2, -4, 1, 9, -6, 7, -3, 5};
    int n = sizeof(A)/sizeof(A[0]);

    int max_sum = maxSubArray(A, 0, n-1);
    
    printf("The sum of the maximum subarray in array A = [");
    print_array(A, n);
    printf("] is %d.", max_sum);
    return 0;
}