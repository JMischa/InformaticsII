#include <stdio.h>
#include <stdlib.h>

// Definition of a ListNode
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to heapify a subtree rooted with node i which is an index in heap[]
void heapify(struct ListNode* heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare root with left child
    if (left < n && heap[left]->val < heap[largest]->val)
        largest = left;

    // Compare largest with right child
    if (right < n && heap[right]->val < heap[largest]->val)
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        struct ListNode* temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap, n, largest);
    }
}

// Function to perform heap sort on a linked list
struct ListNode* heap_sort_linked_list(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    // Step 1: Create an array of ListNode pointers from the linked list
    int count = 0;
    struct ListNode* ptr = head;
    while (ptr) {
        count++;
        ptr = ptr->next;
    }

    // Allocate memory for array of ListNode pointers
    struct ListNode** heap = (struct ListNode**)malloc(count * sizeof(struct ListNode*));

    // Populate the array with elements from the linked list
    ptr = head;
    for (int i = 0; i < count; i++) {
        heap[i] = ptr;
        ptr = ptr->next;
    }

    // Step 2: Build max heap (rearrange array)
    for (int i = count / 2 - 1; i >= 0; i--)
        heapify(heap, count, i);

    // Step 3: Extract elements from the max heap one by one
    struct ListNode* sorted_head = heap[0];
    struct ListNode* tail = sorted_head;
    for (int i = count - 1; i > 0; i--) {
        // Swap root (maximum) element with the last element
        struct ListNode* temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        // Heapify root element
        heapify(heap, i, 0);

        // Update tail pointer
        tail->next = heap[0];
        tail = tail->next;
    }
    tail->next = NULL;  // End the linked list

    // Free dynamically allocated memory
    free(heap);

    return sorted_head;
}

// Function to create a new node with given value
struct ListNode* new_node(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void print_list(struct ListNode* head) {
    struct ListNode* ptr = head;
    while (ptr) {
        printf("%d -> ", ptr->val);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    // Creating a linked list: 4 -> 2 -> 1 -> 3
    struct ListNode* node4 = new_node(4);
    struct ListNode* node2 = new_node(2);
    struct ListNode* node1 = new_node(1);
    struct ListNode* node3 = new_node(3);

    node4->next = node2;
    node2->next = node1;
    node1->next = node3;

    printf("Original linked list: ");
    print_list(node4);

    struct ListNode* sorted_head = heap_sort_linked_list(node4);

    printf("Sorted linked list: ");
    print_list(sorted_head);

    // Clean up memory
    struct ListNode* temp;
    while (sorted_head) {
        temp = sorted_head;
        sorted_head = sorted_head->next;
        free(temp);
    }

    return 0;
}
