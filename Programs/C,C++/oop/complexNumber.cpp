#include<iostream>

using namespace std;

class Complex
{
	public:
		int real, img;
		
		Complex(int r, int i)
		{
			real=r;
			img=i;
		}
		
		Complex()
		{
			real=0;
			img=0;
		}
		
		void display()
		{
			if(img<0)
			cout<<real<<" "<<img<<" i \n";
			else
			cout<<real<<" + "<<img<<" i \n";
		}
		
		
	Complex operator+(Complex c)
	{
		
				int r,i;
		r=this->real+c.real;
		i=this->img+c.img;
		
		Complex temp(r,i);
		
		return temp;
   }	
   
   
   	
   
  int operator<(Complex c)
   {
   	 if(this->real<c.real)
   	 return 1;
   	 
   	 return 0;
   }
   
     int operator>(Complex c)
   {
   	 return c<*this;
   }
		
		
		Complex operator-()
		{
			Complex temp(-this->real,-this->img);
			return temp;
		}
		
		
		Complex operator++(int) // post inc
		{
			Complex temp=*this;
			
			real++;
			img++;
			return temp;
		}
		
			Complex operator++() // pre inc
		{
			
			
			real++;
			img++;
			return *this;
		}
		
		Complex operator+=(Complex c)
		{
			*this=*this+c;
			return *this;
		}
		Complex operator*(Complex c)
		{
			Complex temp((real*c.real)-(img*c.img),(real*c.img)+(img*c.real));
			return temp;
		}
};


int main()
{
	Complex c1(3,7), c2(9,-3),c3;
	
     c3=c1+c2;
	
	c3.display();
	return 0;
}
