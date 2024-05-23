#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

int h(int k, int n){
    return (7 * k) % n;
}

int detectCycle(struct Node *l){
    int n = 10;
    int T[n];
    for(int i = 0; i < n; i++)
        T[i] = -1;
    
    struct Node *p = l;
    int i;
    while(p){
        printf("at %d\n", p ->val);
        i = h(p -> val, n);

        while(T[i] != -1){
            if(T[i] == p->val){
                printf("cycle detected\n");
                return 1;
            }
            i++;
        }
        T[i] = p -> val;
        p = p -> next;
    }
    printf("no cycle detected\n");
    return 0;
}

int main(){
    struct Node *head;

    head = malloc(sizeof(struct Node));
    head ->val = 1;

    head ->next = malloc(sizeof(struct Node));
    head ->next->val = 2;
     head->next->next = malloc(sizeof(struct Node));
    head->next->next->val = 3;

    head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->val = 6;

    /* without cycle */
    head->next->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->next->val =
        11; /* maps to same slot, but should not trigger cycle */

    /* with cycle */
    /* head->next->next->next->next = head->next; */

    detectCycle(head);

    return 0;
}