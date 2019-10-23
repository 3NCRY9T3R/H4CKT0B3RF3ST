#include<iostream>
#include<cmath>
using namespace std;
class Complex
{
	int r1,r2,i1,i2;
	public:
	void getdata ( )
	{
			cout<<"\n Enter the Ist complex number";
			cout<<"\n Enter the real part: ";
			cin>>r1;
			cout<<"\n Enter the imaginary part: ";
			cin>>i1;
			cout<<"\n The Ist complex number is: "<<r1<<"+("<<i1<<")i";
			cout<<"\n Enter the IInd complex number";
			cout<<"\n Enter the real part: ";
			cin>>r2;
			cout<<"\n Enter the imaginary part: ";
			cin>>i2;
			cout<<"\n The IInd complex number is: "<<r2<<"+("<<i2<<")i";
		}
	void addition()
	{
		cout<<"In the sum of the complex number is: "<<(r1+r2)<<"+("<<(i1+i2)<<")i";
	}
	void subtraction ( )
	{
		int i ;
		cout <<"\n 1.Subtract 2 complex number from 1 complex number ";
		cout<<"\n 2.Subtract 1 complex number from 2 complex number ";
		cin>>i ;
		switch (i)
		{
			case 1: cout<<"\n The subtraction of the complex numbers is: "<<"("<<r1-r2<<")"<<"+("<<i1-i2<<")i";
					break;
			case 2: cout<<"\n The subtraction of the complex numbers is: "<<"("<<r2-r1<<")"<<"+("<<i2-i1<<")i";
					break;
			default: cout<<"\n Wrong choice !!!";
					break;
		}
	}
	void multiplication ( )
	{
		cout<<"\n The multiplication of the matrix is ";
		cout<<((r1*r2)-(i1*i2))<<"+("<<((r1*i2)+(i1*r2))<<")i";
	}
	void division()	
	{
		int j;
		cout <<"\n 1.Division 2 complex number from 1 complex number ";
		cout<<"\n 2.Division 1 complex number from 2 complex number ";
		cin>>j ;
		switch (j)	
		{
			case 1 : cout<<"\n The division of the complex numbers is: "<<((r1*r2)+(i1*i2))/(pow(r2,2)+pow(i2,2))<<"+("<<((i1*r2)-(r1*i2))/(pow(r2,2)+pow(i2,2))<<")i";
					      break;
			  case 2 : cout<<"\nThe division of the complex numbers is: "<<((r2*r1)+(i2*i1))/(pow(r1,2)+pow(i1,2))<<"+("<<((i2*r1)-(r2*i1))/(pow(r1,2)+pow(i1,2))<<")i";
					       break;	
			default : cout<<"\n Wrong choice !!!";
	                 		break;
		}
	}
};
int main()
{
	Complex C;
	int choice;
	char ch;
	C.getdata();
	do
	{
		cout<<"\n Choose from the folowing : ";
		cout<<"\n 1. Add two complex numbers ";
		cout<<"\n 2. Subtract two complex numbers ";
		cout<<"\n 3. Multiply two complex numbers ";
		cout<<"\n 4. Divide two complex numbers ";
		cout<<"\n Enter  your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: C.addition();
				break;
			case 2: C.subtraction();
				break;
			case 3: C.multiplication();
				break;
			case 4:C.division();
				break;
		}
	    cout<<"\nWant to Choose again !!!";
	    cin>>ch;
	}
    while(ch=='y'||ch=='Y');
    return 0;
}
