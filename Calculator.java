import java.util.Scanner;

class Calculator
{
	public static void main(String args[])
	{
		float ans,a,b;
		int choice;

		System.out.println("Calculator");
		do
		{
			System.out.print("1. Add \n2. Subtract \n3. Multipliction \n4.Division \nEnter choice: ");
			
			Scanner sc = new Scanner(System.in);
			
			choice = sc.nextInt();
			
			System.out.print("Enter A: ");
			a = sc.nextFloat();
			
			System.out.print("Enter B: ");
			b = sc.nextFloat();
	
			switch(choice)
			{
				case 1: 
					ans = a+b;
					System.out.println("Sum = " + ans);
					break;
				case 2:
					ans = a-b;
					System.out.println("Difference = " + ans);
					break;
				case 3:
					ans = a*b;
					System.out.println("Multiplication = " + ans);
					break;
				case 4:
					ans = a/b;
					System.out.println("Division = " + ans);
					break;
				default:
					System.out.println("Wrong choice");
					break;
			}
		}
		while(choice!=0);
	}
}
