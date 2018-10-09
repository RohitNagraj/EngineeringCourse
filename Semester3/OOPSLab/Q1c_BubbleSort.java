//Program to sort an array using the bubble sort algorithm
import java.util.Scanner;
class BubbleSort
{
	public static void main(String [] args)
	{
		int [] array = new int[10];
		int size,j,i,temp;

		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter the no. of elements to be entered: ");
		size=scanner.nextInt();

		System.out.print("Enter the elements: ");

		for(i=0;i<size; i++)
		{
			array[i] = scanner.nextInt();
		}


		for(i=0;i<size;i++)
		{
			for(j=0;j<size-1;j++)
			{
				if(array[j]>array[j+1])
				{
					temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
			}
		}

		System.out.print("The sorted array is: ");
		for(i=0;i<size;i++)
		{
			System.out.print (array[i] + " ");
		}
		System.out.print("\n");
	}
}
