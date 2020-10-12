#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
void push(int value);
void pop();
void display();
struct node
{
	int data;
	struct node *next;
}*top=NULL;
void push(int value)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	if(top==NULL)
		temp->next=NULL;
	else
		temp->next=top;
	top=temp;
	printf("\nInsertion is success!!");
}
void pop()
{
	if(top==NULL)
		printf("\nStack is empty!!");
	else
	{
		struct node *ptr=top;
		printf("\nDeleted element : %d",ptr->data);
		top=ptr->next;
		free(ptr);
	}
}
void display()
{
	if(top==NULL)
		printf("\nStack is empty!!");
	else
	{
		struct node *ptr=top;
		while((ptr->next)!=NULL)
		{
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}
		printf("%d->NULL",ptr->data);
	}
}
void main()
{
	int choice, value;
	printf("Stack using Link List \n");
	while(1)
	{
		printf("\n1. Push \n2. Pop \n3.Display \n4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to be inserted : ");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong choice!!");
		}
	}
}
