//Program to print fibonacci series and its sum using iteration
#include<stdio.h>
int main()
{
  int n,a=0,b=1,c,i,sum=0;
  printf("Enter the no. of elments to be displayed in the series: ");
  scanf("%d",&n);

  printf("Series: ");
  for(i=0; i<n; i++)
  {
    printf("%d  ",a);
    sum+=a;
    c=a+b;
    a=b;
    b=c;
  }
  printf("\nSum = %d\n",sum);
  return 0;
}
