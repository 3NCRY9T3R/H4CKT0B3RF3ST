#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};//Creating Structure
void insertAt(int n,struct node *p);
void insert(int n);
void deleteFrom(int n);
void delete();
void display();
void displayRev();
struct node *start=NULL;
struct node *p;
struct node *end=NULL;
int no=0;
struct node *createNode()
{
	struct node *p= (struct node *)malloc(sizeof(struct node));
	p->left=NULL;
	p->right=NULL;
	return p;
}//Creating a node
void insertAt(int n,struct node *p)
{
	if(n>no+1)
	{
		printf("Invalid position!!!!!\n");
		free(p);
	}
	else if (start==NULL)
	{
		start=p;
		end=p;
		no=no+1;
	}
	else
	{
		if(n==1)
		{
			p->right=start;
			start->left=p;
			start=p;
		}//Inserting node at the first position of the linked list
		else
		{
			int count=1;
			struct node *temp=start;
			while(count<n-1)
			{
				temp=temp->right;
				count=count+1;
			}
			p->right=temp->right;
			p->left=temp;
			temp->right=p;
		}
		no=no+1;
	}
}//Inserting node at position 'n' of the linked list
void insert(int n)
{
	printf("1-Insert at begining\n2-Insert by positon number\n3-Insert at the end\n");
	int choice,address;
	struct node *newnode=createNode();
	newnode->data=n;
	printf("Enter your position preference\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		insertAt(1,newnode);
		break;
		case 2:
		printf("Enter the position\n");
		scanf("%d",&address);
		insertAt(address,newnode);
		break;
		case 3:
		insertAt(no+1,newnode);
		break;
		default:
		printf("Wrong Input!!!!!!\n");
		free(newnode);
	}
}//Inserting a node in the linked list
void deleteFrom(int n)
{
	if(n>no)
		printf("Invalid position!!!!!\n");
	else 
	{
		if(n==1)
		{
			p=start;
			start=start->right;
			start->left=NULL;
		}	//Deleting node from the first position of the linked list
		else
		{
			int count=1;
			struct node *temp=start;
			while(count!=n-1)
			{
				temp=temp->right;
				count=count+1;
			}
			p=temp->right;
			if(no!=n)
				p->right->left=temp;
			temp->right=p->right;
			if(no==n)
				end=temp;//Deleting node from the last position of the linked list
		}
		if(start==NULL)
			end=NULL;
		printf("%d is deleted form the list\n",p->data);
		free(p);
		no=no-1;
	}
}//Deleting node from position 'n' of the linked list
void delete()
{
	if(start==NULL)
		printf("No node left to delete");
	else
	{
		printf("1-Delete at begining\n2-Delete by positon number\n3-Delete at the end\n");
		int choice,address;
		printf("\nEnter your position preference\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			deleteFrom(1);
			break;
			case 2:
			printf("\nEnter the position\n");
			scanf("%d",&address);
			deleteFrom(address);
			break;
			case 3:
			if(no==1)
				deleteFrom(1);
			else
				deleteFrom(no);
			break;
			default:
			printf("Wrong Input!!!!!!\n");
		}
	}
}//Deleting a node from the linked list
void display()
{
	if(start==NULL)
		printf("No list!!\n");
	else
	{
		printf("The list is: ");
		int i=1;
		struct node *temp=start;
		while(i<=no)
		{
			printf("%d ",temp->data);
			temp=temp->right;
			i++;
		}
		printf("\n");
	}
}//Displaying the list
void displayRev()
{
	if(end==NULL)
		printf("No list!!\n");
	else
	{
		printf("The reverse of the list is: ");
		int i=1;
		struct node *temp=end;
		while(i<=no)
		{
			printf("%d ",temp->data);
			temp=temp->left;
			i++;
		}
		printf("\n");
	}
}//Displaying the reverse of the list
int main()
{
	printf("\n1-Insert a node\n2-Delete a node\n3-Display the list\n4-Display the reverse of the list\n5-Exit the operations\n");
	int choice,exit=0,value;
	while(exit==0)
	{
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the data\n");
			scanf("%d",&value);
			insert(value);
			break;//Inserting the node
			case 2:
			delete();
			break;//Deleting the node
			case 3:
			display();
			break;//Displaying the list
			case 4:
			displayRev();
			break;//Displaying the reverse of the list
			case 5:
			exit=1;
			printf("\nOperation ended.\n");
			break;//Exiting the program
			default:
			printf("\nWrong Input!!!!!!\n");//Going back for asking choice
		}
	}
}
