#include <stdio.h>

void bubbleSort(int arr[], int n){
    int i, j, t;
    int counter = 0;

    for (i = n-1; i >=0; i--){
        for(j = 1; j<= i; j++){
            counter ++;
            if(arr[j] < arr[j-1]){
                t = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = t;
            }
        }
    }
    printf("Execution of inner loop: %d \n", counter);
}

int main(){
    int arr[] = {0,1,3,4,2,8,9,5,6,7};
    int n = sizeof(arr)/ sizeof(arr[0]);

    printf("unsorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n);
    printf("sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
