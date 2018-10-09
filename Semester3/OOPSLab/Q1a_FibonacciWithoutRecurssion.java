//Program to print the fibonacci series till a given limit
import java.util.Scanner;
class FibonacciWithoutRecurssion
{
	public static void main(String [] args)
	{
		int a=0,b=1,c;

		System.out.print("Enter the limit of the series: ");
		int limit;
		Scanner scanner = new Scanner(System.in);
		limit= scanner.nextInt();
		System.out.print("Series: ");

		while(a<limit)
		{
			System.out.print(a + " ");
			c=a+b;
			a=b;
			b=c;
		}
		System.out.print("\n");
	}
}
