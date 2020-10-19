import java.util.*;
class palindrome 
{
  public static void main(String[] args) 
  {
    Scanner sc= new Scanner(System.in);
    System.out.println("Enter a number");
    int num=sc.nextInt();
    int temp,rev;
    temp=num;
    rev=0;
    while(temp!=0)
    {    
      int digit=temp%10;
      rev=rev*10+digit;
      temp=temp/10;
    }
    if(num==rev)
    {System.out.println("Palindrome");}
    else
    {System.out.println("Not a Palindrome");}
  }
}
