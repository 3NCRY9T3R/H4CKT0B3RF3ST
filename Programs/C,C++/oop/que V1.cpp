#include<iostream>
using namespace std;
class QueOverFlow
{
	
};
class QueUnderFlow
{
	
};

class Que
{
    int *q;
    int size,head=-1,tail=-1;
public:
    Que(int S)
    {
        q=new int[S];
        size=S;
        for(int i=0;i<size;i++)
        {
        	q[i]=0;
		}
    }
    ~Que()
    {
        delete [] q;
    }
    void insert(int E)
    {
        head++;
		//if(head==-1 && tail==-1)
        //tail++;
        //head++;
		if(head==size && tail!=-1)
        {
            head=0;
        }
        if(head!=-1 && head==tail)
        {
            QueOverFlow ERROR;
            throw ERROR;
        }
        //h++;
        q[head]=E;
        cout<<"in  "<<q[head]<<"\n";
        
    }
    int del()
    {
    	if(tail==-1 && head==-1)             // tail!=-1 && tail==head || (tail==0 && head==-1)
        {
            QueUnderFlow ERROR;
            throw ERROR;
        }
        tail++;
   /*     if(head==tail)
            {
                cout<<"\t out "<<q[tail]<<"\n";
		        int temp=q[tail];
                return temp;
                tail=-1;
                head=-1;
            }*/
        if(tail==size)
        {
            tail=0;
        }
        //tail++;
        cout<<"\t out "<<q[tail]<<"\n";
		int temp=q[tail];
		q[tail]=0;
		//tail++;
        if(head==tail)
            {
                tail=-1;
                head=-1;
            }
		return temp;    
    }
    void displaylast()
    {
        cout<<head;
    }
    void displayfirst()
    {
        cout<<tail;
    }
    void display()
    {
    	for(int i=0;i<size;i++)
			cout<<q[i]<<" ";
		  cout<<"\ntail "<<tail<<"\nhead "<<head;
    }
};
int main()
{
    Que q(5);
    try
    {
   	q.insert(213);
	q.insert(12);
	q.insert(11);
	q.insert(1);
	q.insert(21);
	//q.del();
	q.insert(13);
	//q.del();
	//q.del();
	//q.del();
	//q.del();
	q.insert(15);
	q.insert(16);
	q.insert(90);
	//q.del();
	//q.del();
	//q.del();
	//q.del();
	//q.del();
	q.display();  
    }
    catch(QueUnderFlow a)
    {
    	cout<<"under flow";
	}
	catch(QueOverFlow a)
	{
		cout<<"overflow";
	}
	//int x=q.del();
   // cout<<x;
}
