#include <stdio.h>


void insertionSort(int arr[], int n){
    int i,j,key;
    int counter = 0;
    
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i-1;

        while (j >= 0 && key < arr[j]){
            counter++;
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    printf("Execution of inner loop: %d \n", counter);
}

int main(){
    int arr[] = {0,1,3,4,2,8,9,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("unsorted array: ");
    for(int i=0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("Sorted Array: ");
    for (int i= 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
