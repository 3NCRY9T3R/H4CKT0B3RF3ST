#include<iostream>
using namespace std;
int lcm(int a,int b)
{
    int max;
    if(a>b)
        max=a;
    else
        max=b;
    do{
        if(max%a == 0 && max%b == 0)
        {
            return max;
            break;
        }
        else
            ++max;
    }while(true);
}
int main() 
{
    int a,b;
    cout<<"LCM of two numbers: ";
    cout<<"\n Enter the first number: ";
    cin>>a;
    cout<<"\n Enter the second number: ";
    cin>>b;
    cout<<"\n LCM of "<<a<<" and "<<b<<" is: "<<lcm(a,b);
	return 0;
}
