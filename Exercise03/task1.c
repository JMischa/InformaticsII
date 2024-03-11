#include <stdio.h>
#include <time.h> // measuring run time
#include <math.h>

int n, t;
int A[100000000];

int linear_search(int A[], int n, int t) {
    // write you code

    for(int i = 0; i < n; i++){
        if(A[i] == t){
            return 1;
        }
    }
    return 0; // not found
}

int binary_search(int A[], int n, int t) {
    // write your code
    int l = 1;
    int r = n;
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
    clock_t start, end;
    printf("Enter an integer for n: ");
    scanf("%d", &n); 
    printf("Generate an array with %d distinct integers from 1 to %d.\n", n, n);
    for(int i = 0; i < n; i++) A[i] = i + 1;
    printf("Enter an integer for t: \n");
    scanf("%d", &t); 
    start = clock();
    int index = linear_search(A, n, t); // your implementation
    if(index == 1){
        printf("Value is in the array");
    }
    else{
        printf("Value is not in the array");
    }
    end = clock();
    double run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Linear search takes : %f millseconds\n", run_time); 

    start = clock();
    int res = binary_search(A, n, t); // your implementation
    if(res == 1){
        printf("Number was found: %d", t);
    }
    else{
        printf("Number was not in the array");
    }
    end = clock();
    run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Binary search takes : %f millseconds\n", run_time); 
}
