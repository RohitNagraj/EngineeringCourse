#include<stdio.h>
int main()
{
  int n,a=0,b=1,c,i,sum=0;
  printf("Enter the no. of elments displayed in the series: ");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    printf("%d  ",a);
    sum+=a;
    c=a+b;
    a=b;
    b=c;
  }
  printf("\nSum = %d\n",sum );
}
