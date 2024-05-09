#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node{
    int val;
    struct Node *next;
};

struct Node **new(){
    struct Node **new_stack = malloc(sizeof(struct Node*));
    *new_stack = NULL;
    return new_stack;
}


bool is_empty(struct Node** S){
    return(*S == NULL);
}

int pop(struct Node** S){
    if(is_empty(S)){
        return -1;
    }
    int top_value;
    top_value = (*S) ->val;

    struct Node *temp = *S;
    *S = (*S) -> next;
    free(temp);
    return top_value;
}

void push(struct Node** S, int x){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node ->val = x;
    new_node ->next = *S;
    *S = new_node;
}

struct Node **sort_stack(struct Node **S){
    struct Node **all_elements = new();
    struct Node **temp_stack = new();
    int x, y;

    while(is_empty(S) == 0){
        push(all_elements, pop(S));
    }
    push(S, pop(all_elements));

    while(is_empty(all_elements) == 0){
        x = pop(all_elements);
        while(is_empty(S) == 0){
            y = pop(S);
            if(y < x){
                push(temp_stack, y);
            }
            else{
                push(S, y);
                break;
            }
        }
        push(S,x);
        while(is_empty(temp_stack) == 0){
            push(S, pop(temp_stack));
        }
    }
    return S;
}


void print_stack_helper(struct Node *node) {
    if (node != NULL) {
        print_stack_helper(node->next);
        printf("%d ", node->val);
    }
}

void print_stack(struct Node **S, char *name) {
    if (is_empty(S) == 0) {
        printf("Stack %s is (from bottom to top): ", name);
        print_stack_helper(*S);
        printf("\n");
    }
    else {
        printf("The stack %s is empty.\n", name);
    }
}

int main() {
    struct Node **S = new();
    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 4);
    print_stack(S, "S");
    S = sort_stack(S);
    print_stack(S, "S");
    return 0;
}
