#include<stdio.h>
#include<stdlib.h>
// Node of the linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List
{
    Node *head;
    Node *tail;
    int number_of_nodes;
}List;

// initializes a linked list
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at the beginning of the List
void insert_front(List* dll, int data);

/* Removes first element for a non-empty list */
void dllist_delete_beginning(List* list);

// Deletes the node at position pos. No operation if pos is out of range.
void position_delete(List* dll, int pos);

// Return index of key in the list(0-based). Return -1 if not found
int search_list(List* dll,int key);

//count the number of nodes
int count_nodes(List* dll);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* dll);

// Return index of key in the list(0-based). Return -1 if not found
void reverse_list(List* dll);

// Deallocates resources held by the list
void destroy_list(List*);

