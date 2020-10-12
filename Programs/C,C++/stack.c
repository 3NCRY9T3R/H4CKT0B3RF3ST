#include<stdio.h>
#define STACKSIZE 5
struct bufferstack
{
int stk[STACKSIZE];
int top; // We will use it as POINTER to top of the stack
}s; // Here s is struct variable, you can see here how to implement structure in C
void push(); // To push elements in stack
int pop(); // To Pop elements in stack
void display();
int main()
{
int c;
s.top=-1; //Set s to -1
int x=1;
while(x) //While loop to keep program in loop
 {
printf("\n TOP is at : %d\t",s.top+1); //this line is to test, the position of s
printf("\n ****MENU****\n");
printf("1: Push \n");
printf("2: Pop \n");
printf("3: Display \n");
printf("4: Exit");
printf("\n Please enter your choice : ");
scanf("%d",&c);
 switch(c)
 {
 case 1:
 push();
 break;
 case 2:
 pop();
 break;
 case 3:
 display();
 break;
 case 4:
 return 0;
 }
printf(" \n Do you want to cotin....? press 1 or 0 ");
scanf("%d",&x);
 }
}
void push()
{
 int num;
 printf("\n ***PUSH OPERATION***");
 if(s.top==(STACKSIZE-1))
 {
 printf("\n Sorry You can't push any element into stack .... ,Stack is full");
 }
 else
 {
 printf("\n Enter the number to push into stack:-\t");
 scanf("%d",&num);
 s.top+=1;
 s.stk[s.top]= num;

 }
}
int pop()
{
 printf("\n ***POP OPERATION***");
 int num;
 if(s.top==-1)
 {
 printf(
"\nstack is empty ");
 }
 else
 {
 num=s.top;
 printf(
"\n Poped number is : %d\t
",s.stk[num]);
 s.stk[num]=
0; //To delete top element from stack
 s.top-=
1;
 }
 return num;
 }
void display() {
 int i;
 printf(
"\n ***DISPLAY OPERATION***");
 if(s.top==-
1
)
 {
 printf(
"\n Stack is empty \n
");
 }
 else
 {
 for(i=s.top;i>=
0;i--)
 {
 printf(
"\n%d : %d
",i,s.stk[i]);
 }
 printf(
"\tTOP=%d
",s.top);
 } }
