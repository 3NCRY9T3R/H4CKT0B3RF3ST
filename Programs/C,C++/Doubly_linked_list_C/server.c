#include"server.h"
int count_nodes(List* dll)
{
	//TODO
    return dll->number_of_nodes;
}

void insert_front(List* dll, int data)
{
    Node * temp=create_node(data);
    Node *head=dll->head;
    if(head==NULL)
    {
        dll->head=temp;
        dll->number_of_nodes=1;
        return;
    }
    temp->next=head;
    head->prev=temp;
    dll->head=temp;
    dll->number_of_nodes=dll->number_of_nodes+1;
    return;
}


void dllist_delete_beginning(List* list)
{
    if(list->number_of_nodes==0)
    {
       // printf("EMPTY");
        return;
    }
    Node* temp=list->head;
    if(list->number_of_nodes==1)
    {
        list->head=NULL;
        list->number_of_nodes=0;
        free(temp);
        return;
        
    }

    list->head=temp->next;
    (list->head)->prev=NULL;
    free(temp);
    list->number_of_nodes=list->number_of_nodes-1;
    return;
    //TODO
    
}


void position_delete(List* dll, int pos)
{
    if(pos>=dll->number_of_nodes)
    {
        
        return;
    }
    Node* head=dll->head;
   if(pos==0)
   {
       dllist_delete_beginning(dll);
       return;
   }
    if(pos == dll->number_of_nodes-1)
    {
        while((head->next)->next!=NULL)
        {
            head=head->next;
        }
        
        Node* temp=head->next;
        head->next=NULL;
        free(temp);
        dll->number_of_nodes=dll->number_of_nodes-1;
        return;
    }
    
    int c=0;
    while(c<pos-1)
    {
        head=head->next;
        //printf("%d",head->data);
        c++;
    }
    Node* temp=head->next;
    Node* nxt=(head->next)->next;
    Node* curr=head;
    curr->next=nxt;
    nxt->prev=curr;
    free(temp);
    dll->number_of_nodes=dll->number_of_nodes-1;
    return;
    
}

int search_list(List* dll,int key)
{
    //TODO
    Node* head=dll->head;
    int c=0;
    while(head!=NULL)
    {
        if(head->data==key)
            return c;
        c++;
        head=head->next;
    }
    return -1;
}


void reverse_list(List* dll)
{
    Node* head=dll->head;
    if(head==NULL||head->next==NULL)
        return;
        
        
       Node* temp=head;
    Node* curr=head;
    
   while (curr != NULL)
      {
          temp = curr->prev;
          curr->prev = curr->next;
          curr->next = temp;
          curr = curr->prev;
      }
          dll->head = temp->prev;
    //printf("%d",(dll->head)->next->data);

    return;
}


