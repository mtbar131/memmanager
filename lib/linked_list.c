#include "./linked_list.h"
#include<stdio.h>
#include<stdlib.h>

LinkedList* create_new_linked_list() {
        LinkedList *l = (LinkedList*) malloc(sizeof(LinkedList));
        l->head = NULL;
        l->length = 0;
        return l;
}

void append(LinkedList *l, node *n) {
        // make sure n->next is NULL
        n->next = NULL;
        node **walk = &l->head;
        while (*walk != NULL)
          walk = &(*walk)->next;
        *walk = n;
        l->length++;
}

void removeAt(LinkedList *l, int pos) {
        int count = 0;
        node **walk = &l->head;
        node *to_be_removed;
        while (count < pos) {
                walk = &((*walk)->next);
                count++;
        }
        to_be_removed = *walk;
        *walk = (*walk)->next;
        free(to_be_removed);
        l->length--;
}

void merge_consecutive_nodes(LinkedList *l, int pos1, int pos2,
                             void* (*merge_fn)(const void*, const void*)) {
        int count = 0;
        node **walk = &l->head;
        node *merged_data;
        node *to_be_removed;
        while (count < pos1) {
                walk = &((*walk)->next);
                count++;
        }
        merged_data = merge_fn((*walk)->data, (*walk)->next->data);
        to_be_removed = (*walk)->next;
        (*walk)->next = (*walk)->next->next;
        (*walk)->data = merged_data;
        free(to_be_removed);
        l->length--;
}

void insert_at(LinkedList *l, node *n, int position) {
        int count = 0;
        node **walk = &l->head;
        while (count < position) {
                walk = &((*walk)->next);
                count++;
        }
        n->next = (*walk);
        (*walk) = n;
        l->length++;
}

void print_list(LinkedList *l, void (*print_data)(void *)) {
        node *walk = l->head;
        while (walk != NULL) {
                print_data(walk->data);
                walk = walk->next;
        }
        printf("\n");
}


/* DBUG functions */
void print_int(void *num) {
        printf("%d,", *((int*)num));
}

void* merge_data(const void *a, const void *b) {
        int *p = (int*)malloc (sizeof(int));
        *p = *((int*)a) + *((int*)b);
        return (void*)p;
}
int main() {
        LinkedList *list = create_new_linked_list();
        int i;
        node *n;
        int arr[12];
        for (i = 0; i < 10; i++) {
          n = (node*)malloc (sizeof(node));
          arr[i] = i;
          n->data = (void*)&arr[i];
          append(list, n);
        }
        print_list(list, print_int);
        arr[10] = 10;
        arr[11] = 11;
        removeAt(list, 0);
        print_list(list, print_int);
        n = (node*)malloc (sizeof(node));
        n->data = (void*)&arr[10];
        insert_at(list, n, 0);
        print_list(list, print_int);
        n = (node*)malloc (sizeof(node));
        n->data = (void*)&arr[11];
        insert_at(list, n, 10);
        print_list(list, print_int);
        merge_consecutive_nodes(list, 0, 1, merge_data);
        merge_consecutive_nodes(list, 8, 9, merge_data);
        print_list(list, print_int);
        return 0;
}
