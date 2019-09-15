//Program to check if the entered number is prime or not
import java.util.Scanner;

class PrimeNumberCheck
{
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter the no. to be check for prime: ");
		int x= scanner.nextInt();

		boolean isPrime=true;

		for(int i=2;i<=x/2;i++)
		{
			if(x%i==0)
			{
				isPrime=false;
				break;
			}
		}

		if(isPrime)
			System.out.println("It is a prime number\n");

		else
			System.out.println("It is not a prime number\n");
	}
}
