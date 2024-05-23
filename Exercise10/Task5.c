#include <stdio.h>
#include <stdlib.h>

#define N 10


int h1(int x){
    return x % N;
}

int h2(int x){
    return (int)(.1 * x) % N;
}

void printT(int *T) {
    for (int i = 0; i < N; ++i) {
        printf("%d,", T[i]);
    }
    printf("\n");
}

int cuckooInsert(int *T1, int *T2, int x){
    int y;
    int max_loop = 50;
    while(max_loop-- != 0){
        if(T1[h1(x)] == -1){
            T1[h1(x)] = x;
            return 0; 
        }
        y = T1[h1(x)];
        T1[h1(x)] = x;
        
        if(T2[h2(y)] == -1){
            T2[h2(y)] = y;
            return 0;
        }
        x = T2[h2(y)];
        T2[h2(y)] = y;
    }
    return -1;
}

int cuckooSearch(int *T1, int *T2, int x){
    if(T1[h1(x)] == x){
        printf("%d is in T1 at position: %d\n", x, h1(x));
    }
    else if(T2[h2(x)] == x){
        printf("%d is in T2 at position: %d\n", x, h2(x));
    }
    else{
        printf("%d is not in T1 and T2\n", x);
    }
}

int main(int argc, char *argv[]) {
    int T1[N];
    int T2[N];

    /* init tables */
    for (int i = 0; i < N; ++i) {
        T1[i] = -1;
        T2[i] = -1;
    }

    int n = 3;
    int vals[] = {44, 236, 36, 136};

    printf("T1: ");
    printT(T1);
    printf("T2: ");
    printT(T2);

    printf("inserting...\n");

    for (int i = 0; i < n; ++i) {
        cuckooInsert(T1, T2, vals[i]);
    }
    printf("T1: ");
    printT(T1);
    printf("T2: ");
    printT(T2);

    cuckooSearch(T1, T2, 44);

    return 0;
}