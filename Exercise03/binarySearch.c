#include <stdio.h>
#include <math.h>


int binary_search(int A[], int n, int t) {
    // write your code
    int l = 0;
    int r = n - 1;
    int m = floor((l+r)/2);

    while(l <= r && t != A[m]){
        if(t < A[m]){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
        m = floor((l + r)/2);
    }
    if(l <= r){
        return 1;
    }
    return 0; // not found
}

int main() {
    // Test array
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the target value to search: ");
    scanf("%d", &target);
    // Perform binary search
    int result = binary_search(arr, n, target);

    // Display result
    if (result)
        printf("%d is found in the array.\n", target);
    else
        printf("%d is not found in the array.\n", target);

    return 0;
}

