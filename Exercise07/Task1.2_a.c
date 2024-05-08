#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 1000

int Q[MAX_QUEUE_SIZE];
int t;
int h;

void new(){
    t = 0;
    h = 0;
}

bool is_empty(){
    return(t == h);
}

int dequeue(){
    if(is_empty()){
    return -1;
    }
    
    int i = h;
    h = (h + 1) % MAX_QUEUE_SIZE;
    return Q[i];
}


int enqueue(int x){
    int next_index = (t + 1) % MAX_QUEUE_SIZE;
    if(next_index == h){
        return 0;
    }
    Q[t] = x;
    t = (t + 1) % MAX_QUEUE_SIZE;
    return 1;
}

void print_queue() {
    if (is_empty()) {
        printf("The queue is empty.\n");
        return;
    }

    printf("The queue is (from head to tail): ");
    int i;
    for (i = h; i != t; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", Q[i]);
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