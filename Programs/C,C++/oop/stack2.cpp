#include<iostream>

using namespace std;

class StakeOverflowException
{
};

class StakeUnderflowException
{
};


template<class T>
class Stack
{

int size;
T *stk;
int head=-1;
public:
	Stack(int size)
	{
	this->size=size;
	stk=new T[size];	
	}


void push(T element)
{

  if(head==size-1)
  {
  	StakeOverflowException ob;
  	throw ob;
  }	
  head++;
  stk[head]=element;
  	
}

T pop()
{
	if(head==-1)
	{
		StakeUnderflowException ob;
  	    throw ob;
	}
	
	T temp=stk[head];
	head--;
	return temp;
}


Stack(const Stack &s)
{
 this->size=s.size;
 stk=new T[size];
 
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
 stk=new T[size];
 
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
	Stack<int> s1(3);
	
 

 
 s1.push(22);
 s1.push(33);
 s1.push(44);
 //s1.push(55);
 s1.pop();
 int x=s1.pop();
 
 cout<<x;

	
	return 0;
}
