//Program to implement a stack using an integer array
import java.util.Scanner;
class Stack
{
	int stack[] , top;
	
	Stack()
	{
		top=-1;
		stack = new int[20];
	}
	
	void push(int x)
	{
		if(top==19)
		{
			System.out.println("Stack is full.");
		}
		else
		{
			stack[++top]=x;
			System.out.println("Pushed successfully\n");
		}
	}
	
	int pop()
	{
		if(top==-1)
		{
			System.out.println("Stack is empty\n");
			return 0;
		}
		
		
		else 
			return(stack[top--]);
	}
	
	void display()
	{
		if (top==-1)
		{
			System.out.println("Empty stack\n");
		}
		else
		{
			System.out.print("The stack is: ");
			for(int i=0;i<=top;i++)
			{
				System.out.print(stack[i] + "  ");
			}
			System.out.println("\n");
			
		}
	}
	
	public static void main(String [] args)
	{
		String choice;
		int x;
		Stack s = new Stack();
		Scanner sc =  new Scanner(System.in);
		
		while(true)
		{
			System.out.println("1. Push");
			System.out.println("2. Pop");
			System.out.println("3. Display");
			System.out.println("4. Exit");
			System.out.print("Enter your choice: ");
			
			choice = sc.next();
			
			switch(choice)
			{
				case "1":
					System.out.print("Enter element to push: ");
					x=sc.nextInt();
					s.push(x);
					break;
					
				case "2":
					System.out.print("The popped element is: " + s.pop() + "\n\n");
					break;
					
				case "3": 
					s.display();
					break;
				
				case "4": 	
					System.exit(0);
				
				default:
					System.out.println("Wrong choice");
			}
		}
	}
}
					
