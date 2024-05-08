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

void print_queue() {
    if (is_empty()) {
        printf("The queue is empty.\n");
        return;
    }

    printf("The queue is (from head to tail): ");
    for (struct Node *node = head; node != NULL; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");
}

int main() {
    new();
    printf("The initial queue is empty: %d\n", is_empty());
    printf("I now enqueue the values 3, 4 and 2\n");
    enqueue(3);
    enqueue(4);
    enqueue(2);
    print_queue();
    printf("I now dequeue (remove from the head)\n");
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Enqueued value: 10\n");
    enqueue(10);
    print_queue();
    printf("Enqueued value: 20\n");
    enqueue(20);
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    return 0;
}