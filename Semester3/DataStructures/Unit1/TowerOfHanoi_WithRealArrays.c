//WARNING : This code is not in the syllabus. This code uses 3 stacks and does all the shifting of numbers.

/*
Explaination: Assume we have n disks in the source, the basic idea of the algorithm is, move n-1 disks to temp,
move the last remaining one to destination, move all n-1 disks from temp to destination.
Base condition: If theres only one disk to be moved, move it from source to destination
Recurssion: if there is more than 1 disk, move all the n-1 to temp, move nth disk to destination, move n-1 from
temp to destination.
*/


#include<stdio.h>
#include<conio.h>
#define SIZE 5
int step=0;

void moveTower(int size, int source[], int destination[], int temp[], int *x,int *y,int *z)
// x,y,z are the top pointers for source, destination and temp. They are passed by reference so that
// any changes made to them are reflected everywhere and they can be passed in different order for the Recurssion call.
{
  if(size==1) //Base condition
  {
    destination[++(*y)] = source[(*x)]; //Move from source to destination
    source[*x]=0;
    (*x)--;
  }

  else
  {


    moveTower(size-1,source,temp,destination,x,z,y); //Move from source to temp

    destination[++(*y)] = source[(*x)]; //Move nth number from source to destination
    source[*x]=0;
    (*x)--;

    moveTower(size-1,temp,destination, source,z,y,x); //Move n-1 disks from temp to destination
  }

  step++;

}
int main()
{

  int x=SIZE-1,y=-1,z=-1,i;
  int source[10]={5,4,3,2,1},destination[10]={0},temp[10]={0}; //Initialize array here.

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
