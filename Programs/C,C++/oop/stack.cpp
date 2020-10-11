#include<iostream>

using namespace std;

class StakeOverflowException
{
};

class StakeUnderflowException
{
};



class Stack
{

int size;
int *stk;
int head=-1;
public:
	Stack(int size)
	{
	this->size=size;
	stk=new int[size];	
	}


void push(int element)
{

  if(head==size-1)
  {
  	StakeOverflowException ob;
  	throw ob;
  }	
  head++;
  stk[head]=element;
  	
}

int pop()
{
	if(head==-1)
	{
		StakeUnderflowException ob;
  	    throw ob;
	}
	
	int temp=stk[head];
	head--;
	return temp;
}


Stack(const Stack &s)
{
 this->size=s.size;
 stk=new int[size];
 
 this->head=s.head;
 for(int i=0;i<=head;i++)
 {
 	stk[i]=s.stk[i];
 }
 	
}

Stack operator=(Stack s)
{
 this->size=s.size;
 delete[] stk;
 stk=new int[size];
 
 this->head=s.head;
 for(int i=0;i<=head;i++)
 {
 	stk[i]=s.stk[i];
 }	
 
 return *this;
}

~Stack()
{
	delete[] stk;
}
  	
};


int main()
{
	Stack s1(3);

 s1.pop();	
 s1.push(22);
 s1.push(33);
 s1.push(44);
 s1.push(55);

	
	return 0;
}
