import java.util.*;

class GoBackN
{
	int n, front, rear;
	char ch;
	Scanner s = new Scanner(System.in);
	
	void input()
	{
		System.out.println("Please enter the window size");
		n = s.nextInt();
		n = (int)Math.pow(2, n);
		
		front = 0;
		rear = n-1;
	}
	
	void slidewindow()
	{
		if(front == n-1)
			front = 0;
		else
			front++;
			
		if(rear == n-1)
			rear = 0;
		else
			rear++;
			
		receive();
	}
	
	void sender()
	{
			if(rear > front)
			{
				for(int i=front; i<=rear; i++)
					System.out.println("Frame " + i + " transmitted.");
			}
			else if(front > rear)
			{
				for(int i = front; i<=n-1; i++)
					System.out.println("Frame " + i + " transmitted.");
				for(int i = 0; i<=rear; i++)
					System.out.println("Frame " + i + " transmitted.");
			}
			receive();
	}
	
	void receive()
	{
		int c = 1;
		if(rear > front)
		{
			for(int i=front; i<=rear; i++)
			{
				System.out.print("\nFrame " + i + " received. (y/n)");
				ch = s.next().charAt(0);
				if(ch == 'y')
					slidewindow();
				else
					break;
			}
			sender();
		}
		else
		{
			for(int i=front; i<=n-1; i++)
			{
				System.out.print("\nFrame " + i + " received. (y/n)");
				ch = s.next().charAt(0);
				if(ch == 'y')
					slidewindow();
				else
				{
					c = 0;
					break;
				}
			}
			if(c == 1)
			{
				for(int i=0; i<=rear; i++)
				{
					System.out.print("\nFrame " + i + " received. (y/n)");
					ch = s.next().charAt(0);
					if(ch == 'y')
						slidewindow();
					else
						break;
				}
			}
			sender();
		}
	}
	
	public static void main(String args[])
	{
		GoBackN g = new GoBackN();
		g.input();
		g.sender();
		g.receive();
	}
}
