#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *new_stack() {
    struct Node *new_stack = malloc(sizeof(struct Node));
    new_stack->next = NULL;
    return new_stack;
}

bool is_empty(struct Node *S) {
    return (S == NULL);
}

int pop(struct Node **S) {
    if (is_empty(*S)) {
        return -1;
    }
    int top_value = (*S)->val;

    struct Node *temp = *S;
    *S = (*S)->next;
    free(temp);
    return top_value;
}

void push(struct Node **S, int x) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->val = x;
    new_node->next = *S;
    *S = new_node;
}

int peek(struct Node *S) {
    if (is_empty(S)) {
        return INT_MIN;
    }
    return S->val;
}

void sort_stack(struct Node **S) {
    struct Node *temp_stack = new_stack();

    while (!is_empty(*S)) {
        int temp = pop(S);
        while (!is_empty(temp_stack) && peek(temp_stack) < temp) {
            push(S, pop(&temp_stack));
        }
        push(&temp_stack, temp);
    }
    *S = temp_stack;
}

void printStack(struct Node *S) {
    while (S != NULL) {
        printf("%d ", S->val);
        S = S->next;
    }
    printf("\n");
}

// Driver program
int main() {
    struct Node *S = NULL;
    push(&S, 30);
    push(&S, -5);
    push(&S, 18);
    push(&S, 14);
    push(&S, -3);

    printf("Stack before sorting: ");
    printStack(S);

    sort_stack(&S);

    printf("\nStack after sorting: ");
    printStack(S);

    return 0;
}
