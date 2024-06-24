#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function prototypes
struct ListNode* merge_sort(struct ListNode *head);
struct ListNode* merge(struct ListNode *left, struct ListNode *right);
struct ListNode* find_middle(struct ListNode *head);
void print_list(struct ListNode *head);
void push(struct ListNode **head_ref, int new_val);

// Merge sort function for linked list
struct ListNode* merge_sort(struct ListNode *head) {
    // Base case: if list is empty or has one element
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Find the middle of the list
    struct ListNode *middle = find_middle(head);
    struct ListNode *next_to_middle = middle->next;
    middle->next = NULL;

    // Recursively sort the two halves
    struct ListNode *left_sorted = merge_sort(head);
    struct ListNode *right_sorted = merge_sort(next_to_middle);

    // Merge the sorted halves
    return merge(left_sorted, right_sorted);
}

// Helper function to find the middle of the linked list
struct ListNode* find_middle(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge two sorted linked lists
struct ListNode* merge(struct ListNode *left, struct ListNode *right) {
    struct ListNode dummy;
    struct ListNode *current = &dummy;
    
    while (left && right) {
        if (left->val < right->val) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }
    
    // Attach remaining nodes of left or right
    current->next = (left != NULL) ? left : right;

    return dummy.next;
}

// Helper function to print the linked list
void print_list(struct ListNode *head) {
    struct ListNode *current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Helper function to push a new node to the front of the list
void push(struct ListNode **head_ref, int new_val) {
    struct ListNode *new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node->val = new_val;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Main function for testing
int main() {
    struct ListNode *head = NULL;

    // Example usage:
    // Create a sample linked list: 4 -> 2 -> 1 -> 3
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 4);

    printf("Original list: ");
    print_list(head);

    // Perform merge sort
    head = merge_sort(head);

    printf("Sorted list: ");
    print_list(head);

    return 0;
}
