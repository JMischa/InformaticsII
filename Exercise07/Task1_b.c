#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int val;
    struct Node *next;
};

struct Node *S;

void new(){
    S = NULL;
}

bool is_empty(){
    return (S == NULL);
}

int pop(){
    if(is_empty() == 1){
        return -1;
    }
    if(S ->next == NULL){
        int top_value = S ->val;
        S = NULL;
        return top_value;
    }
    else{
        int top_value = S ->val;
        struct Node *temp = S;
        S = S ->next;
        free(temp);
        return top_value;
    }
}

void push(int x){
    if(is_empty() == 1){
        S = malloc(sizeof(struct Node));
        S ->val  = x;
        S -> next = NULL;
    }
    else{
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node ->val = x;
        new_node ->next = S;
        S = new_node;
    }
}

void print_stack_helper(struct Node *node) {
    if (node != NULL) {
        print_stack_helper(node->next);
        printf("%d ", node->val);
    }
}

void print_stack() {
    if (is_empty() == 0) {
        printf("Stack is (from bottom to top): ");
        print_stack_helper(S);
        printf("\n");
    }
    else {
        printf("The stack is empty.\n");
    }
}

int main() {
    new();
    printf("The initial stack is empty: %d\n", is_empty());
    push(3);
    push(2);
    push(1);
    print_stack();
    printf("Popped item: %d\n", pop());
    print_stack();
    push(4);
    print_stack();
    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());
    print_stack();
    printf("Now I tried popping an empty stack: %d\n", pop());
    return 0;
}