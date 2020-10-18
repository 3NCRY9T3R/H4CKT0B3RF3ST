#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define TRUE 1
#define FALSE 0
/**********************************************/
 struct CQueue
 {
     int REAR;
     int FRONT;
     int Item [SIZE];
 };
/**********************************************/

 struct CQueue CQ;

/**********************************************/
 void Initalize(void)
 {
     CQ.FRONT=SIZE-1;
     CQ.REAR=SIZE-1;
 }
 /**********************************************/

int Empty(void)
{
    if(CQ.REAR==CQ.FRONT)
        return TRUE;
    else
        return FALSE;
}
/**********************************************/
void EnQueue( int x)
{

    if((CQ.REAR+1)%SIZE==CQ.FRONT)
    {
        printf("Queue overflow");
        exit (1);
    }
    CQ.REAR=(CQ.REAR+1)%SIZE;
    CQ.Item[CQ.REAR]=x;
}
/**********************************************/

 int DeQueue()
 {
    int x;
     if(Empty())
    {

     printf("queue underflow");
     exit(1);
    }
    CQ.FRONT=(CQ.FRONT+1)%SIZE;
     x=CQ.Item[CQ.FRONT];
     return x;
 }
/**********************************************/
Traverse()
{
    int i;
    i=(CQ.FRONT+1)%SIZE;
    while(i%SIZE!=CQ.REAR)
    {
        printf(" %d ",CQ.Item[i]);
        i++;
    }
       printf("%d",CQ.Item[i]);
}
/**********************************************/
  void main()
{
     Initalize();
     int x;
     EnQueue(400);
     EnQueue(600);
     EnQueue(700);
     EnQueue(800);
     EnQueue(900);
     Traverse();
     x=DeQueue();
     printf("\n \t dequeued element  are   %d\n",x);
     x=DeQueue();
     printf("\t dequeued element  are %d \n",x);
     x=DeQueue();
     printf("\t dequeue element are%d\n",x);
      x=DeQueue();
      Traverse();
 }



