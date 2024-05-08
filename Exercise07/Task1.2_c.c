#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

struct Queue{
    struct Node **head, **tail;
};

struct Queue new(){
    struct Queue new_queue;
    new_queue.head = malloc(sizeof(struct Node*));
    new_queue.tail = malloc(sizeof(struct Node*));
    *(new_queue.head) = *(new_queue.tail) = NULL;
    return new_queue;
}

bool is_empty(struct Queue q){
    return(*(q.head) == NULL && *(q.tail) == NULL);
}

int dequeue(struct Queue q){
    if(is_empty(q)){
        return -1;
    }
    if(*(q.head) == *(q.tail)){
        int head_val = (*(q.head)) -> val;
        free(*(q.head));
        *(q.head) = *(q.tail) = NULL;
        return head_val;
    }
    else{
        int head_val = (*(q.head)) -> val;
        struct Node *temp = *(q.head);
        *(q.head) = (*(q.head)) -> next;
        free(temp);
        return head_val;
    }
}

void enqueue(struct Queue q, int x){
    if(is_empty(q)){
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node ->val = x;
        new_node ->next = NULL;
        *(q.head) = *(q.tail) = new_node;
    }
    else{
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node -> val = x;
        new_node -> next = NULL;
        (*(q.tail)) ->next = new_node,
        *(q.tail) = new_node;
    }
}

void print_queue(struct Queue q, char *name) {
    if (is_empty(q)) {
        printf("The queue %s is empty.\n", name);
        return;
    }

    printf("The queue %s is (from head to tail): ", name);
    for (struct Node *node = *(q.head); node != NULL; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");
}

int main() {
    struct Queue q1 = new();
    printf("The queue q1 is empty: %d\n", is_empty(q1));
    printf("I now enqueue the values 3, 4 and 2\n");
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 2);
    print_queue(q1, "q1");
    printf("I now dequeue (remove from the head)\n");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Enqueued value: 10\n");
    enqueue(q1, 10);
    print_queue(q1, "q1");
    printf("Enqueued value: 20\n");
    enqueue(q1, 20);
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));

    printf("\nNow I create another queue\n");
    struct Queue q2 = new();
    enqueue(q2, 12);
    enqueue(q2, 7);
    enqueue(q2, 9);
    print_queue(q2, "q2");

    printf("\nNow I transfer one element from q2 to q1:\n");
    enqueue(q1, dequeue(q2));
    print_queue(q1, "q1");
    print_queue(q2, "q2");
    return 0;
}