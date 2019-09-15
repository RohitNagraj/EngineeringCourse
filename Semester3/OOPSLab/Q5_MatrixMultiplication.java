import java.util.Scanner;

class Q5_MatrixMultiplication {
	
	public int matA[][], matB[][], matC[][];

	Q5_MatrixMultiplication()
	{
		matA = new int[3][3];
		matB = new int[3][3];
		matC = new int[3][3];
	}

	int[][] getMatrix (int m[][])
	{
		Scanner sc = new Scanner(System.in);
		for(int i = 0;i<3;i++)
		{
			for(int j = 0; j<3;j++)
				m[i][j] = sc.nextInt();
		}
		return m;
	}

	int[][] multiply(int m[][], int n[][], int c[][])
	{
		int i,j,k,sum = 0;

		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				for(k=0;k<3;k++)
				{
					sum += m[i][k] * n[k][j];
				}
				c[i][j] = sum;
				sum = 0;
			}
		}
		return c;
	}
	public static void main(String [] args)
	{
		Q5_MatrixMultiplication matrix = new Q5_MatrixMultiplication();

		System.out.println("Enter the first 3x3 matrix");
		matrix.matA = matrix.getMatrix(matrix.matA);

		System.out.println("Enter the second 3x3 matrix");
		matrix.matB = matrix.getMatrix(matrix.matB);

		matrix.matC = matrix.multiply(matrix.matA, matrix.matB, matrix.matC);
		
		System.out.println("The resultant matrix is:-");
		for(int i = 0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				System.out.print(matrix.matC[i][j] + " ");
			System.out.println();
		}
	}
}