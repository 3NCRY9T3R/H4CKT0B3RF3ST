import java.util.*;
class LeakyBucket
{
    public static void main(String args[]) throws InterruptedException
    {
        int n,incoming,outgoing,store=0,bucketSize;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number of inputs : ");
        n=sc.nextInt();
        System.out.print("Enter the incoming rate : ");
        incoming=sc.nextInt();
        System.out.print("Enter the outgoing rate : ");
        outgoing=sc.nextInt();
        System.out.print("Enter the size of the bucket : ");
        bucketSize=sc.nextInt();
        while(n!=0)
        {
            if(incoming<=(bucketSize-store))
            {
                store+=incoming;
                System.out.println("Bucket buffer size is "+store+" out of "+bucketSize);
            }
            else
            {
                System.out.println("Packet loss = "+(incoming-(bucketSize-store)));
                System.out.println("Bucket buffer size is "+store+" out of "+bucketSize);
            }
            store-=outgoing;
            System.out.println("After outgoing: "+store+" packets left out of "+bucketSize);
            n--;
            System.out.println();
            Thread.sleep(3000);
        }
        sc.close();
    }
}
