#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

struct Node *get_previous_node(struct Node *head, struct Node *a){
    if(head == NULL || a == NULL){
        return NULL;
    }
    else if(head->next == a){
        return head;
    }
    struct Node *prev = head;
    while(prev != NULL && prev->next != a){
        prev = prev->next;
    }
    return prev;
}

struct Node *swap_nodes(struct Node *head, struct Node *a, struct Node *b) {
    struct Node *prev_a;
    struct Node *prev_b;
    if(a == b || a == NULL || b == NULL){
        return head;
    }
    if(head == a){
        if(a -> next == b){
            a->next = b->next;
            b->next = a;
        } else {
            struct Node *tmp_a_next = a->next;
            prev_b = get_previous_node(head, b);
            a->next = b->next;
            b->next = tmp_a_next;
            prev_b->next = a;
        }
        head = b;
    } else if(head == b){
        if(b->next == a){
            b->next = a->next;
            a->next = b;
        } else {
            struct Node *tmp_b_next = b->next;
            prev_a = get_previous_node(head, a);
            b->next = a->next;
            a->next = tmp_b_next;
            prev_a->next = b;
        }
        head = a;
    } else if(a->next == b){
        prev_a = get_previous_node(head, a);
        prev_a->next = b;
        a->next = b->next;
        b->next = a;
    } else if(b->next == a){
        prev_b = get_previous_node(head, b);
        prev_b->next = a;
        b->next = a->next;
        a->next = b;
    } else {
        struct Node *tmp_a_next = a->next;
        prev_a = get_previous_node(head, a);
        prev_b = get_previous_node(head, b);
        prev_a->next = b;
        a->next = b->next;
        b->next = tmp_a_next;
        prev_b->next = a;
    }
    return head;
}

struct Node *InsertionSort(struct Node *head){
    struct Node *i;
    struct Node *j;
    struct Node *t;

    i = head->next;
    while(i != NULL){
        j = get_previous_node(head,i);
        t = i;
        while(j != NULL && t->val < j->val){
            head = swap_nodes(head, j, t);
            j = get_previous_node(head,t);
        }
        i = t->next;
    }
    return head;
}

void printList(struct Node *head){
    while(head != NULL){
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* newNode(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    return node;
}

int main(){
    struct Node* head = newNode(4);
    head->next = newNode(3);
    head->next->next = newNode(1);
    head->next->next->next = newNode(2);

    printf("Original list: \n");
    printList(head);

    head = InsertionSort(head);

    printf("Sorted list: \n");
    printList(head);

    return 0;
}

