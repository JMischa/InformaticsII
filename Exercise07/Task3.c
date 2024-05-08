#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node{
    int val;
    struct Node *next;
};

struct Node *head, *tail;

void new(){
    head = NULL;
    tail = NULL;
}

bool is_empty(){
    return(head == NULL && tail == NULL);
}

int dequeue(){
    if(is_empty()){
        return -1;
    }
    if(head == tail){
        int head_val = head -> val;
        free(head);
        head = tail = NULL;
        return head_val;
    }
    else{
        int head_val = head ->val;
        struct Node *temp = head;
        head = head -> next;
        free(temp);
        return head_val;
    }
}

void enqueue(int x){
    if(is_empty()){
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node -> val = x;
        new_node -> next = NULL;
        head = tail = new_node;
    }
    else{
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node -> val = x;
        new_node ->next = NULL;
        tail ->next = new_node;
        tail = new_node;
    }
}
void generate(int x){
    int printed = 0, current_val;
    new();
    enqueue(1);
    for(printed = 0; printed < x; printed ++){
        current_val = dequeue();
        printf("%d, ", current_val);
        enqueue(3 * current_val +1);
        enqueue(3 * current_val + 2);
    }
}

int main(){
    generate(8);
    return 0;
}