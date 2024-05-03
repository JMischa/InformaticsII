#include <stdio.h>

struct node{
    int val;
    struct node *next;
    struct node *prev;
}

struct node *merge(struct node *list1, struct node *list2){
    if(list1 == NULL){
        return list2;
    }
    else if(list2 == NULL){
        return list1;
    }
    struct node *head = malloc(sizeof(struct node));
    head ->next = NULL;
    head ->prev = NULL;
    struct node *p = head;
    struct node *p1 = list1;
    struct node *p2 = list2;

    while(p1 && p2){
        if(p1 ->val < p2 -> val){
            p ->next = p1;
            p1 ->prev = p;
            p1 = p1 -> next;
        }
        else{
            p ->next = p2;
            p2 ->prev = p;
            p2 = p2 ->next;
        }
        p = p ->next;
    }
    if(p1){
        p ->next = p1;
        p1 -> prev = p;
    }
    else if(p2){
        p ->next = p2;
        p2 ->prev = p;
    }
    return head ->next;
}


struct node *reverse(struct node *head){
    struct node *temp = NULL;
    struct node *current = head;

    if(head == NULL || head ->next == NULL){
        return head;
    }
    while(current != NULL){
        temp = current ->prev;
        current ->prev = current ->next;
        current ->next = temp;
        current = current ->next;
    }
    return temp ->prev;
}

struct node *reverseRecursive(struct node *current){
    if(current == NULL || current ->next == NULL){
        current ->prev = NULL;
        return current;
    }
    struct node *newHead = reverseRecursive(current ->next);
        current ->next->next = current;
        current ->prev = current ->next;
        current ->next = NULL;

    return newHead;
}



