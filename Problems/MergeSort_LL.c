#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int val;
    struct Node* next;
};



void printList(struct Node *head){
    struct Node *current = head;
    while(current != NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

void push(struct Node **head, int val){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node ->val = val;
    new_node ->next = *head;
    *head = new_node;
}

int main(){
    struct Node *head = NULL;

    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 5);
    push(&head, 9);
    push(&head, 7);

    head = mergeSort(head);

    printList(head);

    return 0;
}
