//This code is not the same as the one taught in class. This code actually uses 3 stacks and does all the shifting of numbers.
#include<stdio.h>
#include<conio.h>
#define SIZE 5
 int step=0;

void moveTower(int size, int source[], int destination[], int temp[], int *x,int *y,int *z)
{
  int i;

  if(size==1)
  {
    destination[++(*y)] = source[(*x)];
    source[*x]=0;
    (*x)--;
  }

  else
  {


    moveTower(size-1,source,temp,destination,x,z,y);
    destination[++(*y)] = source[(*x)];
    source[*x]=0;
    (*x)--;

    moveTower(size-1,temp,destination, source,z,y,x);
  }

  step++;

}
int main()
{

  int x=SIZE-1,y=-1,z=-1,i;
  int source[10]={5,4,3,2,1},destination[10]={0},temp[10]={0};

  printf("Initial state\n" );
  for(i=SIZE-1;i>=0;i--)
  {
	printf("%d    %d    %d\n",source[i],destination[i],temp[i]);
  }

  moveTower(SIZE,source,destination,temp,&x,&y,&z);
  printf("\nFinal state\n" );
  for(i=SIZE-1;i>=0;i--)
  {
	printf("%d    %d    %d\n",source[i],destination[i],temp[i]);
  }


  printf("\nSteps = %d\n",step);

  return 0;
}
