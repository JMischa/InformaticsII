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
    /* TODO: Implement task 2.(b) */
    if (head == NULL || a == NULL){
    return NULL;
    }
    else if(head ->next == a){
        return head;
    }
    struct month *p = head;
    while(p ->next != a){
        p = p ->next;
    }
    return p;
}

struct month *swap_month(struct month *head, struct month *a, struct month *b) {
    /* TODO: Implement task 2.(c) */
    struct month *prev_a;
    struct month *prev_b;
    if(a == b){
        return head;
    }
    else if(head == a){
        if(a -> next == b){
            a ->next = b ->next;
            b -> next = a;
        }
        else{
            struct month *tmp_a_next = a -> next;
            prev_b = get_previous_month(head, b);
            a -> next = b -> next;
            b ->next = tmp_a_next;
            prev_b -> next = a;
        }
        head = b;
    }
    else if(a->next == b){
        prev_a = get_previous_month(head, a);
        a ->next = b ->next;
        b->next = a;
        prev_a -> next = b;
    }
    else{
       struct month *tmp_a_next = a->next;
        prev_a = get_previous_month(head, a);
        prev_b = get_previous_month(head, b);
        prev_a->next = b;                     
        a->next = b->next;
        b->next = tmp_a_next;
        prev_b->next = a;
    }
    return head;
}

struct month *selection_sort(struct month *head) {
    /* TODO: Implement task 2.(d) */
    struct month *i;
    struct month *j;
    struct month *k;
    
    i = head;
    while(i != NULL){
        k = i;
        j = i ->next;
        while(j != NULL){
            if(j ->month_number < k ->month_number){
                k = j;
            }
            j = j->next;
        }
        head = swap_month(head, i, k);
        i = k ->next;
    }
    return head;
}

int main(int argc, char *argv[]) {
    /* Init month linked list */
    struct month *head;
    head = init_months(head);

    /* Print the linked list as it is after initialization */
    print_months(head);
    printf("\n");

    /* TODO: Task 2.(d): Goal is to implement the selection sort algorithm */
    head = selection_sort(head);
    print_months(head);

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
