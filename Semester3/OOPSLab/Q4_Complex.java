import java.util.Scanner;
class Q4_Complex
{
	int real,imaginary;
	
	void set()
	{	
		Scanner sc = new Scanner(System.in);
		System.out.print ("Enter the real part of complex number: ");
		real= sc.nextInt();
		System.out.print ("Enter the imaginary part of the complex number: ");
		imaginary = sc.nextInt();
	}
	
	Q4_Complex()
	{
		real=0;
		imaginary=0;
	}
	
	void add (Q4_Complex A)
	{
		this.real = A.real + this.real;
		this.imaginary = A.imaginary + this.imaginary;
		System.out.println("The result is: " + this.real + " + " + this.imaginary + "i");
	}
	
	void subtract (Q4_Complex A)
	{
		this.real = A.real - this.real;
		this.imaginary = A.imaginary - this.imaginary;
		System.out.println("The result is: " + this.real + " + " + this.imaginary + "i");
	}
	
	void multiply (Q4_Complex A)
	{
		int temp = this.real;
		this.real = A.real*this.real - A.imaginary*this.imaginary;
		this.imaginary = A.real*this.imaginary + A.imaginary*temp;
		System.out.println("The result is: " + this.real + " + " + this.imaginary + "i");
	}
	
	public static void main(String [] args)
	{
		int tempReal, tempImaginary;
		int choice;
		Scanner sc = new Scanner(System.in);
		Q4_Complex A = new Q4_Complex();
		Q4_Complex B = new Q4_Complex();
		
		while(true)
		{
		
			System.out.println ("\n\n\n-------------Complex Number Operations-------------");
			System.out.println ("1. Addition");
			System.out.println ("2. Subtraction");
			System.out.println ("3. Multiply");
			System.out.println ("4. Exit");
			System.out.print ("Enter your choice: ");

			choice = sc.nextInt();
			
			switch (choice)
			{
				
				case 1:
					A.set();
					B.set();
					A.add(B);
					break;
					
				case 2:
					A.set();
					B.set();
					A.subtract(B);
					break;
					
				case 3:
					A.set();
					B.set();
					A.multiply(B);
					break;
					
				case 4:
					System.exit(0);
				default:
					System.out.print ("Wrong choice\n\n\n");
			}
		}
	}
}

