#include<iostream>
using namespace std;
class Date
{
    int dd,mm,yy;
    char xy;
    int check(int m, int d)
    {
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
        return ch
    }
public:
    Time(int dd, int mm, int yy,char xy='A')
    {
        if(check(m,d))
        {
            this->dd=dd;
            this->mm=mm;
            if(y<0)
            {
                this->xy='B';
            }
        }
        else
        {
            this->dd=1;
            this->mm=1;
            this->yy=1;
        }
    }
    void display()
    {
        cout<<"Date-> "<<dd<<"/"<<mm<<"/"<<yy;
    }
    void dayadd(int a)
    {
        this->dd=this->dd+a;
        switch(m)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: if(d>31)
                     {
                        m++;
                        break;
                     }
            case 4:
            case 6:
            case 9:
            case 11: if(d>30)
                     {
                        m++;
                        break;
                     }
            case 2: if((y%4==0 && d>29) || (y%4!=0 && d>28))
                     {
                        m++    
                        break;
                     }
        }
        if(m>12)
        {
            
        }
    }
};
