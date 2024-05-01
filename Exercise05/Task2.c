#include <stdio.h>

int counter = 0;

void swap(int array[], int index1, int index2){
    int tmp = array[index2];
    array[index2] = array[index1];
    array[index1] = tmp;
}

int hoarePartition(int array[], int leftIndex, int rightIndex){
    int x = array[rightIndex];
    int i = leftIndex - 1;
    int j = rightIndex + 1;
    while(1){
        do{
            counter++;
            j--;
        } while(array[j] > x);
        do{
            counter++;
            i++;
        }while(array[i] < x);
        if(i >= j){
            return i;
        }
        swap(array, i, j);
    }
}

void quickSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        int m = hoarePartition(array, leftIndex, rightIndex);
        quickSort(array, leftIndex, m-1);
        quickSort(array, m, rightIndex);
    }
}


int main(){
    int array[] = {9,8,7,6,5,4,3,2,1,0};
    int lenght = sizeof(array)/sizeof(array[0]);
    int res = hoarePartition(array, 0, lenght -1);
    printf("%d \n", res);
    for(int i = 0; i < lenght; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
    quickSort(array, 0, lenght -1);
    for(int i = 0; i < lenght; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
    printf("Counter: %d", counter);
    return 0;
}