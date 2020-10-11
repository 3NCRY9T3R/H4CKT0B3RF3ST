#include<iostream>
using namespace std;
class InvalidDate
{

};
class Date
{
    int dd,mm,yy;
    char xy;
    int check(int m, int d,int y)
    {	
    	int ch;
		if(y<0)
    	{
    		return 0;
		}
        switch(m)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: if(d<=31)
                     {
                            ch=1;
                            break;
                     }
                     else
                     {
                         ch=0;
                         break;
                     }

            case 4:
            case 6:
            case 9:
            case 11: if(d<=30)
                     {
                            ch=1;
                            break;
                     }
                     else
                     {
                         ch=0;
                         break;
                     }
            case 2: if((y%4==0 && d<=29) || (y%4!=0 && d<=28))
                     {
                            ch=1;
                            break;
                     }
                     else
                     {
                         ch=0;
                         break;
                     }
                     
            default :ch=0;
                     break;
        }
        return ch;
    }
public:
    Date(int dd, int mm, int yy,char xy='A')
    {
        if(check(mm,dd,yy))
        {
            this->dd=dd;
            this->mm=mm;
            this->yy=mm;
        }
        else
        {
        	InvalidDate d;
            throw  d;
        }
    }
    void display()
    {
        cout<<"Date-> "<<dd<<"/"<<mm<<"/"<<yy;
    }
};
int main()
{
    try
    {
        Date d1(1,21,21);
    }
    catch(InvalidDate a)
    {
        cout<<" Invalid date";
    }
}
