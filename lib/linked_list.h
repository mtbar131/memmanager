#ifndef _MEMMANAGER_LINKED_LIST_H_
#define _MEMMANAGER_LINKED_LIST_H_

typedef struct node {
        void *data;
        struct node *next;
}node;

typedef struct LinkedList {
        node *head;
        int length;
}LinkedList;

// Initialize and return a linked list
LinkedList* create_new_linked_list();

// Append the given node at the end of the list
void append(LinkedList*, node*);

// remove node at nth position from list - 0 based indexing
void removeAt(LinkedList*, int);

// merges nodes at position1 and position2
// Note function will NOT merge nodes if
// Assert (position2 - position1 <= 0)
// The merge_fn is a function poitner to a function
// which will merge the two data poitners of the node
// as per requirement. This function takes two pointers, one for each
// data node and expects the final merged data pointer to be returned
// 0 based indexing
void merge_consecutive_nodes(LinkedList*, int, int,
                             void* (*merge_fn)(const void*, const void*));

// Inserts given node at given position - 0 based indexing
void insert_at(LinkedList*, node*, int);

// prints contents of the list. Need to pass the function to print data
void print_list(LinkedList*, void (*print_data)(void *));

#endif  // _MEMMANAGER_LINKED_LIST_H_
