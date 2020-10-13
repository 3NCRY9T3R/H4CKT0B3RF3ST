//Stack using queue

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

struct queue  //structure of a queue
{
    NODE *front,*rear;
};


struct queue enqueue(struct queue Q,int x) //function to add element x to queue Q
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=x;
    temp->next=NULL;
    if (Q.front ==NULL)
    {
        Q.front=Q.rear=temp;
        return Q;
    }
    Q.rear->next=temp;
    Q.rear=temp;
    return Q;
}

struct queue dequeue(struct queue Q) //function to delete an element from queue Q
{
    NODE *temp=Q.front;
    if (Q.front==Q.rear)
    {
        
        Q.front=Q.rear=NULL;
    }    
    else
    {
        Q.front=Q.front->next;   
    }    
    free(temp);
    return Q;    
}

struct queue push(struct queue Q,int x)  //function to implement push operation using queue methods
{   
    Q=enqueue(Q,x);    
    return Q;
}

void display(struct queue Q) //function to display the stack
{   
    if (Q.front==NULL)
    {
        printf("Stack is empty");
        return;
    }    
    printf("The elements in the stack are: \n");
    NODE *p=Q.front;
    while (p!=NULL)
    {
        printf("\t%d ",p->data);
        p=p->next;
    }
    printf("(top)");
    
}

struct queue pop(struct queue Q) //function to implement push operation using queue methods
{
    if (Q.front==NULL)
    {
        printf("Stack is empty.");
        return Q;
    }    
    struct queue Q2;
    Q2.front=Q2.rear=NULL;
    NODE *p=Q.front;
    while (p->next!=NULL)
    {
        Q2=enqueue(Q2,p->data);
        p=p->next;
        Q=dequeue(Q);
    }
    dequeue(Q);
    return Q2;
}


int main()
{
    struct queue Q;
    Q.front=Q.rear=NULL;
    while (1)
    {
        printf("\n\nStack(using Queue) menu: \n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Display the contents of the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int n,x;
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&x);
            Q=push(Q,x);
            break;
        case 2:
            Q=pop(Q);
            break;
        case 3:
            display(Q);
            break;
        case 4:
            exit(0);        
        default:
            printf("Invalid option entered");
            break;
        }
    }
    return 0;
}
