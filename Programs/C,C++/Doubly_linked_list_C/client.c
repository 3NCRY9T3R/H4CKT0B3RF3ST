#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
int main()
{
    List* dll = initialize_list();
    int ele,choice,pos,x;
    do
    {	printf("0- Exit the program\n 1- Insert element x at the front of the list \n 2- Delete node at the front of the list \n 3– Return the number of nodes in the list. \n 4- Delete node at position p.\n 5- Search for element x and print its offset .\n 6- Reverse the elements of the list. No operation if the list is empty.\n 7- Display the entire list.\n " );
		printf("\n enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at beginning
            case 1:
                scanf("%d",&ele);
                insert_front(dll,ele);
                break;

	   // Delete element at the beginning of the list  	   
	   case 2:
                dllist_delete_beginning(dll);
		break;

	   // Count number of nodes 
	  case 3:
               x = count_nodes(dll);
		printf("%d\n",x);
            	break;

            // Delete at position
            case 4:
                scanf("%d",&pos);
                position_delete(dll, pos);
                break;

            // Search for element
            case 5:
                scanf("%d",&ele);
                pos = search_list(dll,ele);
                printf("%d\n",pos);
                break;
	
	    // reverse for element
            case 6:
                reverse_list(dll);
                break;

            // Print entire list
            case 7:
                display(dll);
                break;        
        }
    }
    while (choice != 0);

    destroy_list(dll);
    return 0;
}

List* initialize_list()
{
    List* dll = (List*)malloc(sizeof(List));
    dll->head = NULL;
    dll->number_of_nodes = 0;

    return dll;
}

Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void display(List* dll)
{
    if(dll->number_of_nodes == 0)
        printf("EMPTY");
    else
    {
        Node* temp = dll->head;

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    
    printf("\n");
}

void destroy_list(List* dll)
{
    Node *p = dll->head;
	Node *q = NULL;

    while (p != NULL)
    {
		q = p;
		p = p->next;
		free(q);
	}
	
    free(dll);
}

