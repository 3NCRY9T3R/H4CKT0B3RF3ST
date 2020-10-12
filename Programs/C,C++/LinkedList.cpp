#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

void display();
void insert_begin();
void delete_begin();
struct node
{
	int info;
	struct node *next;
};
struct node *start=NULL;


int main()
{
	int choice;

	while(1){
		cout<<"\n 1.Display    \n";
		cout<<"\n 2.Insert at the beginning    \n";
		cout<<"\n 3.Delete from beginning      \n";
		cout<<"\n 4.Exit       \n";
		cout<<"Enter your choice:\t";
		cin>>choice;
		switch(choice)
		{
		       case 1:
					display();
					break;
			case 2:
					insert_begin();
					break;
			case 3:
					delete_begin();
					break;
			case 4:
					exit(0);
					break;
			default:
					cout<<"\n Wrong Choice:\n";
					break;
		}
	}

}

void display()
{
	struct node *ptr;
	if(start==NULL)
	{
		cout<<"\nList is empty:\n";
		return;
	}
	else
	{
		ptr=start;
		cout<<"\nThe List elements are:\n";
		while(ptr!=NULL)
		{
			cout<<ptr->info<<"\t";
			ptr=ptr->next ;
		}
	}
}
void insert_begin()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		cout<<"\nOut of Memory Space:\n";
		return;
	}
	cout<<"\nEnter the data value for the node:\t" ;
	cin>>temp->info;
	temp->next =NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
}
void delete_begin()
{
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)1
        11
        
        
        
	{
		cout<<"\nList is Empty:\n";
		return;
	}
	else
	{
		ptr=start;
		start=start->next ;
		cout<<"\nThe deleted element is \t"<<ptr->info;
		free(ptr);
	}
}

