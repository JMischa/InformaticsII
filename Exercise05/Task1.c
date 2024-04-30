# include <stdio.h>

int leftChild(int index){
    return 2 * index + 1;
}
int rightChild(int index){
    return 2 * index + 2;
}

void swap(int array[], int index1, int index2){
    int tmp = array[index2];
    array[index2] = array[index1];
    array[index1] = tmp;
}

int controlMaxHeap(int array[], int currentIndex, int length){
    int leftIndex = leftChild(currentIndex);
    if(leftIndex < length){
        if(array[currentIndex] < array[leftIndex]){
            return currentIndex;
        }
        int leftViolation = controlMaxHeap(array, leftIndex, length);
        if(leftViolation != -1){
            return leftViolation;
        }
    }
    int rightIndex = rightChild(currentIndex);
    if(rightIndex < length){
        if(array[currentIndex] < array[rightIndex]){
            return currentIndex;
        }
        int rightViolation = controlMaxHeap(array, rightIndex, length);
        if(rightViolation != -1){
            return rightViolation;
        }
    }
    return -1;
}

void heapify(int array[], int currentIndex, int length){
    int m = currentIndex;
    int l = leftChild(currentIndex);
    int r = rightChild(currentIndex);
    if((l <= length) && (array[l] > array[m])){
        m = l;
    }
    if((r <= length) && (array[r] > array[m])){
        m = r;
    }
    if(currentIndex != m){
        swap(array, m, currentIndex);
        heapify(array, m, length);
    }
}

void fixHeap(int array[], int length){
    int problemIndex = controlMaxHeap(array, 0, length);
    while(problemIndex != -1){
        heapify(array, problemIndex, length);
        problemIndex = controlMaxHeap(array, 0, length);
    }
}

int main(){
    int array[] = {5,5,3,2,1,6};
    int length = sizeof(array)/sizeof(array[0]);
    int res = controlMaxHeap(array, 0, length);
    printf("%d", res);
    printf("\n");
    fixHeap(array, length);
    for (int i = 0; i < length; i++){
        printf("%d", array[i]);
    }
    return 0;
}