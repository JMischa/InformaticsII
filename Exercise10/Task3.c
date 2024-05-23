#include <stdio.h>
#include <stdlib.h>

#define N 10

void printHT(int *HT){
    for(int i = 0; i < N; i++){
        printf("%d,",HT[i]);
    }
    printf("\n");
}

int h1(int k, int i){
    return ((k + 4) + i) % N;
}

int HTinsert(int *T, int k){
    int probe = h1(k,0);
    int c = 0;

    while (T[probe] != -1 && c < N){
        c++;
        probe = h1(k,c);
    }
    if(c >= N){
        printf("full for %d\n", k);
        return -1;
    }
    T[probe] = k;
    return 0;
}

int HTdelete(int *T, int k){
    int probe = h1(k,0);
    int indexActual = probe;
    int c = 0;

    while(c < N && T[probe] != -1 && T[probe] != k){
        c++;
        probe = h1(k,c);
    }
    if(c >= N || T[probe] == -1){
        return  -1;
    }
    T[probe] = -1;

    int j = (probe + 1) % N;

    while(j != indexActual && T[j] != -1){
        if(h1(T[j],0) != j){
            int tmpK = T[j];
            T[j] = -1;
            HTinsert(T, tmpK);
        }
        j = (j + 1) % N;
    }
    return probe;
}

int HTsearch(int *T, int k){
    int probe = h1(k, 0);
    int c = 0;

    while(c < N && T[probe] != -1 && T[probe] != k){
        c++;
        probe = h1(k, c);
    }
    if(c >= N || T[probe] == -1){
        return -1;
    }
    return probe;
}




int main(int argc, char * argv[]){
    int T[N] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int vals[] = {32, 52, 33, 74, 96};

    for(int i = 0; i < N; i++){
        T[i] = -1;
    }
    for (int i = 0; i < 5; i++){
        HTinsert(T, vals[i]);
    }
    printf("Before del 33: ");
    printHT(T);

    HTdelete(T, 33);

    printf("After del 33:  ");
    printHT(T);

    printf("position of 74: ");
    int position = HTsearch(T, 74);
    printf("%d\n", position);

    return 0;
}
