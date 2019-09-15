//Program to print fibonacci series and its sum using recursion.
#include<stdio.h>

int fibonacci(int n)
{
  if(n==0)
    return 0;
  else if(n==1)
    return 1;
  else
  return (fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
  int sum=0,i,n,a;
  printf("Enter the no. of elments displayed in the series: ");
  scanf("%d",&n);

  printf("Series: ");
  for(i=0;i<n;i++)
  {
    a=fibonacci(i);
    sum+=a;
    printf("%d ",a );
  }
  printf("\nSum = %d\n",sum );

  return 0;
}
