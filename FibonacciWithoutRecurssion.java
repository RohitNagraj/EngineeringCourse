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
		
		while(a<limit)
		{
			System.out.print(a + " : ");
			c=a+b;
			a=b;
			b=c;
		}
		System.out.print("\n");
	}
}
		
