#include <stdio.h>


void insertionSort(int arr[], int n){
    int i,j,key;
    
    for(i = 2; i < n; i++){
        key = arr[i];
        j = i-1;

        while (j >= 1 && key < arr[j]){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {3,5,1,2,9,7,8};
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
