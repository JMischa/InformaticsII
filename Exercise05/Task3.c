#include <stdio.h>
#include <math.h>

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
            j--;
        } while(array[j] > x);
        do{
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

int arraySortedOrNot(int array[], int n){
    if(n == 1 || n == 0){
        return 1;
    }
    return array[n-1] >= array[n-2] && arraySortedOrNot(array, n-1);
}

float median(int array[], int n){
    if(n % 2 == 0){
    int l = array[(n/2)-1];
    int r = array[(n/2)];
    return (float)(l + r)/2;
    }
    else{
        return (float) array[n/2];
    }
}

float findMedian(int array[], int n){
    if(n == 0){
        return 0;
    }
    if(arraySortedOrNot(array, n)){
        return median(array, n);
        }
    else{
        quickSort(array, 0, n -1);
        return median(array, n);
    }
}

int main(){
    int array[] = {5, 2, 8, 3, 7, 4};
    int n = sizeof(array)/sizeof(array[0]);
    float res = findMedian(array, n);
    printf("Median: %f", res);
    return 0;
}