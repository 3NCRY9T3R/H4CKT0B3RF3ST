#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
typedef struct list
{
	int data;
	struct list *link;
}node;
node *start,*a,*b;
void create()
{
	if(start==NULL)
	{
		start=(node*)malloc(sizeof(node));
		printf("Enter details : ");
		scanf("%d",&start->data);
		start->link=NULL;
	}
	else
	{
		a=start;
		while(a->link!=NULL)
		{
			a=a->link;
		}
		b=(node*)malloc(sizeof(node));
		printf("Enter data : ");
		scanf("%d",&b->data);
		a->link=b;
		b->link=NULL;
	}
}
void del()
{
	if(start==NULL)
		printf("\nQueue is empty");
	else
	{
		a=start;
		start=start->link;
		free(a);
	}
}
void print()
{
	a=start;
	if(start==NULL)
		printf("\nQueue is empty");
	else
	{
		while(a!=NULL)
		{
			printf("%d->",a->data);
			a=a->link;
		}
	}
}
void main()
{
	int n;
	printf("Queue implementation using Link List \n");
	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				create();
				break;
			case 2:
				del();
				break;
			case 3:
				print();
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong choice!!");
		}
	}
}
