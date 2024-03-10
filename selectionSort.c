#include <stdio.h>

void selectionSort(int arr[], int n){
    int i,j,k,t;
    for(i = 0; i < n; i++){
        k = i;
        for (j = i+1; j<= n; j++){
            if (arr[j] < arr[k]){
                k = j;
        
            }
        }
    t = arr[i];
    arr[i] = arr[k];
    arr[k] = t;
    }
}

int main(){
    int arr[] = {3,5,1,2,9,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("unsorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    
    selectionSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
} 
