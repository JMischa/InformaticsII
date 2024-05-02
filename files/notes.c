#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Functions already implemented */
struct month *init_months(struct month *head);
void free_months(struct month *head);

/* given month struct */
struct month {
    int month_number;
    char *month_name;
    struct month *next;
};

void print_months(struct month *head) {
    /* TODO: Implement task 2.(a) */
    printf("months: ");
    struct month *p = head;
    while( p != NULL){
        printf("%s (%d), ", p -> month_name, p -> month_number);
        p = p -> next;
    }
    printf("\n");
}


struct month *get_previous_month(struct month *head, struct month *a) {
    if (head == NULL || a == NULL || head == a) {
        return NULL;
    }

    struct month *p = head;
    while (p->next != NULL) {
        if (p->next == a) {
            return p;
        }
        p = p->next;
    }
    return NULL; // a was not found in the list
}


struct month *swap_month(struct month *head, struct month *a, struct month *b) {
    /* TODO: Implement task 2.(c) */
    return head;
}

struct month *selection_sort(struct month *head) {
    /* TODO: Implement task 2.(d) */
    return head;
}

int main(int argc, char *argv[]) {
    /* Init month linked list */
    struct month *head;
    head = init_months(head);

    /* Print the linked list as it is after initialization */
    print_months(head);

    /* Implementation to check for task 2b */
    struct month *current_month = head;
    while(current_month != NULL){
        struct month *previous_month = get_previous_month(head, current_month);
        if(previous_month != NULL){
            printf("%s (%d), ", previous_month -> month_name, previous_month -> month_number);
        }
        else{
            printf("There is no previous month.");
        }
        current_month = current_month -> next;
    }

    /* TODO: Task 2.(d): Goal is to implement the selection sort algorithm */
    /* head = selection_sort(head); */
    /* print_months(head); */

    /* Cleanup */
    free_months(head);
    return 0;
}

struct month *init_months(struct month *head) {
    int n = 12;
    int init_order[n];
    char *month_strings[] = {"January",   "February", "March",    "April",
                             "May",       "June",     "July",     "August",
                             "September", "Oktober",  "November", "Dezember"};
    struct month *h;
    struct month *p; /* trailing pointer */

    /* create random order with fisher-yates shuffle */
    for (int i = 0; i < n; ++i) {
        init_order[i] = i + 1;
    }
    srand(time(0));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); /* generate random index below i */
        /* swap a[i] with a[j] */
        int tmp = init_order[i];
        init_order[i] = init_order[j];
        init_order[j] = tmp;
    }

    /* create month linked list */
    h = malloc(sizeof(struct month)); /* first node, gets returned */
    h->month_number = init_order[0];  /*  */
    h->month_name = month_strings[h->month_number - 1];
    p = h; /* pointer that goes through list */
    for (int i = 1; i < n; ++i) {
        struct month *m = malloc(sizeof(struct month));
        /* printf("create month %d\n", i); */
        m->month_number = init_order[i];
        m->month_name = month_strings[m->month_number - 1];
        p->next = m; /* previous node points now to this */

        p = m; /* increment trailing pointer */
    }
    p->next = NULL;
    return h;
}

void free_months(struct month *head) {
    /* free month linked list */
    struct month *p = head;
    struct month *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}


