#include "stdio.h"

void snippet1() {
    int a = 2147483647;
    int b = 2147483648;
    int c = 2147483649;
    printf("%d, %d, %d", a, b, c);
}

void snippet2() {
    int myArray[20];
    for (int i = 0; i < 20; i++) {
        printf("%d \n", myArray[i]);
    }
}

void snippet3() {
    int myArray[1];
    myArray[0] = 0;
    myArray[1] = 1;
    myArray[2] = 2;
    printf("%d, %d, %d", myArray[0], myArray[1], myArray[2]);
}

void snippet4() {
    int myArray[] = {72, 101, 108, 108, 111, 32,
                     87, 111, 114, 108, 100, 33};
    for (int i = 0; i < 12; i++) {
        printf("%d", myArray[i]);
    }
    printf("\n");
    for (int i = 0; i < 12; i++) {
        printf("%c", myArray[i]);
    }
}

void snippet5() {
    int myArray[5];
    int size1 = sizeof(myArray);
    int size2 = sizeof(myArray[0]);
    int size3 = size1 / size2;
    printf("%d, %d, %d", size1, size2, size3);
}

void snippet6() {
    char myString[] = "hello";
    int stringSize = sizeof(myString) / sizeof(myString[0]);
    printf("%d, ", stringSize);
    for (int i = 0; i < stringSize; i++) {
        printf("%c", myString[i]);
    }
}

int main() {
    //The desired snippet can be called by modifying the next line
    snippet6();
    return 0;
}
