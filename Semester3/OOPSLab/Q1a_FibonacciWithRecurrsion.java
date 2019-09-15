//Program to print fibonacci series using recursion
import java.util.Scanner;

class FibonacciWithRecurrsion
{
	static int fibonacci(int n)
	{
		if(n==0)
			return 0;
		else if (n==1)
			return 1;
		else
			return (fibonacci(n-1) + fibonacci(n-2));
	}
	
	public static void main(String [] args)
	{
		int n,i;
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter the series size: ");
		n=scanner.nextInt();
		
		System.out.print("Series: ");
		for(i=0;i<n;i++)
		{
			System.out.print(fibonacci(i) + " ");
		}
		System.out.println("");
		
	}	
}
