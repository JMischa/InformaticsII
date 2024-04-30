#include <stdio.h>
#include <math.h>

int findMajorElement(int A[], int l, int r){
    // base case
    if(l == r){
        return A[l];
    }
    int m = floor((l+r)/2);

    int leftMajority = findMajorElement(A, l, m);
    int rightMajority = findMajorElement(A, m+1, r);

    if(leftMajority == rightMajority){
        return leftMajority;
    }
    int lcount = 0;
    int rcount = 0;

    for(int i = l; i <= r; i++){
        if(A[i] == leftMajority){
            lcount += 1;
        }
        else if(A[i] == rightMajority){
            rcount += 1;
        }
    }
    if(lcount >= rcount){
        return lcount;
    }
    else{
        return rcount;
    }
}
int printArray(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ,", A[i]);
    }
    printf("%d", A[n-1]);
    return 0;
}

int main(){
    int A[] = {1,3,1,7,1,1,5,1};
    int n = sizeof(A)/sizeof(A[0]);

    printf("The majority element in the array[");
    printArray(A, n);
    printf("] is: %d", findMajorElement(A,0, n-1));
    return 0;
}
