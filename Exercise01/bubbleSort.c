#include <stdio.h>

void bubbleSort(int arr[], int n){
    int i, j, t;

    for (i = n-1; i >=0; i--){
        for(j = 1; j<= i; j++){
            if(arr[j] < arr[j-1]){
                t = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = t;
            }
        }
    }
}

int main(){
    int arr[] = {3,1,5,8,3,9,2};
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
